#include <bits/stdc++.h>
using namespace std;
int n, t, tt, sz, res = 1e9, a[55][100005], out[100005], cnt[100005],
                  mul[100005], que[1000005];
int read() {
  int x = 0, fl = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fl = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * fl;
}
int check(int p, int len) {
  for (int i = 1; i <= len; i++)
    if (a[p][i]) return 0;
  return 1;
}
void dfs(int dep, int sum, int len) {
  if (sum > res || dep > 34) return;
  int now = check(dep, len);
  if (now) {
    res = sum;
    for (int i = 1; i <= t; i++) que[i] = cnt[i];
    sz = t;
    return;
  }
  int fl = 1;
  for (int i = 1; i <= len; i++)
    if (a[dep][i] % 2) fl = 0;
  if (fl) {
    cnt[++t] = 3;
    for (int i = 1; i <= len; i++) a[dep + 1][i] = a[dep][i] / 2;
    int l0 = unique(a[dep + 1] + 1, a[dep + 1] + len + 1) - a[dep + 1] - 1;
    dfs(dep + 1, sum, l0);
    t--;
  } else {
    cnt[++t] = 1;
    for (int i = 1; i <= len; i++)
      a[dep + 1][i] = a[dep][i] + ((a[dep][i] & 1) > 0);
    int l0 = unique(a[dep + 1] + 1, a[dep + 1] + len + 1) - a[dep + 1] - 1;
    dfs(dep + 1, sum + 1, l0);
    t--;
    cnt[++t] = 2;
    for (int i = 1; i <= len; i++)
      a[dep + 1][i] = a[dep][i] - ((a[dep][i] & 1) > 0);
    l0 = unique(a[dep + 1] + 1, a[dep + 1] + len + 1) - a[dep + 1] - 1;
    dfs(dep + 1, sum + 1, l0);
    t--;
  }
  return;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[0][i] = read();
  sort(a[0] + 1, a[0] + n + 1);
  dfs(0, 0, n);
  printf("%d\n", res);
  for (int i = 1; i <= sz; i++) mul[i] = mul[i - 1] + (que[i] == 3);
  for (int i = 1; i <= sz; i++) {
    if (que[i] == 1)
      out[++tt] = -1 * pow(2, mul[i]);
    else if (que[i] == 2)
      out[++tt] = pow(2, mul[i]);
  }
  for (int i = 1; i <= tt; i++) printf("%d ", out[i]);
  puts("");
  return 0;
}
