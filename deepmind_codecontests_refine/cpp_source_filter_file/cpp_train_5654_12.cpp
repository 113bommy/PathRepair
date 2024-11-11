#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll inf = 2e18;
const int mod = 1e9 + 7;
const ld eps = 1e-9;
const ld pi = 3.14159265358979323846;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(12);
  cout << fixed;
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p(b + 1, 1);
  for (int i = 1; i <= b; ++i) p[i] = 2 * p[i - 1];
  vector<int> ans = {1};
  for (int i = 1; i <= b; ++i) ans.push_back(p[i]);
  if (!b) ans.push_back(1);
  for (int i = 1; i <= a; ++i) ans.push_back(ans.back() + 1);
  for (int i = ans.size(); i < n; ++i) ans.push_back(1);
  if (ans.size() > n) {
    cout << -1;
    return 0;
  }
  for (auto i : ans) cout << i << " ";
  return 0;
}
