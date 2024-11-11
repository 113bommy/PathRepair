#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
int s[1000005][3], p2[1000005], g[1000005];
void fmain(int tid) {
  scanf("%d", &n);
  p2[0] = 1;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int x;
    scanf("%d", &x);
    addmod(s[x][0], 1);
    addmod(s[x][1], x);
    addmod(s[x][2], (long long)x * x % 1000000007);
    p2[i] = p2[i - 1] * 2 % 1000000007;
  }
  for (int x = 1; x <= 100000; x *= 10) {
    for (int i = 999999; i >= 0; i--)
      if (i / x % 10 != 0) {
        for (int(j) = 0; (j) < (int)(3); (j)++) addmod(s[i - x][j], s[i][j]);
      }
  }
  for (int(i) = 0; (i) < (int)(1e6); (i)++) {
    if (s[i][0] == 1) {
      addmod(g[i], s[i][2]);
    } else if (s[i][0] > 1) {
      addmod(g[i], ((long long)s[i][1] * s[i][1] % 1000000007 + s[i][2]) %
                       1000000007 * p2[s[i][0] - 2] % 1000000007);
    }
  }
  for (int x = 1; x <= 100000; x *= 10) {
    for (int(i) = 0; (i) < (int)(1e6); (i)++)
      if (i / x % 10 != 9) {
        addmod(g[i], 1000000007 - g[i + x]);
      }
  }
  long long ans = 0;
  for (int(i) = 0; (i) < (int)(1e6); (i)++)
    if (g[i] != 0) {
      ans ^= (long long)i * g[i];
    }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
