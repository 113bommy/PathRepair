#include <bits/stdc++.h>
using namespace std;
int fa[100010];
int n, k;
inline int read() {
  int ans = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  return ans;
}
inline bool check(int x) { return (x & (-x)) == x; }
int main() {
  n = read(), k = read();
  int num = max((n - 3) / 2, 0);
  if (k > num) return puts("NO"), 0;
  if (!(n & 1)) return puts("NO"), 0;
  if (n == 9 && k == 2) return puts("NO"), 0;
  if (check(n + 1) && k == 1) return puts("NO"), 0;
  if (!check(n + 1) && !k) return puts("NO"), 0;
  puts("YES");
  int len = max(0, (k + k - 2));
  for (int i = 1; i <= len; i += 2) fa[i + 1] = i, fa[i] = i == 1 ? 0 : i - 2;
  for (int i = 1; i <= n - len; i++)
    if (i == 1)
      fa[i + len] = max(0, len - 1);
    else
      fa[i + len] = (i >> 1) + len;
  if (check(n - len + 1) && k) fa[n - 1] = fa[n] = 2;
  for (int i = 1; i <= n; i++) printf("%d%c", fa[i], i == n ? '\n' : ' ');
}
