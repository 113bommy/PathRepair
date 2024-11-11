#include <bits/stdc++.h>
using namespace std;
string s[10];
int dx[5] = {-1, 0, 1};
int dy[5] = {-1, 0, 1};
int dangerx[100];
int dangery[100];
int cnt = 0;
int dangertime = 0;
bool win = false;
bool isv(int x, int y) {
  if (x < 8 and x >= 0 and y < 8 and y >= 0) {
    return true;
  }
  return false;
}
void dfs(int x, int y, int time) {
  if (s[x][y] == 'A' or time > dangertime or win == true) {
    win = true;
    return;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (isv(x + dx[i], y + dy[j])) {
        bool check = true;
        for (int k = 0; k < cnt; k++) {
          if ((x + dx[i] == dangerx[k] + time and y + dy[j] == dangery[k]) or
              (x + dx[i] == dangerx[k] + time - 1 and
               y + dy[j] == dangery[k])) {
            check = false;
          }
        }
        if (check == true) {
          dfs(x + dx[i], y + dy[j], time + 1);
        }
      }
    }
  }
  return;
}
int main() {
  for (int i = 0; i < 8; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] == 'S') {
        dangerx[cnt] = i;
        dangery[cnt] = j;
        dangertime = max(dangertime, i);
        cnt++;
      }
    }
  }
  dangertime = 8 - dangertime + 2;
  dfs(7, 0, 1);
  if (win == true) {
    cout << "WIN";
    return 0;
  }
  cout << "LOSE";
  return 0;
}
