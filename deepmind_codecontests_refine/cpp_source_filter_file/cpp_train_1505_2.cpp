#include <bits/stdc++.h>
int _max(int x, int y) { return x > y ? x : y; }
int n;
int f[1002000], dp[1002000], ma[1002000], sec[1002000];
bool Update(int x) {
  int o = dp[x], pos = 0;
  if (ma[f[x]] == dp[x]) pos = 1;
  dp[x] = _max(ma[x], sec[x] + 1);
  if (pos == 0) {
    if (ma[f[x]] <= dp[x])
      sec[f[x]] = ma[f[x]], ma[f[x]] = dp[x];
    else if (sec[f[x]] <= dp[x])
      sec[f[x]] = dp[x];
  } else
    ma[f[x]] = dp[x];
  if (dp[x] == o)
    return 0;
  else
    return 1;
}
void gi(int &x) {
  char ch = getchar();
  x = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
}
void pi(int x) {
  if (x > 9) pi(x / 10);
  putchar(x % 10 + 48);
}
int main() {
  gi(n);
  for (int i = 2; i <= n; i++) {
    gi(f[i]);
    dp[i] = 1;
    if (dp[i] > ma[f[i]])
      sec[f[i]] = ma[f[i]], ma[f[i]] = dp[i];
    else if (dp[i] > sec[f[i]])
      sec[f[i]] = dp[i];
    Update(i);
    for (int j = f[i]; j; j = f[j])
      if (!Update(j)) break;
    pi(ma[1]);
    putchar(' ');
  }
  return 0;
}
