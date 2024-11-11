#include <bits/stdc++.h>
using namespace std;
double dp[110][110][110];
double f(int r, int p, int s) {
  if (r > 0 && s <= 0 && p <= 0) return 1;
  if (r <= 0) return 0;
  if (dp[r][p][s] != -1) return dp[r][p][s];
  double all = r * p + p * s + s * r;
  double ans = 0.;
  if (r && p) ans += r * p * 1.0 * f(r - 1, p, s) / all;
  if (p && s) ans += p * 1.0 * s * f(r, p - 1, s) / all;
  if (r && s) ans += 1.0 * r * s * f(r, p, s - 1) / all;
  return dp[r][p][s] = ans;
}
void mset() {
  for (int i = 0; i < 110; i++)
    for (int j = 0; j < 110; j++)
      for (int k = 0; k < 110; k++) dp[i][j][k] = -1;
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(12);
  mset();
  f(101, 101, 101);
  cout << f(a, c, b) << ' ';
  cout << f(b, a, c) << ' ';
  cout << f(c, b, a) << '\n';
}
