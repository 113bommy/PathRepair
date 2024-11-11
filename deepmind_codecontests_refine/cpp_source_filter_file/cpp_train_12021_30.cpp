#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 1000 + 5;
int n, l, k, x[N], y[N], road[N];
double dp[N];
bool isc[N];
vector<int> ans;
double f(int i) {
  double &r = dp[i];
  if (isc[i]) return r;
  isc[i] = 1;
  r = inf;
  double ans;
  for (int j = 0; j <= i - 1; j++) {
    ans = f(j) + sqrt(abs(x[i] - x[j] - l)) - y[i] * k;
    if (ans < r) {
      r = ans;
      road[i] = j;
    }
  }
  return r;
}
bool solve(double val) {
  k = val;
  memset(isc, 0, sizeof(isc));
  isc[0] = 1;
  return f(n) <= 0;
}
int main() {
  ios ::sync_with_stdio(0);
  cin >> n >> l;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  double b = 0, e = 1e6;
  for (int i = 1; i <= 50; i++) {
    double o = (b + e) / 2;
    if (solve(o))
      e = o;
    else
      b = o;
  }
  while (n) {
    ans.push_back(n);
    n = road[n];
  }
  reverse(ans.begin(), ans.end());
  for (__typeof(ans.begin()) it = ans.begin(); it != ans.end(); it++)
    cout << *it << ' ';
  cout << '\n';
  return 0;
}
