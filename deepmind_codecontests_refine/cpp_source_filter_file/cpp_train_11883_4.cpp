#include <bits/stdc++.h>
using namespace std;
const int MX = 320000;
int N;
long long A[MX];
struct Edge {
  int y, nx;
} E[MX << 1];
int H[MX], ec;
void AddE(int x, int y) { E[++ec].y = y, E[ec].nx = H[x], H[x] = ec; }
int F[MX], son[MX], U[MX], V[MX], B[MX];
long long W[MX];
void dfs1(int x, int f) {
  F[x] = f, W[x] = A[x];
  int mx = -1;
  for (int i = H[x]; i; i = E[i].nx)
    if (E[i].y != f) {
      dfs1(E[i].y, x);
      if (W[E[i].y] > mx) son[x] = E[i].y, mx = W[E[i].y];
    }
  if (son[x]) W[x] = min(W[x], W[son[x]]);
}
void dfs2(int x, int u) {
  U[x] = u;
  if (son[x]) dfs2(son[x], u);
  for (int i = H[x]; i; i = E[i].nx)
    if (E[i].y != F[x] && E[i].y != son[x]) dfs2(E[i].y, E[i].y);
}
void dfs3(int x, int v) {
  V[x] = v;
  int cnt = 0;
  for (int i = H[x]; i; i = E[i].nx)
    if (E[i].y != F[E[i].y] && W[E[i].y] == W[son[x]]) ++cnt;
  if (cnt == 1) dfs3(son[x], v);
  for (int i = H[x]; i; i = E[i].nx)
    if (E[i].y != F[x] && (cnt > 1 || E[i].y != son[x])) dfs3(E[i].y, E[i].y);
}
int main() {
  scanf("%d", &N);
  for (int i = (1); i <= (N); ++i) scanf("%lld", A + i);
  for (int i = (1); i < (N); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    AddE(x, y), AddE(y, x);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  dfs3(1, 1);
  long long ans = 0, cnt = 0;
  for (int i = (1); i <= (N); ++i) {
    if (U[i] == i) ans += W[i];
    if (W[V[i]] == A[i]) ++cnt;
  }
  printf("%lld %lld\n", ans, cnt);
  for (int i = (1); i <= (N); ++i)
    if (W[V[i]] == A[i]) printf("%d ", i);
  putchar('\n');
  return 0;
}
