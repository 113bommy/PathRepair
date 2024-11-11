#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, m, f[200009][30], vis[30], l, r, ans, flag, mid;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (!i)
      f[i][s[i] - 'a'] = 1;
    else {
      for (int j = 0; j < 30; j++) {
        if (s[i] - 'a' == j) {
          f[i][j] = f[i - 1][j] + 1;
        } else
          f[i][j] = f[i - 1][j];
      }
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t;
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < t.size(); j++) {
      vis[t[j] - 'a']++;
    }
    ans = 0;
    l = 0, r = n;
    while (l < r) {
      mid = (l + r) / 2;
      flag = 1;
      for (int j = 0; j < 30; j++) {
        if (f[mid][j] < vis[j]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans + 1 << endl;
  }
}
