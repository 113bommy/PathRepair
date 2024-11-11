#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 3e5 + 100;
void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  vector<int> v;
  int free = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != c)
      v.push_back(i + 1);
    else
      free = i + 1;
  }
  if ((int)v.size() == 0) {
    cout << 0 << '\n';
    return;
  }
  if (free > n / 2) {
    cout << 1 << '\n';
    cout << free << '\n';
    return;
  }
  cout << 2 << '\n';
  cout << n << ' ' << n - 1 << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
