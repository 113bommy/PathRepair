#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N], n, k, ans, lst, b[N], cnt;
inline void fr(int &num) {
  num = 0;
  char c = getchar();
  int p = 1;
  while (c < '0' || c > '9') c == '-' ? p = -1, c = getchar() : c = getchar();
  while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
  num *= p;
}
int main() {
  fr(n), fr(k);
  for (register int i = 1; i <= n; ++i) {
    fr(a[i]);
    if (a[i] < 0) {
      if (lst) b[++cnt] = i - lst - 1;
      ++ans, lst = i;
    }
  }
  if (ans > k) return puts("-1"), 0;
  k -= ans, ans <<= 1;
  sort(b + 1, b + 1 + cnt);
  register int fl = -1;
  for (register int i = 1; i <= cnt; ++i) {
    if (k < b[i]) break;
    k -= b[i], ans -= 2;
  }
  if (n - lst <= k) --ans;
  printf("%d", ans);
  return 0;
}
