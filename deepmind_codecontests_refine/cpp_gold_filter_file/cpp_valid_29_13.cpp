#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, r = 0;
  char c = getchar();
  while (!isdigit(c)) f ^= c == '-', c = getchar();
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c & 15), c = getchar();
  return f ? r : -r;
}
const int N = 2e5 + 7, M = 3e5 + 7;
int n, m, a[N];
struct b1t {
  long long c[M];
  inline void add(int p, int x) {
    for (; p <= m; p += ((p) & -(p))) c[p] += x;
  }
  inline long long ask(int p) {
    long long res = 0;
    for (; p; p -= ((p) & -(p))) res += c[p];
    return res;
  }
} T1, T2;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), m = max(m, a[i]);
  long long ans = 0, sum = 0;
  for (int j = 1; j <= n; j++) {
    int x = a[j];
    ans += sum + 1ll * (j - 1) * x - T2.ask(x), sum += x;
    for (int i = x; i <= m; i += x) ans -= x * (j - 1 - T1.ask(i - 1));
    T1.add(x, 1);
    for (int i = x; i <= m; i += x) T2.add(i, x);
    printf("%lld ", ans);
  }
  return 0;
}
