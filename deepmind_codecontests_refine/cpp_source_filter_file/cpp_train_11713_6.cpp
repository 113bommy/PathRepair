#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T>
inline void gmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void gmin(T &a, T b) {
  if (b < a) a = b;
}
const int N = 100 + 5, M = 1000 + 5, S = 1e5 + 5, Z = 1e9 + 7,
          ms63 = 1061109567;
int n, m, k;
int TOP;
struct BIT {
  double f[S];
  double query(int x) {
    if (++x <= 0) return 0;
    double tmp = 0;
    for (; x; x -= x & -x) tmp += f[x];
    return tmp;
  }
  void modify(int x, double v) {
    if (++x <= 0) return;
    for (; x <= TOP + 1; x += x & -x) f[x] += v;
  }
} bit[2];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    if (m == 1) {
      puts("1");
      continue;
    }
    TOP = n * m;
    double mu = 1.0 / (m - 1);
    memset(bit, 0, sizeof(bit));
    bit[0].modify(0, 1);
    int mysco = 0;
    int pre = 0, now = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k);
      mysco += k;
      memset(bit[now].f, 0, sizeof(bit[now].f));
      int top = i * m;
      for (int j = i; j <= top; ++j) {
        double rate = (bit[pre].query(j - 1) - bit[pre].query(j - m - 1)) -
                      (bit[pre].query(j - k) - bit[pre].query(j - k - 1));
        bit[now].modify(j, rate * mu);
      }
      pre ^= 1;
      now ^= 1;
    }
    double ans = bit[pre].query(mysco - 1);
    ans = ans * (m - 1) + 1;
    printf("%.12f\n", ans);
  }
  return 0;
}
