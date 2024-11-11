#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int mod = 1000000007;
int a, b, c, d, e, f, g, h, i, j, k;
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  friend Point operator-(const Point &x, const Point &y) {
    return Point(x.x - y.x, x.y - y.y);
  }
  friend long long operator^(const Point &x, const Point &y) {
    return (long long)x.x * y.y - (long long)x.y * y.x;
  }
};
Point G[N];
int F[N][N];
void Init() {
  cin >> a;
  for (int ii = 0; ii < a; ii++) scanf("%d%d", &G[ii].x, &G[ii].y);
  long long S = 0;
  for (int ii = 0; ii < a; ii++) S += (G[ii] ^ G[(ii + 1) % a]);
  if (S < 0) reverse(G, G + a);
}
void Work() {
  for (int dd = 1; dd < a; dd++) {
    for (int ii = 0, jj = ii + dd; jj < a; ii++, jj++) {
      if (dd == 1) {
        F[ii][jj] = 1;
        continue;
      }
      for (int kk = ii + 1; kk < jj; kk++)
        if (((G[kk] - G[ii]) ^ (G[kk] - G[jj])) < 0)
          (F[ii][jj] += (long long)F[ii][kk] * F[kk][jj] % mod) %= mod;
    }
  }
  cout << F[0][a - 1] << endl;
}
int main() {
  Init(), Work();
  return 0;
}
