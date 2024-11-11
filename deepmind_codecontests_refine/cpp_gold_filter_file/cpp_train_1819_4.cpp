#include <bits/stdc++.h>
using namespace std;
int fg = 0;
string s[100005], ps, px, v;
void dfs(int now, int n, int tag) {
  if (fg) return;
  if (now == n) {
    if (tag) fg = 1, v = px;
    return;
  }
  if (tag == 0) {
    if (px[now] == '?') {
      for (int i = 0; i <= 9; i++) {
        if (fg) return;
        if (i < (ps[now] - '0')) continue;
        if (i == (ps[now] - '0')) {
          px[now] = (char)(i + '0');
          dfs(now + 1, n, 0);
          px[now] = '?';
        }
        if (i > (ps[now] - '0')) {
          px[now] = (char)(i + '0');
          dfs(now + 1, n, 1);
          px[now] = '?';
        }
      }
    } else {
      if (px[now] > ps[now]) dfs(now + 1, n, 1);
      if (px[now] == ps[now]) dfs(now + 1, n, 0);
      if (px[now] < ps[now]) return;
    }
  } else {
    if (fg) return;
    if (px[now] == '?') {
      px[now] = '0';
      dfs(now + 1, n, 1);
      px[now] = '?';
    } else
      dfs(now + 1, n, 1);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < s[1].length(); i++) {
    int x = (i == 0);
    if (s[1][i] == '?') s[1][i] = (char)(x + '0');
  }
  for (int i = 2; i <= n; i++) {
    if (s[i].length() < s[i - 1].length()) {
      cout << "NO" << endl;
      return 0;
    }
    if (s[i].length() > s[i - 1].length()) {
      for (int j = 0; j < s[i].length(); j++) {
        int x = (j == 0);
        if (s[i][j] == '?') s[i][j] = (char)(x + '0');
      }
    }
    if (s[i].length() == s[i - 1].length()) {
      px = s[i];
      ps = s[i - 1];
      v = "";
      fg = 0;
      dfs(0, s[i].length(), 0);
      if (!fg) {
        cout << "NO" << endl;
        return 0;
      }
      s[i] = v;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << s[i] << endl;
  }
}
