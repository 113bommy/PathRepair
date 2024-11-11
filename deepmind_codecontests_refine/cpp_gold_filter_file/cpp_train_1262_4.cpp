#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, cnt;
long long a[maxn];
inline int read() {
  int ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57) {
    ret = ret * 10 + ch - 48;
    ch = getchar();
  }
  return ret * f;
}
long long work(long long x) { return (long long)(n - x + 2) * (n / x) / 2; }
int main() {
  n = read();
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i) continue;
    a[++cnt] = work(i);
    a[++cnt] = work(n / i);
  }
  sort(a + 1, a + 1 + cnt);
  for (int i = 1; i <= cnt; i++)
    if (a[i] != a[i - 1]) printf("%lld ", a[i]);
  return 0;
}
