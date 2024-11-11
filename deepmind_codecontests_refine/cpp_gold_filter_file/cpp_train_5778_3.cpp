#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5;
const int K = 26;
const int M = 502;
const int inf = (int)1e9 + 7;
char a[M][M];
int dd[M][M], dp[M][M];
int n, m;
int px[4] = {-1, 0, 1, 0};
int py[4] = {0, -1, 0, 1};
bool good(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) {
    return 1;
  }
  return 0;
}
int find(int x, int y, int z, int t) {
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int xx = x + px[i], yy = y + py[i], zz = z + px[j], tt = t + py[j];
      if (good(xx, yy) && good(zz, tt) && xx == zz && tt == yy) {
        ans++;
      }
    }
  }
  return ans;
}
int main() {
  int a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  int ans = 0;
  if (a3 >= a1) {
    ans += (a1 + a2) * (a1 + a2) - a2 * a2;
    a3 -= a1;
    ans += (a1 + a2) * a3 * 2;
    a6 -= a3;
    ans += (a5 + a6) * (a5 + a6) - a5 * a5;
  } else {
    ans += (a3 + a2) * (a3 + a2) - a2 * a2;
    a1 -= a3;
    ans += (a2 + a3) * a1 * 2;
    a4 -= a1;
    ans += (a4 + a5) * (a4 + a5) - a5 * a5;
  }
  cout << ans;
  return 0;
}
