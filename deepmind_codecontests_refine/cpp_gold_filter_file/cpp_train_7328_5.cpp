#include <bits/stdc++.h>
using namespace std;
const int N(19), D(10);
long long n;
long long p[N];
long long g[D], _g[D];
long long f[N][D][D][D][D];
void update(long long &v, long long nv) {
  if (v == -1 || v > nv) v = nv;
}
int getMax(long long n) { return n ? max((int)(n % 10), getMax(n / 10)) : 0; }
int main() {
  cin >> n;
  if (n < 10) {
    cout << (n + 9) / 10 << endl;
    return 0;
  }
  p[0] = 1;
  for (int i = int(1); i < int(N); ++i) p[i] = p[i - 1] * 10;
  memset(f, -1, sizeof(f));
  for (int i = int(0); i < int(D); ++i)
    for (int j = int(0); j < int(D); ++j)
      for (int k = int(0); k < int(D); ++k) {
        int num = j * 10 + k, step = 0;
        while (num > 0) {
          num -= max(i, max(num / 10, num % 10));
          ++step;
          if (num >= 0 && num < 10) f[1][i][j][k][num] = step;
        }
      }
  for (int l = int(2); l < int(N); ++l)
    for (int i = int(0); i < int(D); ++i)
      for (int j = int(1); j < int(D); ++j)
        for (int k = int(0); k < int(D); ++k) {
          long long num = p[l] + k - max(i, max(j, k));
          if (num >= p[l]) {
            for (int kk = int(0); kk < int(D); ++kk)
              if (f[l][i][j][num % 10][kk] != -1)
                update(f[l][i][j][k][kk], f[l][i][j][num % 10][kk] + 1);
          } else {
            long long step = p[l - 1] / 9;
            memset(g, -1, sizeof(g));
            memset(_g, -1, sizeof(_g));
            g[num % 10] = step;
            for (int x = int(0); x < int(D); ++x)
              if (g[x] != -1)
                for (int y = int(0); y < int(D); ++y)
                  if (f[l - 1][max(i, j - 1)][9][x][y] != -1)
                    update(_g[y], g[x] + f[l - 1][max(i, j - 1)][9][x][y]);
            if (j > 1) {
              memcpy(g, _g, sizeof(_g));
              memset(_g, -1, sizeof(_g));
              for (int x = int(0); x < int(D); ++x)
                if (g[x] != -1)
                  for (int y = int(0); y < int(D); ++y)
                    if (f[l][i][j - 1][x][y] != -1)
                      update(_g[y], g[x] + f[l][i][j - 1][x][y]);
            }
            memcpy(f[l][i][j][k], _g, sizeof(_g));
          }
        }
  memset(g, -1, sizeof(g));
  g[n % 10] = 0;
  n = n / 10 * 10;
  while (n) {
    for (int l = 1; l != N; ++l)
      if (n / p[l] % 10) {
        int i = getMax(n / p[l] / 10), j = n / p[l] % 10;
        memset(_g, -1, sizeof(_g));
        for (int x = int(0); x < int(D); ++x)
          if (g[x] != -1)
            for (int y = int(0); y < int(D); ++y)
              if (f[l][i][j][x][y] != -1)
                update(_g[y], g[x] + f[l][i][j][x][y]);
        memcpy(g, _g, sizeof(_g));
        n = n - j * p[l];
        break;
      }
  }
  long long ans = -1;
  for (int x = int(0); x < int(D); ++x)
    if (g[x] != -1) update(ans, g[x] + (x > 0));
  cout << ans << endl;
  return 0;
}
