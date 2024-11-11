#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
const long long inf = 0x7F7F7F7F7F7F;
int n, a, b;
long long f[200005][2];
char s[200005];
long long Min(long long x, long long y) { return x < y ? x : y; }
int main() {
  int t = read();
  while (t--) {
    n = read();
    a = read();
    b = read();
    scanf("%s", s + 1);
    f[0][0] = b;
    f[0][1] = inf;
    for (int i = 1; i <= n - 1; ++i) {
      if (s[i] == '0' && s[i + 1] == '0') {
        f[i][1] = a + b + b;
        f[i][0] = a + b;
        f[i][0] += Min(f[i - 1][1] + a, f[i - 1][0]);
        f[i][1] += Min(f[i - 1][0] + a, f[i - 1][1]);
      } else {
        f[i][1] = a + b + b;
        f[i][0] = inf;
        f[i][1] += Min(f[i - 1][0] + a, f[i - 1][1]);
      }
    }
    f[n][0] = a + b + Min(f[n - 1][0], f[n - 1][1] + a);
    printf("%I64d\n", f[n][0]);
  }
  return 0;
}
