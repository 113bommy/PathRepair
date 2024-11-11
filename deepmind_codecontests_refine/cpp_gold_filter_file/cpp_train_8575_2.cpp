#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  if (k > n || (n > 1 && k == 1))
    cout << -1 << endl;
  else {
    char x = 'c';
    string ans = "";
    for (long long i = 0; i < n; i++) {
      if (i < n - (k - 2)) {
        if (i == 0)
          ans += 'a';
        else {
          if (ans[i - 1] == 'a')
            ans += 'b';
          else
            ans += 'a';
        }
      } else
        ans += x++;
    }
    cout << ans << endl;
  }
}
int main() {
  long long tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
