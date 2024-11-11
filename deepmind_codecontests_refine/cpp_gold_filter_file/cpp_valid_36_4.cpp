#include <bits/stdc++.h>
using namespace std;
int n;
int binpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res *= x;
    x *= x;
    y >>= 1;
  }
  return res;
}
void solve() {
  cin >> n;
  string s(n, 'a');
  if (n % 2 == 0) {
    s[n / 2 - 1] = 'b';
  } else {
    s[n / 2] = 'b';
    s[0] = 'c';
  }
  cout << s << "\n";
  return;
  for (int mask = 0; mask < binpow(3, n); mask++) {
    string s;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
      int val = mask / binpow(3, i) % 3;
      s += (char)(val + '0');
    }
    for (int i = 0; i < n; i++) {
      string cur;
      for (int j = i; j < n; j++) {
        cur += s[j];
        ++mp[cur];
      }
    }
    bool cool = true;
    for (auto it = mp.begin(); it != mp.end(); it++)
      if (it->second % 2 == 0) {
        cool = false;
        break;
      }
    if (cool) cout << s << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
