#include <bits/stdc++.h>
using namespace std;
int Read() {
  char c;
  while (c = getchar(), (c != '-') && (c < '0' || c > '9'))
    ;
  bool neg = (c == '-');
  int ret = (neg ? 0 : c - 48);
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
  return neg ? -ret : ret;
}
const int MAXN = 50005, MOD = 7 + 1e9;
int cnt[MAXN * 30], c[MAXN * 30][2], d[MAXN * 30][30];
int N, n = 1, a[MAXN], p[MAXN];
long long M, ans;
void init() {
  cin >> N >> M, M += M;
  for (int i = 1; i <= N; i++) {
    a[i] = Read(), p[i] = 1;
    int x = 1;
    for (int j = 29; j >= 0; j--) {
      if (!c[x][((((a[i]) >> (j)) & 1))]) c[x][((((a[i]) >> (j)) & 1))] = ++n;
      x = c[x][((((a[i]) >> (j)) & 1))], ++cnt[x];
      for (int k = j - 1; k >= 0; k--) d[x][k] += ((((a[i]) >> (k)) & 1));
    }
  }
}
void work() {
  int full = 0;
  for (int bit = 29; bit >= 0; bit--) {
    int tmp = 0;
    for (int i = 1; i <= N; i++)
      tmp += cnt[c[p[i]][((((a[i]) >> (bit)) & 1)) ^ 1]];
    if (tmp < M) {
      M -= tmp;
      for (int i = 1; i <= N; i++) {
        if (c[p[i]][((((a[i]) >> (bit)) & 1)) ^ 1]) {
          int y = c[p[i]][((((a[i]) >> (bit)) & 1)) ^ 1];
          ans += (long long)cnt[y] * (full | (1 << bit));
          for (int j = bit - 1; j >= 0; j--)
            ans += ((long long)(((((a[i]) >> (j)) & 1)) ? (cnt[y] - d[y][j])
                                                        : d[y][j])
                    << j);
        }
        p[i] = c[p[i]][((((a[i]) >> (bit)) & 1))];
      }
    } else {
      full |= (1 << bit);
      for (int i = 1; i <= N; i++)
        p[i] = c[p[i]][((((a[i]) >> (bit)) & 1)) ^ 1];
    }
  }
  (ans += M * full) /= 2;
  printf("%d\n", ans % MOD);
}
int main() {
  init();
  work();
  return 0;
}
