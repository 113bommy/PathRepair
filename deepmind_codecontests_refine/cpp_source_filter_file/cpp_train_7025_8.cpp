#include <bits/stdc++.h>
using namespace std;
int IN() {
  int x = 0, ch;
  for (; (ch = getchar()) < '0' || ch > '9';)
    ;
  for (; ch >= '0' && ch <= '9'; (ch = getchar())) (x *= 10) += ch - '0';
  return x;
}
int N, Q, C, D, T, L[800005], R[800005], st[800005], Len[800005], Now[800005],
    Ans[800005], Pos[800005];
char s[800005];
bool V[800005];
struct Lin {
  int v, next;
} E[800005];
struct Opt {
  int k, t, ID;
};
vector<Opt> G[800005];
void Link(int u, int v) {
  E[++D] = (Lin){v, st[u]};
  st[u] = D;
}
void DFS(int u) {
  L[u] = ++C;
  for (int i = st[u]; i; i = E[i].next) DFS(E[i].v);
  R[u] = C;
}
struct SAM {
  int T, D, F[800005], Max[800005], A[800005][26];
  SAM() { T = D = 1; }
  void Add(int x) {
    if (A[D][x] && Max[A[D][x]] == Max[D] + 1) {
      D = A[D][x];
      return;
    }
    int np = ++T, p = D, q, nq;
    Max[np] = Max[p] + 1;
    for (; p && !A[p][x]; p = F[p]) A[p][x] = np;
    if (!p)
      F[np] = 1;
    else if (Max[q = A[p][x]] == Max[p] + 1)
      F[np] = q;
    else {
      Max[nq = ++T] = Max[p] + 1;
      F[nq] = F[q];
      for (int i = 0; i <= 26; i++) A[nq][i] = A[q][i];
      F[np] = F[q] = nq;
      for (; p && A[p][x] == q; p = F[p]) A[p][x] = nq;
    }
    D = np;
  }
  void Pre(int u) {
    if (F[u]) Link(F[u], u);
    V[u] = 1;
    for (int i = 0; i <= 26; i++)
      if (A[u][i] && !V[A[u][i]]) Pre(A[u][i]);
  }
} S;
struct Bit {
  int F[800005];
  void Add(int x) {
    for (; x <= C; x += x & -x) F[x]++;
  }
  int Ask(int x) {
    int ret = 0;
    for (; x; x -= x & -x) ret += F[x];
    return ret;
  }
} B;
int main() {
  N = IN();
  Q = IN();
  for (int i = 1; i <= N; i++) {
    scanf("%s", s + T);
    S.D = 1;
    for (; s[T]; T++, Len[i]++) S.Add(s[T] - 'a');
  }
  S.Pre(1);
  DFS(1);
  for (int i = 1, k = 0, x = 1; i <= N; i++, x = 1) {
    for (int j = k; j <= k + Len[i] - 1; j++)
      x = S.A[x][s[j] - 'a'], Pos[j] = x;
    Now[i] = x;
    k += Len[i];
  }
  for (int i = 1; i <= Q; i++) {
    int l = IN(), r = IN(), k = IN();
    G[l - 1].push_back((Opt){Now[k], -1, i});
    G[r].push_back((Opt){Now[k], 1, i});
  }
  for (int i = 1, k = 0; i <= N; i++) {
    for (int j = k; j <= k + Len[i] - 1; j++) B.Add(L[Pos[j]]);
    k += Len[i];
    for (int j = 0; j < G[i].size(); j++)
      Ans[G[i][j].ID] +=
          G[i][j].t * (B.Ask(R[G[i][j].k]) - B.Ask(L[G[i][j].k] - 1));
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", Ans[i]);
}
