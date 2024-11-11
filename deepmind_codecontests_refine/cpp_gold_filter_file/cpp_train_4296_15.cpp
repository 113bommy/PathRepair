#include <bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
int n, m, k, cnt, num[105], fa[N], stk[N], top;
template <typename T>
inline T read() {
  T x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * w;
}
bool check(int x) {
  int cnt = 0;
  while (x) cnt += x & 1, x >>= 1;
  return cnt == 1;
}
int main() {
  n = read<int>(), k = read<int>(), m = max((n - 3) / 2, 0);
  if (k > m) return puts("NO"), 0;
  if (n % 2 == 0) return puts("NO"), 0;
  if (n == 9 && k == 2) return puts("NO"), 0;
  if (check(n + 1) && k == 1) return puts("NO"), 0;
  if (!check(n + 1) && !k) return puts("NO"), 0;
  puts("YES");
  int base = max(0, 2 * (k - 1));
  for (int i = 1; i <= base; i += 2) fa[i + 1] = i, fa[i] = max(0, i - 2);
  for (int i = 1; i <= n - base; i++) {
    if (i == 1)
      fa[i + base] = max(0, base - 1);
    else
      fa[i + base] = (i >> 1) + base;
  }
  if (check(n - base + 1) && k) fa[n - 1] = fa[n] = 2;
  for (int i = 1; i <= n; i++) printf("%d%c", fa[i], i == n ? '\n' : ' ');
  return 0;
}
