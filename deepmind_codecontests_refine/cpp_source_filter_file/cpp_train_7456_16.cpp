#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0, pos, suf[1000010], tot = 0;
char c[1000010];
bool f[1000010];
int gi() {
  int w = 0, f = 1;
  char ch;
  while (!isdigit(ch)) {
    f = ch == '-' ? -1 : 1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    w = (w << 1) + (w << 3) + ch - 48;
    ch = getchar();
  }
  return w * f;
}
bool check(int x) {
  memset(f, 0, sizeof(f));
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (f[i - 1]) {
      if (c[i] == '.') f[i] = 1;
      if (c[i] == 'D') f[min(min(i + x, n), suf[i] - 1)] = 1;
      if (c[i] == 'B') {
        if (suf[i] <= i + x) f[suf[i]] = 1;
        if (suf[suf[i]] <= i + x)
          f[min(min(suf[i] + x, n), suf[suf[suf[i]]] - 1)] = 1;
      }
    }
  }
  return f[n];
}
int main() {
  n = gi();
  scanf("%s", c + 1);
  for (int i = 1; i <= n; i++) {
    if (c[i] == 'D') cnt++, pos = i;
    if (c[i] == 'B') tot++;
  }
  if (cnt == 1) {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < pos; i++)
      if (c[i] == 'B') sum1++;
    for (int i = pos + 1; i <= n; i++)
      if (c[i] == 'B') sum2++;
    int tmp1 = 0, tmp2 = 0;
    for (int i = 1; i < pos; i++)
      if (c[i] == 'B') {
        tmp1 = i;
        break;
      }
    for (int i = n; i > pos; i--)
      if (c[i] == 'B') {
        tmp2 = i;
        break;
      }
    if (sum1 > sum2)
      printf("%d %d\n", sum1, pos - tmp1);
    else if (sum2 > sum1)
      printf("%d %d\n", sum2, tmp2 - pos);
    else
      printf("%d %d\n", sum1, min(pos - tmp1, tmp2 - pos));
    return 0;
  }
  int tmp = n + 1;
  for (int i = n; i >= 1; i--) {
    suf[i] = tmp;
    if (c[i] == 'D') tmp = i;
  }
  int l = 0, r = 2 * n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d %d\n", tot, l);
}
