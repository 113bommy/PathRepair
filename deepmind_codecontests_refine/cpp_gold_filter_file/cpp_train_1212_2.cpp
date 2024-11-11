#include <bits/stdc++.h>
using namespace std;
const int pp = 1e9 + 7;
const long long oo = 1e18;
int l, r;
struct Tmatrix {
  int num[17][17];
  void clear() { memset(num, 0, sizeof(num)); }
  void unit() {
    clear();
    for (int i = 0; i <= 16; i++) num[i][i] = 1;
  }
  Tmatrix operator*(const Tmatrix &t) {
    Tmatrix c;
    for (int i = 0; i <= 16; i++)
      for (int j = 0; j <= 16; j++) {
        long long x = 0;
        for (int k = 0; k <= 16; k++) {
          x += (long long)num[i][k] * t.num[k][j];
          if (x >= oo) x %= pp;
        }
        c.num[i][j] = x % pp;
      }
    return c;
  }
} tmp;
struct Tprogram {
  void open() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  }
  void close() {}
  void init() { scanf("%d%d", &l, &r); }
  int power(int x, int n) {
    int tmp = x, ans = 1;
    while (n) {
      if (n & 1) ans = (long long)ans * tmp % pp;
      tmp = (long long)tmp * tmp % pp;
      n >>= 1;
    }
    return ans;
  }
  int ask(int n) {
    if (n == 0) return 0;
    if (n == 1) return 4;
    n--;
    tmp.clear();
    for (int i = 0; i <= 15; i++)
      for (int j = 0; j <= 15; j++) {
        int x1 = i >> 2, x2 = i & 3;
        int y1 = j >> 2, y2 = j & 3;
        if (x2 != y1) continue;
        if (y1 == y2) continue;
        if (y1 + y2 == 3) continue;
        if (x1 == 2 && x2 == 0 && y2 == 1) continue;
        if (x1 == 1 && x2 == 0 && y2 == 2) continue;
        tmp.num[i][j] = 1;
      }
    for (int i = 0; i <= 16; i++) tmp.num[i][16] = 1;
    Tmatrix ans;
    ans.unit();
    while (n) {
      if (n & 1) ans = ans * tmp;
      tmp = tmp * tmp;
      n >>= 1;
    }
    int s = (long long)4 * ans.num[16][16] % pp;
    for (int i = 0; i <= 15; i++) {
      int x = i >> 2, y = i & 3;
      if (x + y == 3) continue;
      if (x == y) continue;
      s = (s + ans.num[i][16]) % pp;
    }
    return s;
  }
  int get(int n) {
    return ((long long)ask(n) + ask(n + 1 >> 1)) * power(2, pp - 2) % pp;
  }
  void work() {
    int ans = get(r) - get(l - 1);
    if (ans < 0) ans += pp;
    printf("%d\n", ans);
  }
} Program;
int main() {
  Program.init();
  Program.work();
  return 0;
}
