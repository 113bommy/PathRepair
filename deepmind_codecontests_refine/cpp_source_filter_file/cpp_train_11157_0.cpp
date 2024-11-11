#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
void solve() {
  int n, k;
  cin >> n >> k;
  string s1;
  cin >> s1;
  int mn = 1e9;
  string s;
  for (int i = 0; i < (int)(n - k + 1); i++) {
    s = s1;
    int ans = 0;
    if (s[i] != 'R') ans++;
    s[i] = 'R';
    for (int j = (int)(i + 1); j < (int)(i + k); j++) {
      int f = 0;
      if (s[j] == 'R' && s[j - 1] == 'G') f = 1;
      if (s[j] == 'G' && s[j - 1] == 'R') f = 1;
      if (s[j] == 'B' && s[j - 1] == 'G') f = 1;
      if (!f) {
        ans++;
        if (s[j - 1] == 'R') s[j] = 'G';
        if (s[j - 1] == 'G') s[j] = 'B';
        if (s[j - 1] == 'B') s[j] = 'R';
      }
    }
    mn = min(ans, mn);
  }
  for (int i = 0; i < (int)(n - k + 1); i++) {
    s = s1;
    int ans = 0;
    if (s[i] != 'G') ans++;
    s[i] = 'G';
    for (int j = (int)(i + 1); j < (int)(i + k); j++) {
      int f = 0;
      if (s[j] == 'R' && s[j - 1] == 'G') f = 1;
      if (s[j] == 'G' && s[j - 1] == 'R') f = 1;
      if (s[j] == 'B' && s[j - 1] == 'G') f = 1;
      if (!f) {
        ans++;
        if (s[j - 1] == 'R') s[j] = 'G';
        if (s[j - 1] == 'G') s[j] = 'B';
        if (s[j - 1] == 'B') s[j] = 'R';
      }
    }
    mn = min(ans, mn);
  }
  for (int i = 0; i < (int)(n - k + 1); i++) {
    s = s1;
    int ans = 0;
    if (s[i] != 'B') ans++;
    s[i] = 'B';
    for (int j = (int)(i + 1); j < (int)(i + k); j++) {
      int f = 0;
      if (s[j] == 'R' && s[j - 1] == 'G') f = 1;
      if (s[j] == 'G' && s[j - 1] == 'R') f = 1;
      if (s[j] == 'B' && s[j - 1] == 'G') f = 1;
      if (!f) {
        ans++;
        if (s[j - 1] == 'R') s[j] = 'G';
        if (s[j - 1] == 'G') s[j] = 'B';
        if (s[j - 1] == 'B') s[j] = 'R';
      }
    }
    mn = min(ans, mn);
  }
  cout << mn << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
