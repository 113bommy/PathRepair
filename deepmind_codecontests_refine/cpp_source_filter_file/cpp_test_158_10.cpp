#include <bits/stdc++.h>
using namespace std;
long long mod = (1 ? 1e9 + 7 : 998244353);
const int N = 5e5 + 5;
void Evlos() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  long long sol = 0;
  vector<int> out(m);
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<int> koef(m);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if ((1 << i) & mask) {
        for (int j = 0; j < m; j++) koef[j] += a[i][j];
        ans -= x[i];
      } else {
        for (int j = 0; j < m; j++) koef[j] -= a[i][j];
        ans += x[i];
      }
    }
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int i, int j) { return koef[i] < koef[j]; });
    vector<int> can(m);
    for (int i = 0; i < m; i++) {
      can[order[i]] = i + 1;
      ans += koef[order[i]] * (i + 1);
    }
    if (ans > sol) {
      sol = ans;
      out = can;
    }
  }
  for (int i = 0; i < m; i++) cout << out[i] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) Evlos();
  return 0;
}
