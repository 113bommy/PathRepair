#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, b, a;
  cin >> n >> b >> a;
  int s[n];
  for (long long i = 0; i < n; i++) cin >> s[i];
  int amax = a;
  int ans = 1;
  a--;
  for (long long i = 1; i <= n - 1; i++) {
    if (s[i] == 0) {
      if (a > 0) {
        a--;
        ans++;
      } else if (b > 0) {
        b--;
        ans++;
      } else
        break;
    } else {
      if (a < amax) {
        if (b > 0) {
          b--;
          ans++;
          if (a < amax) a++;
        } else if (a > 0) {
          a--;
          ans++;
        } else
          break;
      } else {
        a--;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
