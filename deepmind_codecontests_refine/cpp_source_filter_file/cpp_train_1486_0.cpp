#include <bits/stdc++.h>
using namespace std;
const int MX = 500005;
const long long MOD = 1000000007;
void setIO(string name) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
int t;
int n, m;
char a[1000005][5];
int r[10], s[10], q[10];
void solve() {
  cin >> n >> m;
  int x, y;
  if (n > 3 && m > 3) {
    cout << -1 << endl;
    return;
  }
  if (n <= 3) {
    x = n, y = m;
    for (int i = 0; i < (n); i++) {
      for (int j = 0; j < (m); j++) {
        cin >> a[j][i];
      }
    }
  } else {
    x = m, y = n;
    for (int i = 0; i < (n); i++) {
      for (int j = 0; j < (m); j++) {
        cin >> a[i][j];
      }
    }
  }
  for (int i = 0; i < (5); i++) {
    s[i] = 0;
    q[i] = 0;
  }
  if (x == 3) {
    for (int i = 0; i < (y); i++) {
      for (int j = 0; j < (5); j++) r[j] = 0;
      if (a[i][0] == '1') {
        r[1]++;
        r[2]++;
        r[3]++;
        r[4]++;
      }
      if (a[i][1] == '1') {
        r[1]++;
        r[2]++;
      } else {
        r[3]++;
        r[4]++;
      }
      if (a[y][2] == '1') {
        r[2]++;
        r[4]++;
      } else {
        r[1]++;
        r[3]++;
      }
      for (int j = 0; j < (5); j++) r[j] = min(r[j], 3 - r[j]);
      if (i % 2 == 0)
        for (int j = 0; j < (5); j++) s[j] += r[j];
      else
        for (int j = 0; j < (5); j++) q[j] += r[j];
    }
    int ans = 2000000;
    ans = min(ans, s[1] + q[3]);
    ans = min(ans, s[2] + q[4]);
    ans = min(ans, s[4] + q[2]);
    ans = min(ans, s[3] + q[1]);
    cout << ans << endl;
    return;
  } else if (x == 2) {
    for (int i = 0; i < (y); i++) {
      for (int j = 0; j < (3); j++) r[j] = 0;
      if (a[i][0] == '1') {
        r[1]++;
        r[2]++;
      }
      if (a[i][1] == '1') {
        r[1]++;
        ;
      } else {
        r[2]++;
      }
      for (int j = 0; j < (3); j++) r[j] = min(r[j], 2 - r[j]);
      if (i % 2 == 0)
        for (int j = 0; j < (3); j++) s[j] += r[j];
      else
        for (int j = 0; j < (3); j++) q[j] += r[j];
    }
    int ans = 2000000;
    ans = min(ans, s[1] + q[2]);
    ans = min(ans, s[2] + q[1]);
    cout << ans << endl;
    return;
  } else {
    cout << 0 << endl;
    return;
  }
}
int main() {
  t = 1;
  for (int i = 0; i < (t); i++) {
    solve();
  }
}
