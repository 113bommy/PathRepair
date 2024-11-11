#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int xl[N], yl[N], xr[N], yr[N];
int n;
int x, y;
int check(int mid) {
  int l = 1;
  for (int r = mid; r < n; r++) {
    int tx = xl[l - 1] + xr[r + 1];
    int ty = yl[l - 1] + yr[r + 1];
    int rx = abs(x - tx);
    int ry = abs(y - ty);
    if (mid >= rx + ry && (mid - (rx + ry)) % 2 == 0) return 1;
    l++;
  }
  return 0;
}
int main() {
  cin >> n;
  string s;
  cin >> s;
  s = '@' + s;
  n++;
  for (int i = 1; i < n; i++) {
    xl[i] = xl[i - 1], yl[i] = yl[i - 1];
    if (s[i] == 'U') {
      yl[i]++;
    }
    if (s[i] == 'D') {
      yl[i]--;
    }
    if (s[i] == 'L') {
      xl[i]--;
    }
    if (s[i] == 'R') {
      xl[i]++;
    }
  }
  for (int i = n - 1; i > 0; i--) {
    xr[i] = xr[i + 1], yr[i] = yr[i + 1];
    if (s[i] == 'U') {
      yr[i]++;
    }
    if (s[i] == 'D') {
      yr[i]--;
    }
    if (s[i] == 'L') {
      xr[i]--;
    }
    if (s[i] == 'R') {
      xr[i]++;
    }
  }
  cin >> x >> y;
  int l = 0, h = n;
  while (h - l > 1) {
    int mid = (h + l) / 2;
    if (check(mid))
      h = mid;
    else
      l = mid;
  }
  if (h == n)
    cout << "-1";
  else
    cout << h;
}
