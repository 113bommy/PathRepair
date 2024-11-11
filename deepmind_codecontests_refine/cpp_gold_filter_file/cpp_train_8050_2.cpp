#include <bits/stdc++.h>
using namespace std;
inline int miin(int x, int y) { return x < y ? x : y; }
class sum {
 public:
  int a[(1 << 19) + (1 << 19)];
  void set(int x, int y) {
    x += (1 << 19);
    a[x] += y;
    x >>= 1;
    while (x > 0) {
      a[x] = miin(a[x + x], a[x + x + 1]);
      x >>= 1;
    }
  }
  int move(int x) {
    x += (1 << 19);
    while (a[x] > 0) {
      if (x % 2 == 1) {
        x++;
      } else {
        x /= 2;
      }
    }
    while (x < (1 << 19)) {
      if (a[x + x] == 0) {
        x = x + x;
      } else {
        x = x + x + 1;
      }
    }
    return x - (1 << 19);
  }
};
map<int, int> mp;
sum s;
int a[400005], adr[400005], b[400005], h[400005];
int i, j, k, n, m, x, y, z, t, fr, d;
long long res;
char cc[10];
int main() {
  memset(adr, -1, sizeof(adr));
  memset(b, -1, sizeof(b));
  scanf("%d%d%d", &n, &d, &m);
  for (i = 0; i < n; i++) {
    if (adr[i] == -1) {
      x = i;
      y = fr;
      while (adr[x] == -1) {
        adr[x] = fr;
        a[fr] = x;
        fr++;
        x = (x + d) % n;
      }
      b[fr] = y;
      fr++;
    }
  }
  res = 0;
  while (m--) {
    scanf("%s%d", &cc, &x);
    if (cc[0] == '+') {
      scanf("%d", &y);
      k = s.move(adr[y]);
      res += k - adr[y];
      if (b[k] != -1) {
        t = s.move(b[k]);
        res += t - b[k];
        k = t;
      }
      mp[x] = k;
      s.set(k, 1);
    } else {
      s.set(mp[x], -1);
    }
  }
  printf("%I64d\n", res);
  return 0;
}
