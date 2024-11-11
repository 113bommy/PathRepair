#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int Abs(int a) { return a > 0 ? a : -a; }
int X[MAXN], Y[MAXN], CX[MAXN], CY[MAXN], R[MAXN];
bitset<MAXN> Bt[MAXN];
int n, m, k;
bool Test(int i, int j) {
  return 1ll * R[j] * R[j] >= 1ll * (CX[j] - X[i]) * (CX[j] - X[i]) +
                                  1ll * (CY[j] - Y[i]) * (CY[j] - Y[i]);
}
void init() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &X[i], &Y[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &R[i], &CX[i], &CY[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (Test(i, j)) {
        Bt[i].set(j);
      }
    }
  }
}
void solve() {
  bitset<MAXN> T;
  while (k--) {
    int a, b;
    scanf("%d%d", &a, &b);
    T = Bt[a] & Bt[b];
    printf("%d\n", Bt[a].count() + Bt[b].count() - T.count());
  }
}
int main() {
  init();
  solve();
  return 0;
}
