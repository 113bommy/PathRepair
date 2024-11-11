#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
void solve(vector<int> &v, int x, bool had) {
  sort(v.begin(), v.end());
  int len = v.size();
  if (v[len / 2] == x) {
    cout << !had << "\n";
    return;
  }
  int l = lower_bound(v.begin(), v.end(), x) - v.begin();
  int r = upper_bound(v.begin(), v.end(), x) - 1 - v.begin();
  int g1, g2;
  int ops;
  g1 = l;
  g2 = len - l - 1;
  if (g1 > g2) {
    ops = (g1 - g2);
  } else {
    assert(g1 < g2);
    ops = (g2 - g1 - 1);
  }
  g1 = r;
  g2 = len - r - 1;
  if (g1 > g2) {
    ops = min(ops, g1 - g2);
  } else {
    assert(g1 < g2);
    ops = min(ops, g2 - g1 - 1);
  }
  cout << (ops + !had) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  bool has_x = false;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] == x) {
      has_x = 1;
    }
  }
  if (!has_x) {
    v.emplace_back(x);
  }
  solve(v, x, has_x);
  return 0;
}
