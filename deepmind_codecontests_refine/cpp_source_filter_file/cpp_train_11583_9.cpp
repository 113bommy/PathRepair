#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s, pad = "";
    cin >> s;
    for (int i = 0; i < (k); i++) pad += '0';
    s = pad + s + pad;
    int ans = 0, l = k, r = k, idx = -1;
    bool left = true;
    for (int i = 0; i < s.length(); i++) {
      if (l == 0 && r == 0) {
        ans++;
        l = k;
        r = k;
        left = true;
      }
      if (s[i] == '1') {
        l = k;
        r = k;
        left = true;
        continue;
      }
      if (l == 0 && left) {
        left = !left;
        continue;
      }
      (left ? l : r)--;
    }
    if (l == 0 && r == 0) {
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
