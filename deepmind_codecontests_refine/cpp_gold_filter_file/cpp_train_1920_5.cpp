#include <bits/stdc++.h>
using namespace std;
int IN() {
  int x = 0, ch;
  for (; (ch = getchar()) < '0' || ch > '9';)
    ;
  for (; ch >= '0' && ch <= '9'; (ch = getchar())) (x *= 10) += ch - '0';
  return x;
}
int N, Q, D, st[100005], Dep[100005], F[20][100005];
int M, C, L[100005], R[100005], Ans[100005], Max[100005 << 2], Laz[100005 << 2];
struct Lin {
  int v, next;
} E[100005 * 2];
struct Nod {
  int ID, x, k;
};
vector<Nod> A[100005];
void Link(int u, int v) {
  E[++D] = (Lin){v, st[u]};
  st[u] = D;
  E[++D] = (Lin){u, st[v]};
  st[v] = D;
}
void DFS(int u, int f) {
  Dep[u] = Dep[F[0][u] = f] + 1;
  L[u] = ++C;
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) ^ f) DFS(v, u);
  R[u] = C;
}
int LCA(int u, int v) {
  if (Dep[u] > Dep[v]) swap(u, v);
  for (int i = 16; i >= 0; i--)
    if (Dep[F[i][v]] >= Dep[u]) v = F[i][v];
  if (u == v) return u;
  for (int i = 16; i >= 0; i--)
    if (F[i][u] != F[i][v]) u = F[i][u], v = F[i][v];
  return F[0][u];
}
int Find(int x, int d) {
  for (int i = 16; i >= 0; i--)
    if ((1 << i) & d) x = F[i][x];
  return x;
}
void Upd(int x, int d) {
  Max[x] += d;
  Laz[x] += d;
}
void Up(int x) {
  for (x >>= 1; x; x >>= 1)
    Max[x] =
        ((Max[x << 1]) > (Max[x << 1 | 1]) ? (Max[x << 1]) : (Max[x << 1 | 1]));
}
void Dn(int x) {
  for (int s = 1, d = M >> 1; d; (s <<= 1) |= (d & x) > 0, d >>= 1)
    if (Laz[s]) Upd(s << 1, Laz[s]), Upd(s << 1 | 1, Laz[s]), Laz[s] = 0;
}
int Query(int l, int r) {
  int ret = 0;
  Dn(l + M);
  Dn(r + M);
  for (l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (l & 1 ^ 1) ret = ((ret) > (Max[l ^ 1]) ? (ret) : (Max[l ^ 1]));
    if (r & 1) ret = ((ret) > (Max[r ^ 1]) ? (ret) : (Max[r ^ 1]));
  }
  return ret;
}
void Modify(int x, int y, int d) {
  Dn(x + M - 1);
  Dn(y + M + 1);
  for (int l = x + M - 1, r = y + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (l & 1 ^ 1) Upd(l ^ 1, d);
    if (r & 1) Upd(r ^ 1, d);
  }
  Up(x + M - 1);
  Up(y + M + 1);
}
void Work(int u, int f) {
  Modify(L[u], R[u], -1);
  if (1 < L[u]) Modify(1, L[u] - 1, 1);
  if (R[u] < N) Modify(R[u] + 1, N, 1);
  int S = A[u].size();
  for (int i = 0; i <= S - 1; i++) {
    int ret = 0, k = A[u][i].ID, x = A[u][i].x, t;
    if (A[u][i].k)
      ret = Query(L[x], R[x]);
    else {
      if (1 < L[x]) t = Query(1, L[x] - 1), ret = ((ret) > (t) ? (ret) : (t));
      if (R[x] < N) t = Query(R[x] + 1, N), ret = ((ret) > (t) ? (ret) : (t));
    }
    Ans[k] = ((Ans[k]) > (ret) ? (Ans[k]) : (ret));
  }
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) ^ f) Work(v, u);
  Modify(L[u], R[u], 1);
  if (1 < L[u]) Modify(1, L[u] - 1, -1);
  if (R[u] < N) Modify(R[u] + 1, N, -1);
}
int main() {
  N = IN();
  for (int i = 2; i <= N; i++) Link(IN(), IN());
  DFS(1, 0);
  Q = IN();
  for (int i = 1; i <= 16; i++)
    for (int j = 1; j <= N; j++) F[i][j] = F[i - 1][F[i - 1][j]];
  for (M = 1; M <= N + 1; M <<= 1)
    ;
  for (int i = 1; i <= N; i++) Max[M + L[i]] = Dep[i];
  for (int i = M; i >= 1; i--)
    Max[i] =
        ((Max[i << 1]) > (Max[i << 1 | 1]) ? (Max[i << 1]) : (Max[i << 1 | 1]));
  for (int i = 1; i <= Q; i++) {
    int u = IN(), v = IN(), w = LCA(u, v);
    if (Dep[u] > Dep[v]) swap(u, v);
    int d = Dep[u] + Dep[v] - 2 * Dep[w], x = Find(v, (d - 1) / 2);
    A[u].push_back((Nod){i, x, 0});
    A[v].push_back((Nod){i, x, 1});
  }
  Work(1, 0);
  for (int i = 1; i <= Q; i++) printf("%d\n", Ans[i]);
}
