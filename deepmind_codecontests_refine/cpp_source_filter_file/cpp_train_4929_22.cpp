#include <bits/stdc++.h>
const double eps = (1e-5);
using namespace std;
int dcmp(double a, double b) {
  return fabs(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
long long getBit(long long num, int idx) { return ((num >> idx) & 1ll) == 1; }
int setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
void M() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int countNumBit1(int mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1);
    ++ret;
  }
  return ret;
}
const int MAX = 66;
const int inf = 1e9;
int cost[MAX][MAX][MAX], ans[MAX][MAX][MAX], n, m, r;
int main() {
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans[0][i][j] = 11;
  for (int i = 1; i <= m; ++i) {
    auto& mat = cost[i];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) scanf("%d", &mat[i][j]);
    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
          mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) ans[0][i][j] = min(ans[0][i][j], mat[i][j]);
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        ans[k][i][j] = ans[k - 1][i][j];
        for (int c = 1; c <= n; ++c)
          ans[k][i][j] = min(ans[k][i][j], ans[k - 1][i][c] + ans[0][c][j]);
      }
    }
  }
  while (r--) {
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    printf("%d\n", ans[min(k, n)][s][t]);
  }
  return 0;
}
