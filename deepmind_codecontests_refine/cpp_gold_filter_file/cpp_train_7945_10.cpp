#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool m[2005][2005] = {};
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    m[x + 1000][y + 1000] = 1;
  }
  int cnt = 0;
  for (int x = 1; x < 2004; x++) {
    for (int y = 1; y < 2004; y++) {
      if (m[x][y]) {
        bool yes = 0;
        for (int xx = 0; xx < x; xx++) {
          if (m[xx][y]) {
            yes = 1;
            break;
          }
        }
        if (!yes) continue;
        yes = 0;
        for (int xx = x + 1; xx < 2005; xx++) {
          if (m[xx][y]) {
            yes = 1;
            break;
          }
        }
        if (!yes) continue;
        yes = 0;
        for (int yy = 0; yy < y; yy++) {
          if (m[x][yy]) {
            yes = 1;
            break;
          }
        }
        if (!yes) continue;
        yes = 0;
        for (int yy = y + 1; yy < 2005; yy++) {
          if (m[x][yy]) {
            yes = 1;
            break;
          }
        }
        if (yes) cnt++;
      }
    }
  }
  cout << cnt << '\n';
}
