#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
double d[maxn][maxn];
double dfs(int n, int m) {
  if (d[n][m] != 0.0) return d[n][m];
  if (!m) return 1.0;
  if (!n) return 1.0 / (m + 1);
  double k1 = 1.0 * m / (m + 1) * (1.0 - dfs(m - 1, n)) - 1.0;
  double b1 = 1.0;
  double k2 = 1.0 * m / (m + 1) + 1.0 * m / (m + 1) * (1.0 - dfs(m - 1, n)) +
              dfs(m, n - 1) - 1.0;
  double b2 = 1.0 - dfs(m, n - 1);
  return d[n][m] = k1 * (b2 - b1) / (k1 - k2) + b1;
}
int main() {
  int n, m;
  cin >> n >> m;
  printf("%.10f %.10f\n", dfs(n, m), 1.0 - dfs(n, m));
}
