#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, a[N], mn = N, pos, ans, sum, x = 1, y = 1;
int sta[N], top = 0, lb[N], rb[N], fa[N], d[N], idx;
char s[N], t[N];
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = (1); i <= (n); i++) {
    sum += s[i] == '(' ? 1 : -1;
    if (mn > sum) mn = sum, pos = i;
  }
  if (sum) {
    puts("0\n1 1");
    return 0;
  }
  for (int i = (pos + 1); i <= (n); i++) t[i - pos] = s[i];
  for (int i = (1); i <= (pos - 1); i++) t[n - pos + i] = s[i];
  swap(s, t);
  for (int i = (1); i <= (n); i++) {
    if (s[i] == '(')
      sta[++top] = ++idx, lb[idx] = i;
    else
      rb[sta[top]] = i, fa[sta[top]] = sta[top - 1], --top, ++d[sta[top]];
  }
  ans = d[0];
  for (int i = (1); i <= (idx); i++) {
    if (d[i] + 1 > ans && fa[i] == 0)
      ans = d[i] + 1, x = lb[i] + pos, y = rb[i] + pos;
    if (d[0] + d[i] + 1 > ans && fa[i] && fa[fa[i]] == 0)
      ans = d[0] + d[i] + 1, x = lb[i] + pos, y = rb[i] + pos;
  }
  if (x > n) x -= n;
  if (y > n) y -= n;
  printf("%d\n%d %d\n", ans, x, y);
  return 0;
}
