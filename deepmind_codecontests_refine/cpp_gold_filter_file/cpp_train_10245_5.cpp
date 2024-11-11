#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000];
int ai00(int x, int y, string s) {
  a[0] = 0;
  b[0] = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    a[i + 1] = a[i];
    b[i + 1] = b[i];
    if (s[i] == 'U') b[i + 1]++;
    if (s[i] == 'D') b[i + 1]--;
    if (s[i] == 'L') a[i + 1]--;
    if (s[i] == 'R') a[i + 1]++;
  }
  for (int i = 0; i < n; ++i) {
    int xx = x - a[i];
    int yy = y - b[i];
    int dx = a[n] - a[0];
    int dy = b[n] - b[0];
    if (dx) {
      int t = xx / dx;
      if (t < 0) continue;
      if (xx - dx * t) continue;
      if (t * dy != yy) continue;
      return true;
    } else if (dy) {
      int t = yy / dy;
      if (t < 0) continue;
      if (yy - dy * t) continue;
      if (t * dx != xx) continue;
      return true;
    } else {
      if (xx) continue;
      if (yy) continue;
      return true;
    }
  }
  return false;
}
int main() {
  string s;
  int n;
  int x, y;
  while (cin >> x >> y) {
    cin >> s;
    n = s.size();
    if (ai00(x, y, s))
      printf("Yes\n");
    else
      printf("No\n");
  }
}
