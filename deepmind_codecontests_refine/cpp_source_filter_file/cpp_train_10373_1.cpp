#include <bits/stdc++.h>
using namespace std;
long long v[1010];
int f[1010][1010];
long long calc(int x) {
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= i; j++)
      f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * j) % 1000000007;
  long long ret = 0;
  for (int i = 1; i <= x; i++) (ret += f[x][i]) %= 1000000007;
  return ret;
}
int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int val;
      scanf("%1d", &val);
      v[j] <<= 1;
      v[j] |= val;
    }
  sort(v + 1, v + m + 1);
  int cnt = 1;
  long long ans = 1;
  for (int i = 2; i <= m; i++)
    if (v[i] == v[i - 1])
      cnt++;
    else {
      (ans *= calc(cnt)) %= 1000000007;
      cnt = 1;
    }
  (ans *= calc(cnt)) %= 1000000007;
  printf("%I64d\n", ans);
  return 0;
}
