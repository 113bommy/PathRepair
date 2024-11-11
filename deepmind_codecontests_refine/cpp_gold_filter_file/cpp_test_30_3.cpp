#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int ans[N];
int T, n;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = -1;
  for (char i = 'a'; i <= 'z'; i++) {
    int cur = 0;
    int l = 0, r = n - 1;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else if (s[l] == i) {
        l++;
        cur++;
      } else if (s[r] == i) {
        r--;
        cur++;
      } else {
        cur = -1;
        break;
      }
    }
    if (cur != -1 && (ans == -1 || cur < ans)) ans = cur;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
