#include <bits/stdc++.h>
using namespace std;
const int N = 16;
int64_t f[N][2][2];
int64_t work(int64_t r) {
  int64_t ans = 0;
  for (int ob = 0; ob < N; ++ob) {
    memset(f, 0, sizeof(f));
    int r0 = r & 15;
    for (int x = 0; x <= ob; ++x) {
      f[0][x == ob][x <= r0] += ob > 3 || (x >> ob & 1);
    }
    for (int i = 0; i < 15; ++i) {
      int ri = r >> (i + 1) * 4 & 15;
      for (int x = 0; x <= ob; ++x) {
        if (ob / 4 == i + 1)
          if ((x >> (ob % 4) & 1) == 0) continue;
        int j = x == ob;
        if (x < ri) {
          f[i + 1][j][1] += f[i][0][0] + f[i][0][1];
          f[i + 1][1][1] += f[i][1][0] + f[i][1][1];
        } else if (x == ri) {
          f[i + 1][j][1] += f[i][0][1];
          f[i + 1][j][0] += f[i][0][0];
          f[i + 1][1][1] += f[i][1][1];
          f[i + 1][1][0] += f[i][1][0];
        } else {
          f[i + 1][j][0] += f[i][0][0] + f[i][0][1];
          f[i + 1][1][0] += f[i][1][0] + f[i][1][1];
        }
      }
    }
    ans += f[15][1][1];
  }
  return ans;
}
int main() {
  int n;
  for (scanf("%d", &n); n--;) {
    int64_t l, r;
    scanf("%" PRIx64 "%" PRIx64, &l, &r);
    if (l == 0) l = 1;
    cout << work(r) - work(l) << endl;
  }
  return 0;
}
