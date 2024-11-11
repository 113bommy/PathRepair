#include <bits/stdc++.h>
using namespace std;
int flag[10][10];
int mp[505];
int a[22];
int judge(void) {
  int vis[10][10];
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 4; j++) {
      vis[i][j] = flag[i][j];
      if (a[i] && a[j + 5]) vis[i][j] = 0;
    }
  }
  while (1) {
    int cao = 0;
    for (int i = 0; i <= 4; i++) {
      if (a[i] == 0) continue;
      int sum = 0;
      for (int j = 0; j <= 4; j++) {
        if (vis[i][j]) sum++;
      }
      if (sum == 1) {
        cao = 1;
        for (int j = 0; j <= 4; j++) {
          vis[i][j] = 0;
        }
        break;
      }
    }
    if (cao) continue;
    for (int i = 0; i <= 4; i++) {
      if (a[i + 5] == 0) continue;
      int sum = 0;
      for (int j = 0; j <= 4; j++) {
        if (vis[j][i]) sum++;
      }
      if (sum == 1) {
        cao = 1;
        for (int j = 0; j <= 4; j++) {
          vis[j][i] = 0;
        }
        break;
      }
    }
    if (cao == 0) break;
  }
  int sum = 0;
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 4; j++) {
      sum += vis[i][j];
    }
  }
  if (sum <= 1)
    return 1;
  else
    return 0;
}
int main() {
  mp['R'] = 0;
  mp['G'] = 1;
  mp['B'] = 2;
  mp['Y'] = 3;
  mp['W'] = 4;
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    flag[mp[s[0]]][s[1] - '0'] = 1;
  }
  int mi = 10;
  for (int i = 0; i < (1 << 10); i++) {
    int sum = 0;
    for (int j = 0; j < 10; j++) {
      a[j] = ((i >> j) & 1);
      sum += a[j];
    }
    int z = judge();
    if (z) mi = min(mi, sum);
  }
  cout << mi << endl;
  return 0;
}
