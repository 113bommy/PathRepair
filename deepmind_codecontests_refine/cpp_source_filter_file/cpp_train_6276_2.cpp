#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
bool flag[N][N];
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a > b ? b : a; }
inline void read(int& first) {
  first = 0;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar())
    first = (first << 3) + (first << 1) + c - '0';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int first, second, xx, yy;
  cin >> first >> second >> xx >> yy;
  first += 1000;
  xx += 1000;
  yy += 1000;
  second += 1000;
  memset(flag, false, sizeof(flag));
  if (first < xx) swap(first, xx), swap(second, yy);
  if (second > yy) {
    for (int i = xx + 1; i < first; i++)
      flag[i][second] = true, flag[i][yy] = true;
    for (int i = yy + 1; i < second; i++)
      flag[first][i] = true, flag[xx][i] = true;
    flag[first][second] = flag[first][yy] = flag[xx][second] = flag[xx][yy] =
        true;
    int q;
    cin >> q;
    int a, b, r;
    while (q--) {
      cin >> a >> b >> r;
      a += 1000;
      b += 1000;
      for (int i = xx; i <= first; i++) {
        if ((i - a) * (i - a) + (yy - b) * (yy - b) <= r * r)
          flag[i][yy] = false;
        if ((i - a) * (i - a) + (second - b) * (second - b) <= r * r)
          flag[i][second] = false;
      }
      for (int i = yy; i <= second; i++) {
        if ((i - b) * (i - b) + (a - xx) * (a - xx) <= r * r)
          flag[xx][i] = false;
        if ((i - b) * (i - b) + (a - first) * (a - xx) <= r * r)
          flag[first][i] = false;
      }
    }
    int ans = 0;
    for (int i = xx + 1; i < first; i++) {
      if (flag[i][second]) {
        ans++;
      }
      if (flag[i][yy]) {
        ans++;
      }
    }
    for (int i = yy + 1; i < second; i++) {
      if (flag[first][i]) {
        ans++;
      }
      if (flag[xx][i]) {
        ans++;
      }
    }
    if (flag[first][second]) ans++;
    if (flag[first][yy]) ans++;
    if (flag[xx][second]) ans++;
    if (flag[xx][yy]) ans++;
    cout << ans << endl;
  } else {
    for (int i = xx + 1; i < first; i++)
      flag[i][second] = true, flag[i][yy] = true;
    for (int i = second + 1; i < yy; i++)
      flag[first][i] = true, flag[xx][i] = true;
    flag[first][second] = flag[first][yy] = flag[xx][second] = flag[xx][yy] =
        true;
    int q;
    int a, b, r;
    cin >> q;
    while (q--) {
      cin >> a >> b >> r;
      a += 1000;
      b += 1000;
      for (int i = xx; i <= first; i++) {
        if ((i - a) * (i - a) + (yy - b) * (yy - b) <= r * r)
          flag[i][yy] = false;
        if ((i - a) * (i - a) + (second - b) * (second - b) <= r * r)
          flag[i][second] = false;
      }
      for (int i = second; i <= yy; i++) {
        if ((i - b) * (i - b) + (a - xx) * (a - xx) <= r * r)
          flag[xx][i] = false;
        if ((i - b) * (i - b) + (a - first) * (a - first) <= r * r)
          flag[first][i] = false;
      }
    }
    int ans = 0;
    for (int i = xx + 1; i < first; i++) {
      if (flag[i][second]) {
        ans++;
      }
      if (flag[i][yy]) {
        ans++;
      }
    }
    for (int i = second + 1; i < yy; i++) {
      if (flag[first][i]) {
        ans++;
      }
      if (flag[xx][i]) {
        ans++;
      }
    }
    if (flag[first][second]) ans++;
    if (flag[first][yy]) ans++;
    if (flag[xx][second]) ans++;
    if (flag[xx][yy]) ans++;
    cout << ans << endl;
  }
  return 0;
}
