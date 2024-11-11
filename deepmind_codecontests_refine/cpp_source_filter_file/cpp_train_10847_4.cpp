#include <bits/stdc++.h>
using namespace std;
const int N = 32 + 10;
long long f[N][2][2];
long long calc(int l, int r) {
  if (l < 0) return 0;
  if (r < 0) return 0;
  memset(f, 0, sizeof(f));
  f[32][1][1] = 1;
  for (int i = 31; i >= 0; --i) {
    int p = (l >> i & 1), q = (r >> i & 1);
    for (int x = 0; x < 2; ++x)
      for (int y = 0; y < 2; ++y)
        for (int a = 0; a < 2; ++a)
          for (int b = 0; b < 2; ++b) {
            int v1 = f[i + 1][x][y];
            if (a & b) continue;
            if (x == 1 && a > p) continue;
            if (y == 1 && b > q) continue;
            int op1, op2;
            if (x == 0 || (x == 1 && a < p))
              op1 = 0;
            else
              op1 = 1;
            if (y == 0 || (y == 1 && b < q))
              op2 = 0;
            else
              op2 = 1;
            f[i][op1][op2] += v1;
          }
  }
  long long tot = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) tot += f[0][i][j];
  return tot;
}
void solve() {
  int l, r;
  cin >> l >> r;
  cout << calc(r, r) - calc(l - 1, r) - calc(r, l - 1) + calc(l - 1, l - 1)
       << endl;
}
int main() {
  int T = 1;
  ios::sync_with_stdio(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
