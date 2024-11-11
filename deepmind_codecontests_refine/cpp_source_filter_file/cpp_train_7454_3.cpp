#include <bits/stdc++.h>
using namespace std;
int has[3];
char s[105][105];
map<char, int> mp;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  mp['R'] = 0;
  mp['G'] = 1;
  mp['B'] = 2;
  bool t = 1;
  for (int i = 0; i < n; i++) {
    bool f = 1;
    int now = mp[s[i][0]];
    for (int j = 1; j < m; j++)
      if (s[i][j] != s[i][j - 1]) f = 0;
    if (f == 0 || (has[now] && s[i - 1][0] != s[i][0]))
      t = 0;
    else if (f == 1)
      has[now]++;
  }
  t &= has[0] && has[1] && has[2] && (has[0] == has[1]) && (has[1] == has[2]);
  if (t) {
    cout << "YES";
    return 0;
  }
  memset(has, 0, sizeof(has));
  t = 1;
  for (int j = 0; j < m; j++) {
    bool f = 1;
    int now = mp[s[0][j]];
    for (int i = 1; i < n; i++)
      if (s[i][j] != s[i - 1][j]) f = 0;
    if (f == 0 || (has[now] && s[0][j - 1] != s[0][j]))
      t = 0;
    else if (f == 1)
      has[now] = 1;
  }
  t &= has[0] && has[1] && has[2] && (has[0] == has[1]) && (has[1] == has[2]);
  if (t) {
    cout << "YES";
  } else
    cout << "NO";
}
