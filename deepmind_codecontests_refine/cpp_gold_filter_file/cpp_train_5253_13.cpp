#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long inf = 1e18 + 1;
long long K;
int n, tot, c[N * 18][4], cnt[20][4][4];
char s[N];
struct matrix {
  long long a[4][4];
  matrix() { memset(a, 0x3f, sizeof(a)); }
  matrix operator*(matrix y) {
    matrix x = *this, z;
    for (int i = (0); i <= (3); i++)
      for (int j = (0); j <= (3); j++) {
        z.a[i][j] = inf;
        for (int k = (0); k <= (3); k++)
          z.a[i][j] = min(z.a[i][j], x.a[i][k] + y.a[k][j]);
      }
    return z;
  }
  matrix operator^(long long p) {
    matrix x = *this, y = *this;
    p--;
    for (; p; p >>= 1, x = x * x)
      if (p & 1) y = y * x;
    return y;
  }
} trs;
bool check(long long x) {
  matrix tmp = trs;
  tmp = tmp ^ x;
  long long res = inf;
  for (int i = (0); i <= (3); i++)
    for (int j = (0); j <= (3); j++) res = min(res, tmp.a[i][j]);
  return res < K;
}
int main() {
  scanf("%lld%s", &K, s + 1);
  n = strlen(s + 1);
  for (int i = (1); i <= (n); i++) {
    int now = 0, a = s[i] - 'A', b;
    for (int j = i; j <= n && j - i <= 18; j++) {
      int b = s[j] - 'A';
      if (!c[now][b]) c[now][b] = ++tot, cnt[j - i][a][b]++;
      now = c[now][b];
    }
  }
  for (int i = (0); i <= (3); i++)
    for (int j = (0); j <= (3); j++) {
      int k = 0;
      for (; cnt[k + 1][i][j] >= (1 << k + k); k++)
        ;
      trs.a[i][j] = k + 1;
    }
  long long l = 1, r = K, mid;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%lld\n", l);
  return 0;
}
