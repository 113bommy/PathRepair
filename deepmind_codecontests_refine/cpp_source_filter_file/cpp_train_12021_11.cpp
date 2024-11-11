#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int MAXN = 1010;
int a[MAXN], b[MAXN], par[MAXN], n, l;
double dp[MAXN];
bool check(double x) {
  dp[0] = 0.f;
  par[0] = -1;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1e9;
    par[i] = -1;
    for (int j = 0; j < i; j++) {
      double cur = dp[j] + sqrt((double)abs(a[i] - a[j] - l)) - x * b[i];
      if (cur < dp[i]) dp[i] = cur, par[i] = j;
    }
  }
  return dp[n] < 0.f;
}
void print(int x) {
  if (x < 1) return;
  print(par[x]);
  cout << " " << x;
}
int main() {
  cin >> n >> l;
  a[0] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  double lo = 0.f, hi = 1e9;
  for (int o = 0; o < 50; o++) {
    double mid = (lo + hi) * .5f;
    if (check(mid))
      hi = mid;
    else
      lo = mid;
  }
  check(lo);
  print(n);
  cout << endl;
  return 0;
}
