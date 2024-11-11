#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
char mp[20][20];
bool check() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int x = i, y = j, cnt = 0, tmp = 0;
      while (x < 10 && tmp < 5) {
        if (mp[x][y] == 'X') cnt++;
        x++;
        tmp++;
      }
      if (cnt == 5) return 1;
      x = i, y = j, cnt = tmp = 0;
      while (y < 10 && tmp < 5) {
        if (mp[x][y] == 'X') cnt++;
        y++;
        tmp++;
      }
      if (cnt == 5) return 1;
      x = i, y = j, cnt = tmp = 0;
      while (x < 10 && y < 10 && tmp < 5) {
        if (mp[x][y] == 'X') cnt++;
        x++, y++;
        tmp++;
      }
      if (cnt == 5) return 1;
      x = i, y = j, cnt = tmp = 0;
      while (x >= 0 && y < 10 && tmp < 5) {
        if (mp[x][y] == 'X') cnt++;
        x--, y++;
        tmp++;
      }
      if (cnt == 5) return 1;
    }
  }
  return 0;
}
int dfs() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (mp[i][j] != '.') continue;
      mp[i][j] = 'X';
      if (check()) {
        cout << "YES";
        return 1;
      }
      mp[i][j] = '.';
    }
  }
  return 0;
}
int main() {
  for (int i = 0; i < 10; i++) cin >> mp[i];
  if (!dfs()) cout << "NO\n";
}
