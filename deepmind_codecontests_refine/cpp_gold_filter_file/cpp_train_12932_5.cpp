#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int m_inf = INT_MIN;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int pos = 25;
    bool vis[26] = {false};
    bool ok = true;
    vector<char> a(55, '0');
    for (int i = 0; i < n; i++) {
      if (vis[s[i] - 'a'] == false) {
        vis[s[i] - 'a'] = true;
        if (a[pos + 1] == '0') {
          a[pos + 1] = s[i];
          pos = pos + 1;
        } else if (a[pos - 1] == '0') {
          a[pos - 1] = s[i];
          pos = pos - 1;
        } else {
          ok = false;
          break;
        }
      } else {
        if (a[pos + 1] == s[i]) {
          pos = pos + 1;
        } else if (a[pos - 1] == s[i])
          pos = pos - 1;
        else {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      string ans = "";
      for (int i = 0; i < a.size(); i++) {
        if (a[i] != '0') ans += a[i];
      }
      for (char x = 'a'; x <= 'z'; x++) {
        if (vis[x - 'a'] == false) ans += x;
      }
      cout << ans << '\n';
    }
  }
}
