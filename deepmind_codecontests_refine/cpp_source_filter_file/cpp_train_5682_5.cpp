#include <bits/stdc++.h>
using namespace std;
const int BASE = 70;
long long dataf[BASE][BASE * 2][2];
int main() {
  long long s;
  scanf("%lld", &s);
  long long ans = 0;
  long long(*f)[BASE * 2][2] = dataf + 1;
  for (int le = 0;; le++) {
    long long t1 = (1LL << (le + 1));
    if (t1 > s) break;
    for (int ri = 0;; ri++) {
      long long t2 = (1LL << (ri + 1));
      if (t1 + t2 - 3 > s) break;
      long long v = s / (t1 + t2 - 3);
      long long tg = s - (v - 1) * (t1 + t2 - 3) + 1;
      int maxbase = max(le + 1, ri + 1);
      int maxc = le + ri;
      for (int sumc = 0; sumc <= maxc; sumc++)
        f[-1][sumc][0] = f[-1][sumc][1] = 0;
      f[-1][0][0] = 1;
      for (int dsumc = 0; dsumc <= maxc; dsumc++) {
        long long tg2 = tg + dsumc + 2;
        if (tg2 & 1) continue;
        tg2 >>= 1;
        tg2 -= (1LL << (le)) + (1LL << (ri));
        if (tg2 < 0) continue;
        for (int i = -1; i < maxbase; i++) {
          for (int sumc = 0; sumc <= maxc; sumc++)
            f[i + 1][sumc][0] = f[i + 1][sumc][1] = 0;
          for (int sumc = 0; sumc <= maxc; sumc++)
            for (int nho = 0; nho < 2; nho++) {
              if (f[i][sumc][nho] == 0) continue;
              int tgbit = (((tg2) >> (i + 1)) & 1);
              for (int b1 = 0; b1 < 2; b1++) {
                if (b1 == 1 && i + 1 >= le) continue;
                if (i + 1 == le - 1 && b1 != 0) continue;
                for (int b2 = 0; b2 < 2; b2++) {
                  if (b2 == 1 && i + 1 >= ri) continue;
                  if (i + 1 == ri - 1 && b2 != 1) continue;
                  int kq = (b1 + b2 + nho);
                  if ((kq & 1) != tgbit) continue;
                  if (sumc + b1 + b2 > maxc) continue;
                  kq >>= 1;
                  f[i + 1][sumc + b1 + b2][kq] += f[i][sumc][nho];
                }
              }
            }
        }
        ans += f[maxbase][dsumc][0];
      }
    }
  }
  printf("%lld", ans);
}
