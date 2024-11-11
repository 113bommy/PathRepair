#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return;
}
inline void outi(int x) {
  if (x > 9) outi(x / 10);
  putchar(x % 10 + '0');
}
inline void outl(long long x) {
  if (x > 9) outl(x / 10);
  putchar(x % 10 + '0');
}
const int maxn = 3e3 + 10;
int a[maxn] = {0}, cnt[maxn * maxn];
int main() {
  int t;
  read(t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i - 2; j++) cnt[a[j] * maxn + a[i - 1]]++;
      for (int j = i + 1; j <= n; j++) {
        ans += cnt[a[i] * maxn + a[j]];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
