#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  while (ch != 45 && (ch > '9' || ch < '0')) ch = getchar();
  if (ch == 45) {
    f = -1, ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
void cmin(long long &a, long long b) { a = min(a, b); }
void cmax(long long &a, long long b) { a = max(a, b); }
long long i, j, k, n, s, t, m;
signed main() {
  read(t);
  while (t--) {
    read(s), read(n), read(k);
    if (k > s) {
      printf("NO\n");
      continue;
    }
    if (k == s) {
      printf("YES\n");
      continue;
    }
    long long need = n / k * 2 * k + n % k;
    if (s >= need) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
  }
  return 0;
}
