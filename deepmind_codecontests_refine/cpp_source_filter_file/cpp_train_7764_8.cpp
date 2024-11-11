#include <bits/stdc++.h>
char str[100010], command[100010];
int get_path(long long v, long long n) {
  int len = 0;
  while (1) {
    long long m = (n + 1) >> 1;
    if (v == m) break;
    if (v < m)
      str[len++] = 'L';
    else
      str[len++] = 'R', v -= m;
    n >>= 1;
  }
  str[len] = 0;
  return len;
}
long long encode(const char* str, long long n) {
  int i;
  n = (n + 1) >> 1;
  long long res = n;
  for (i = 0; str[i] != 0; i++) {
    n >>= 1;
    if (str[i] == 'L')
      res -= n;
    else
      res += n;
  }
  return res;
}
int main() {
  int q, i, j, l, len;
  long long n, k, u, x, y, res;
  while (scanf("%lld %d", &n, &q) != EOF) {
    l = __builtin_popcountll(n);
    while (q--) {
      scanf("%lld", &u);
      scanf("%s", command);
      len = get_path(u, n);
      for (i = 0; command[i]; i++) {
        if (command[i] == 'U') {
          if (len) str[--len] = 0;
        } else if (len != l) {
          str[len++] = command[i];
          str[len] = 0;
        }
      }
      printf("%lld\n", encode(str, n));
    }
  }
  return 0;
}
