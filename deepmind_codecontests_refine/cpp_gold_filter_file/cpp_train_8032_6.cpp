#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 4e5 + 10;
const int maxm = 2e5 + 10;
const double PI = acos(-1.0);
int mp[505][505];
int sum;
int vis[505][505];
int i, j, h, w;
bool check() {
  int cur = 0;
  for (int k = i; k >= 1; k--) {
    if (mp[k][j])
      cur++;
    else
      break;
  }
  for (int k = i; k <= h; k++) {
    if (mp[k][j])
      cur++;
    else
      break;
  }
  for (int k = j; k >= 1; k--) {
    if (mp[i][k])
      cur++;
    else
      break;
  }
  for (int k = j; k <= w; k++) {
    if (mp[i][k])
      cur++;
    else
      break;
  }
  return (cur - 3) == sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      char c;
      cin >> c;
      if (c == '*') {
        mp[i][j] = 1;
        sum++;
      } else
        mp[i][j] = 0;
    }
  }
  for (i = 2; i <= h - 1; i++) {
    for (j = 2; j <= w - 1; j++) {
      if (mp[i][j] && mp[i - 1][j] && mp[i + 1][j] && mp[i][j - 1] &&
          mp[i][j + 1]) {
        if (check()) {
          cout << "YES" << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
