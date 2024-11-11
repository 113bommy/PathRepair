#include <bits/stdc++.h>
using namespace std;
void gk() {}
int64_t mul(int64_t a, int64_t b) {
  return (a * b) % (int64_t)1000000007;
  ;
}
int64_t bexpo(int64_t a, int64_t n) {
  int64_t res = 1;
  while (n > 0) {
    if (n & 1) {
      res = (res * a) % 1000000007;
      ;
    }
    a = (a * a) % 1000000007;
    ;
    n >>= 1;
  }
  return res;
}
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
const int64_t sz = 1e5 + 3;
const int64_t sz2 = 3e4 + 50;
int64_t row[4] = {0, 1, 0, -1};
int64_t col[4] = {1, 0, -1, 0};
int64_t n, m;
int64_t yh, ya, yd;
int64_t mh, ma, md;
int64_t h, a, d;
bool check(int64_t i, int64_t j, int64_t k) {
  int64_t x = j - md;
  int64_t y = ma - k;
  if (y <= 0) {
    return 1;
  }
  x = (mh + x - 1) / x;
  y = (i + y - 1) / y;
  return x < y;
}
void find() {
  cin >> yh >> ya >> yd;
  cin >> mh >> ma >> md;
  cin >> h >> a >> d;
  int64_t cost = 0;
  while (1) {
    int64_t x = ya - md;
    if (x <= 0) {
      cost += a;
      ya++;
    } else
      break;
  }
  int64_t m = -1;
  for (int64_t i = yh; i <= 500; i++) {
    for (int64_t j = ya; j <= 200; j++) {
      for (int64_t k = yd; k <= 100; k++) {
        if (!check(i, j, k)) continue;
        int64_t cost = (i - yh) * h + (j - ya) * a + (k - yd) * d;
        if (m == -1)
          m = cost;
        else
          m = min(m, cost);
        break;
      }
      if (check(i, j, yd)) break;
    }
    if (check(i, ya, yd)) break;
  }
  cout << cost + m;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  std::cout.tie(0);
  int64_t t = 1;
  while (t--) {
    find();
  }
  return 0;
}
