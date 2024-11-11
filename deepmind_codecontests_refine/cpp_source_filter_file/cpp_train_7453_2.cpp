#include <bits/stdc++.h>
using namespace std;
const long long mod = 10e7 + 9;
inline void add(long long &a, long long b) {
  a += b;
  if (a > mod) a -= mod;
}
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += mod;
}
inline long long mul(long long a, long long b) { return (a * b) % mod; }
inline int dig(int a, int i) { return 1 & (a >> (31 - i)); }
long long solve(int x, int y, int k) {
  long long ct[32][2][2][2], sum[32][2][2][2];
  memset(ct, 0, sizeof ct);
  memset(sum, 0, sizeof sum);
  if (x < 0 || y < 0 || k < 0) return 0;
  ct[0][1][1][1] = 1;
  for (int i = 0; i < 31; i++) {
    for (int xx = 0; xx < 2; xx++)
      for (int yy = 0; yy < 2; yy++) {
        int kk = xx ^ yy;
        for (int fx = 0; fx < 2; fx++)
          for (int fy = 0; fy < 2; fy++)
            for (int fk = 0; fk < 2; fk++) {
              if (fx && xx > dig(x, i + 1)) continue;
              if (fy && yy > dig(y, i + 1)) continue;
              if (fk && kk > dig(k, i + 1)) continue;
              add(ct[i + 1][fx & (xx == dig(x, i + 1))]
                    [fy & (yy == dig(y, i + 1))][fk & (kk == dig(k, i + 1))],
                  ct[i][fx][fy][fk]);
              add(sum[i + 1][fx & (xx == dig(x, i + 1))]
                     [fy & (yy == dig(y, i + 1))][fk & (kk == dig(k, i + 1))],
                  sum[i][fx][fy][fk]);
              add(sum[i + 1][fx & (xx == dig(x, i + 1))]
                     [fy & (yy == dig(y, i + 1))][fk & (kk == dig(k, i + 1))],
                  mul(kk << (30 - i), ct[i][fx][fy][fk]));
            }
      }
  }
  long long ans = 0;
  for (int xx = 0; xx < 2; xx++)
    for (int yy = 0; yy < 2; yy++)
      for (int kk = 0; kk < 2; kk++) {
        add(ans, ct[31][xx][yy][kk]);
        add(ans, sum[31][xx][yy][kk]);
      }
  return ans;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int x, y, x2, y2, k;
    cin >> x >> y >> x2 >> y2 >> k;
    x--;
    y--;
    x2--;
    y2--;
    k--;
    long long res = 0;
    add(res, solve(x2, y2, k));
    sub(res, solve(x2, y - 1, k));
    sub(res, solve(x - 1, y2, k));
    add(res, solve(x - 1, y - 1, k));
    cout << res << '\n';
  }
}
