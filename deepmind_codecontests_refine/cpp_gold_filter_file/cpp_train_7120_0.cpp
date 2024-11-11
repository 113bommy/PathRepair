#include <bits/stdc++.h>
using namespace std;
char a[110][110];
int row[110];
int col[110];
int ans[110][110];
bool isdone(int n) {
  bool done = true;
  ;
  for (int i = 1; i <= n; i++) {
    if (row[i] == 0 || col[i] == 0) done = false;
  }
  return done;
}
bool hasdot(int r, int c, int n) {
  if (r) {
    for (int i = 1; i <= n; i++)
      if (a[r][i] == '.') return true;
    return false;
  }
  for (int i = 1; i <= n; i++)
    if (a[i][c] == '.') return true;
  return false;
}
int left(int r, int c, int n) {
  int ans = 0;
  if (r) {
    for (int i = 1; i <= n; i++)
      if (row[i] == 0) ans++;
  } else {
    for (int i = 1; i <= n; i++)
      if (col[i] == 0) ans++;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i] + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i][i] != 'E') {
      row[i] = col[i] = 1;
      ans[i][i] = 1;
    }
  }
  int vc, vr;
  int minval = 1000000007;
  if (!isdone(n)) {
    vc = vr = 0;
    for (int i = 1; i <= n; i++) {
      if (!row[i]) {
        if (hasdot(i, 0, n)) vr++;
      }
      if (!col[i]) {
        if (hasdot(0, i, n)) vc++;
      }
    }
    if (vr == left(1, 0, n)) minval = (minval > vr ? (vr) : (minval));
    if (vc == left(0, 1, n)) minval = (minval > vc ? (vc) : (minval));
    if (minval == 1000000007) {
      cout << -1 << endl;
      return 0;
    }
    if (minval == vr) {
      for (int i = 1; i <= n; i++) {
        if (row[i]) continue;
        for (int j = 1; j <= n; j++) {
          if (a[i][j] == '.') {
            ans[i][j] = 1;
            break;
          }
        }
      }
    } else {
      for (int i = 1; i <= n; i++) {
        if (col[i]) continue;
        for (int j = 1; j <= n; j++) {
          if (a[j][i] == '.') {
            ans[j][i] = 1;
            break;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (ans[i][j]) cout << i << " " << j << endl;
  }
  return 0;
}
