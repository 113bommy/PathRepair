#include <bits/stdc++.h>
using namespace std;
int cnt[1000005] = {};
void gcdex(int a, int b, int &g, int &x, int &y) {
  if (!b) {
    g = a;
    x = 1;
    y = 0;
  } else {
    gcdex(b, a % b, g, y, x);
    y -= a / b * x;
  }
}
int main() {
  int x, y;
  int n, m;
  int dx, dy;
  int i;
  cin >> n >> m >> dx >> dy;
  int k;
  int u, v;
  gcdex(dx, n, u, k, v);
  k = (k % n + n) % n;
  dy = ((long long)dy * k) % n;
  int res = 0;
  int rx = 0, ry = 0;
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    y = (y + (long long)(n - x) * dy % n) % n;
    ++cnt[y];
    if (res < cnt[y]) {
      res = cnt[y];
      rx = 0;
      ry = y;
    }
  }
  cout << rx << " " << ry << endl;
  return 0;
}
