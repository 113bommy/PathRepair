#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int neg = 1, num = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') neg = -1;
  for (; isdigit(c); c = getchar()) num = (num << 1) + (num << 3) + c - '0';
  return neg * num;
}
int n, x[1100010], sum[1100010], f[1100010], cnt = 0;
char s[1100010];
inline bool none(int l, int r) { return l > r || sum[l - 1] == sum[r]; }
inline void Update(int &a, int b) {
  if (a < b) a = b;
}
inline bool check(int t) {
  for (int i = 0; i <= cnt; i++) f[i] = 0;
  for (int i = 1; i <= cnt; i++) {
    if (none(f[i] + 1, x[i] - t - 1)) Update(f[i + 1], x[i]);
    if (none(f[i] + 1, x[i] - 1)) Update(f[i + 1], x[i] + t);
    if (i > 1 && none(f[i - 1] + 1, x[i] - t - 1))
      Update(f[i + 1], x[i - 1] + t);
  }
  return none(f[cnt + 1] + 1, n);
}
int main() {
  scanf("%d%s", &n, s + 1);
  int pos = -1;
  for (int i = 1; i <= n; i++)
    if (s[i] == 'P') pos = x[++cnt] = i;
  if (cnt == 1) {
    int L = 0, R = 0, lpos = -1, rpos = -1;
    for (int i = pos - 1; i; i--)
      if (s[i] == '*') L++, lpos = i;
    for (int i = pos + 1; i <= n; i++)
      if (s[i] == '*') R++, rpos = i;
    if (L != R)
      printf("%d %d\n", max(L, R), L > R ? pos - lpos : rpos - pos);
    else
      printf("%d %d\n", L, min(pos - lpos, rpos - pos));
    exit(0);
  }
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] == '*');
  int l = 0, r = n, ans = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%d %d\n", sum[n], ans);
  return 0;
}
