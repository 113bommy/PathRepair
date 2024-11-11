#include <bits/stdc++.h>
using namespace std;
int N, Q, K, C, D, A[100005], B[100005], Df[100005], Db[100005], st[100005],
    In[100005], Ot[100005], val[100005], Siz[100005], Max[100005];
struct Lin {
  int v, next;
} E[100005 * 2];
map<int, int> H1, H2;
bool V[100005];
void Link(int u, int v) {
  E[++D] = (Lin){v, st[u]};
  st[u] = D;
  E[++D] = (Lin){u, st[v]};
  st[v] = D;
}
int Pow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = 1ll * a * a % Q)
    if (b & 1) ret = 1ll * ret * a % Q;
  return ret;
}
void Pre(int u, int f) {
  Siz[u] = 1;
  Max[u] = 0;
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) != f && !V[v])
      Pre(v, u), Siz[u] += Siz[v], Max[u] = max(Max[u], Siz[v]);
}
int Find(int u, int f, int S) {
  Max[u] = max(Max[u], S - Siz[u]);
  int rt = u;
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) != f && !V[v]) {
      int t = Find(v, u, S);
      if (Max[t] < Max[rt]) rt = t;
    }
  return rt;
}
void DFS(int u, int f, int dep) {
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) != f && !V[v]) {
      Df[v] = (1ll * Df[u] * K + val[v]) % Q;
      Db[v] = (1ll * val[v] * A[dep] + Db[u]) % Q;
      DFS(v, u, dep + 1);
    }
}
void INS(int u, int f, int dep) {
  int x = 1ll * (C - Df[u] + Q) * B[dep] % Q;
  H1[x]++;
  H2[Db[u]]++;
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) != f && !V[v]) INS(v, u, dep + 1);
}
void Upd(int u, int f, int dep, int t) {
  int x = 1ll * (C - Df[u] + Q) * B[dep] % Q;
  In[u] += t * H2[x];
  Ot[u] += t * H1[Db[u]];
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) != f && !V[v]) Upd(v, u, dep + 1, t);
}
void Work(int u) {
  Pre(u, 0);
  u = Find(u, 0, Siz[u]);
  V[u] = 1;
  Df[u] = 0;
  Db[u] = val[u];
  H1.clear();
  H2.clear();
  DFS(u, 0, 1);
  INS(u, 0, 0);
  Upd(u, 0, 0, 1);
  for (int i = st[u], v; i; i = E[i].next)
    if (!V[v = E[i].v]) {
      H1.clear();
      H2.clear();
      INS(v, u, 1);
      Upd(v, u, 1, -1);
    }
  for (int i = st[u], v; i; i = E[i].next)
    if (!V[v = E[i].v]) Work(v);
}
int main() {
  scanf("%d%d%d%d", &N, &Q, &K, &C);
  A[0] = B[0] = 1;
  for (int i = 1; i <= N; i++)
    scanf("%d", &val[i]), A[i] = 1ll * A[i - 1] * K % Q,
                          B[i] = Pow(A[i], Q - 2);
  for (int i = 2; i <= N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Link(u, v);
  }
  Work(1);
  long long Ans = 0, Sum = 0;
  for (int i = 1; i <= N; i++) {
    long long x0 = N - In[i], x1 = In[i], y0 = N - Ot[i], y1 = Ot[i];
    Ans += x0 * x0 + y0 * y0 + x0 * y0 + x1 * x1 + y1 * y1 + x1 * y1;
    Sum += x0 * x1 * 2 + y0 * y1 * 2 + x0 * y1 + x1 * y0;
  }
  printf("%d\n", (Ans - Sum / 2) / 3);
}
