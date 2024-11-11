#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const long long MAX = 5e18;
int T, n;
string s, t;
bool can() {
  bool sm = n > 26;
  string x = s;
  sort(x.begin(), x.end());
  for (int i = 1; i < n; i++)
    if (s[i] == s[i - 1]) sm = 1;
  if (sm) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
  int ans = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    int x = -1, y = -1;
    for (int j = 0; j < n; j++) {
      if (s[j] == i) x = j;
      if (t[j] == i) y = j;
    }
    if (x == -1 ^ y == -1) return 0;
    if (x != -1) {
      ans += abs(x - y);
      s.erase(s.begin() + x);
      t.erase(t.begin() + y);
    }
  }
  return ans % 2 == 0;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> s >> t;
    puts(can() ? "YES" : "NO");
  }
  return 0;
}
