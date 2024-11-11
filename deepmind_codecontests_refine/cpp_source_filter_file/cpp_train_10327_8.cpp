#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    register string s, t, second = "", tt = "";
    cin >> n >> s >> t;
    long long cnt = 0;
    string ans = "Yes";
    for (register int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        second += s[i];
        tt += t[i];
        cnt++;
        if (cnt > 2) {
          ans = "No";
          break;
        }
      }
    }
    if (cnt == 1) {
      ans = "No";
    } else if (cnt == 2 and second[0] != second[1] and tt[0] != tt[1]) {
      ans = "No";
    }
    cout << ans << "\n";
  }
  return 0;
}
