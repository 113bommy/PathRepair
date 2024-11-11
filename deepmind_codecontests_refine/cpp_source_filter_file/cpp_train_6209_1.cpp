#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string s[1009];
int ans[1009][1009], vis[1009][1009];
void fun(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) {
    for (int i = x + 1; i < min(n, x + k + 1); i++) {
      if (s[i][y] == '#' || vis[i][y] == 1 ||
          (ans[i][y] >= 0 && ans[i][y] <= ans[x][y]))
        break;
      ans[i][y] = (ans[x][y] + 1);
      vis[i][y] = 1;
      fun(i, y);
    }
    for (int i = y + 1; i < min(m, y + k + 1); i++) {
      if (s[x][i] == '#' || vis[x][i] == 1 ||
          (ans[x][i] >= 0 && ans[x][i] <= ans[x][y]))
        break;
      ans[x][i] = (ans[x][y] + 1);
      vis[x][i] = 1;
      fun(x, i);
    }
    for (int i = x - 1; i >= max(0, x - k); i--) {
      if (s[i][y] == '#' || vis[i][y] == 1 ||
          (ans[i][y] >= 0 && ans[i][y] <= ans[x][y]))
        break;
      ans[i][y] = (ans[x][y] + 1);
      vis[i][y] = 1;
      fun(i, y);
    }
    for (int i = y - 1; i >= max(0, y - k); i--) {
      if (s[x][i] == '#' || vis[x][i] == 1 ||
          (ans[x][i] >= 0 && ans[x][i] <= ans[x][y]))
        break;
      ans[x][i] = (ans[x][y] + 1);
      vis[x][i] = 1;
      fun(x, i);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    string s, s1;
    cin >> s >> s1;
    int i;
    for (i = 1; i < s.size(); i++) {
      if (s[i] > s1[0]) break;
    }
    if (i == s.size())
      cout << s << s1[0];
    else
      cout << s.substr(0, i) << s1[0];
  }
}
