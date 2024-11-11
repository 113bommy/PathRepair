#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000009, MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  string s = to_string(n);
  if ((n & (n - 1)) == 0) {
    cout << 0 << endl;
    return;
  }
  int i = 0;
  long long x = 1;
  int ans = INT_MAX;
  for (; i <= 40; i++) {
    x = (long long)((long long)1 << (long long)i);
    string k = to_string(x);
    int p = 0, q = 0;
    int w = 0;
    for (; p < s.length() && q < k.length(); p++) {
      if (s[p] == k[q]) {
        ++q;
        ++w;
      }
    }
    int h = s.length() - w;
    h += (k.length() - q);
    ans = min(ans, h);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
