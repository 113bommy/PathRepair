#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
const double PI = acos(-1);
const double eps = (1e-9);
const long long int inf = 2e10;
const int M = (1e9) + 7;
const int N = (2e5) + 3;
double sum[N], rev[N], val[N];
double dp[51][N];
double cost(int i, int j) {
  return val[j] - val[i] - (sum[i] * (rev[j] - rev[i]));
}
void compute(int k, int l, int h, int a, int b) {
  if (l > h) return;
  int ind = -1, j, m = ((l + h) >> 1);
  double temp, max_val = inf;
  for (j = a; j < min(b + 1, m); ++j) {
    temp = dp[k - 1][j] + cost(j, m);
    if (temp <= max_val) max_val = temp, ind = j;
  }
  dp[k][m] = max_val;
  compute(k, l, m - 1, a, ind);
  compute(k, m + 1, h, ind, b);
}
void solve() {
  int n, m, i, k;
  scanf("%d%d", &n, &m);
  cout << setprecision(10) << fixed;
  double temp;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &k);
    temp = k;
    sum[i] = sum[i - 1] + temp;
    val[i] = val[i - 1] + (sum[i] / temp);
    rev[i] = rev[i - 1] + (1 / temp);
    dp[1][i] = val[i];
  }
  for (k = 2; k < m + 1; ++k) compute(k, k, n, k - 1, n);
  cout << dp[m][n] << "\n";
}
int main() {
  int t = 1;
  while (t--) solve();
}
