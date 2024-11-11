#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 74, M = 1e6 + 74, OO = 0x3f3f3f3f;
const double EPS = 1e-9;
long long BIT[4][1024][1024];
int n;
void add(int x, int y, long long v) {
  int c = (x & 1) | ((y & 1) << 1);
  for (; x <= n; x += ((x) & (-(x))))
    for (int _y = y; _y <= n; _y += ((_y) & (-(_y)))) BIT[c][x][_y] ^= v;
}
long long get(int x, int y) {
  long long ret = 0;
  int c = (x & 1) | ((y & 1) << 1);
  for (; x; x ^= ((x) & (-(x))))
    for (int _y = y; _y; _y ^= ((_y) & (-(_y)))) ret ^= BIT[c][x][_y];
  return ret;
}
long long get2d(int b, int l, int t, int r) {
  long long v = 0;
  v ^= get(t, r);
  v ^= get(t, l - 1);
  v ^= get(b - 1, r);
  v ^= get(b - 1, l - 1);
  return v;
}
void add2d(int x0, int y0, int x1, int y1, int v) {
  add(x0, y0, v);
  add(x0, y1 + 1, v);
  add(x1 + 1, y0, v);
  add(x1 + 1, y1 + 1, v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(NULL);
  int m;
  cin >> n >> m;
  while (m--) {
    int t;
    cin >> t;
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    if (x0 > x1) swap(x0, x1);
    if (y0 > y1) swap(y0, y1);
    if (t == 1) {
      long long res = 0;
      res ^= get(x1, y1);
      res ^= get(x0 - 1, y1);
      res ^= get(x1, y0 - 1);
      res ^= get(x0 - 1, y0 - 1);
      printf("%lld\n", res);
    } else {
      int v;
      cin >> v;
      add(x0, y0, v);
      add(x0, y1 + 1, v);
      add(x1 + 1, y0, v);
      add(x1 + 1, y1 + 1, v);
    }
  }
  return 0;
}
