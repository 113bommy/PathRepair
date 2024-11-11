#include <bits/stdc++.h>
using namespace std;
char s[100005];
long long t, len;
bool vis[100005];
signed main() {
  ios::sync_with_stdio(false);
  long long t, n;
  cin >> t;
  while (t--) {
    memset(vis, false, sizeof(vis));
    long long ans = 0;
    cin >> n;
    cin >> s + 1;
    len = strlen(s + 1);
    for (long long i = 1; i <= len; i++) {
      if (s[i] == s[i - 1]) {
        vis[i] = true;
        if (s[i] == '0') {
          s[i] = '1';
        } else {
          s[i] = '0';
        }
      }
    }
    for (long long i = 1; i <= len; i++) {
      if (vis[i]) {
        while (i + 1 <= len && vis[i + 1]) i++;
        ans++;
      }
    }
    cout << ans << endl;
  }
}
