#include <bits/stdc++.h>
using namespace std;
inline long long QpowMod(long long a, long long b, long long M) {
  int ans = 1, base = a;
  while (b) {
    if (b & 1) ans = (ans * base) % M;
    b >>= 1;
    base = (base * base) % M;
  }
  return ans;
}
inline int read() {
  int f = 1, x = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f * x;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int a[100], b[100], c[100];
int mi, ma;
int main() {
  int n;
  int _;
  scanf("%d", &_);
  while (_--) {
    long long ans = 0;
    scanf("%d", &n);
    mi = 1e9 + 5, ma = 1e9 + 5;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      mi = min(a[i], mi);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
      ma = min(a[i], ma);
    }
    for (int i = 1; i <= n; i++) {
      ans += max(a[i] - mi, b[i] - ma);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
