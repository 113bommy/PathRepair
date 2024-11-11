#include <bits/stdc++.h>
using namespace std;
const int BIT = 52;
long long s;
int f[2][BIT * 2][2];
int main() {
  cin >> s;
  long long ans = 0;
  for (int L = 0; L < BIT; L++)
    for (int R = 0; R < BIT; R++) {
      long long v = s / ((1ll << (L + 1)) + (1ll << (R + 1)) - 3);
      if (v <= 0) continue;
      long long nw =
          s - (v - 1) * ((1ll << (L + 1)) + (1ll << (R + 1)) - 3) + 1;
      for (int os = 0; os <= L + R + 2; os++) {
        long long go = nw + os;
        if (go & 1) continue;
        go /= 2;
        memset(f, 0, sizeof f);
        int cr = 0;
        f[cr][0][0] = 1;
        int bit = max(L, R);
        if (go >= (1ll << (bit + 2))) continue;
        for (int i = 0; i <= bit; i++, cr ^= 1) {
          memset(f[cr ^ 1], 0, sizeof f[cr ^ 1]);
          for (int bc = 0; bc <= os; bc++)
            for (int ad = 0; ad < 2; ad++)
              if (f[cr][bc][ad])
                for (int lv = 0; lv < 2; lv++)
                  if (i > L && lv || i == L && !lv || i == L - 1 && lv)
                    continue;
                  else
                    for (int rv = 0; rv < 2; rv++)
                      if (i > R && rv || i == R && !rv || i == R - 1 && !rv)
                        continue;
                      else {
                        int cval = lv + rv + ad;
                        if (cval % 2 != bool(go & (1ll << i))) continue;
                        f[cr ^ 1][bc + lv + rv][cval >> 1] += f[cr][bc][ad];
                      }
        }
        ans += f[cr][os][bool(go & (1ll << (bit + 1)))];
      }
    }
  cout << ans << endl;
}
