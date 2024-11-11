#include <bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;
bool a[26];
int b[N][26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(a, false, sizeof(a));
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      a[s[i] - 'a'] = true;
    }
    bool flag = false;
    int m = t.length();
    for (int i = 0; i < m; i++) {
      if (!a[t[i] - 'a']) {
        flag = true;
      }
    }
    if (flag) {
      cout << -1 << endl;
      continue;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        if (i == n - 1) {
          b[i][j] = n + 10;
        } else {
          b[i][j] = b[i + 1][j];
        }
      }
      b[i][s[i] - 'a'] = i;
    }
    int ans = 0;
    int i = 0, j = 0;
    while (i < m) {
      ans++;
      int curr = b[0][t[i] - 'a'];
      j = i + 1;
      while (curr < n && j < m) {
        if (s[curr] != t[j]) {
          curr = b[curr][t[j] - 'a'];
        } else if (curr == n - 1) {
          curr++;
        } else {
          curr = b[curr + 1][t[j] = 'a'];
        }
        j++;
      }
      if (curr >= n) {
        i = j - 1;
      } else {
        i = j;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
