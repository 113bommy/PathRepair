#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string st;
  cin >> st;
  map<char, int> m;
  for (int i = 0; i < n; i++) {
    m[st[i] - 'A']++;
  }
  set<int> s;
  for (auto x : m) {
    s.insert(x.second);
  }
  int mx = *s.rbegin();
  int cnt = 0;
  for (auto x : m) {
    if (x.second == mx) cnt++;
  }
  long long res = 1;
  for (int i = 0; i < n; i++) {
    res *= cnt;
    res %= 1000000007;
  }
  cout << res;
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
