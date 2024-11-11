#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007, m = 1000000;
int n, f[m + 10], two[m + 10], ans;
void work() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), f[x]++;
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < m; j++)
      if (j & (1 << i)) f[j ^ (1 << i)] += f[j];
  two[0] = 1;
  for (int i = 1; i <= n; i++) two[i] = (two[i - 1] << 1) % mo;
  for (int i = 0; i < m; i++) {
    int x = i, p = 0;
    while (x) p += x & 1, x >>= 1;
    if (p & 1)
      ans = (ans - two[f[i]] + mo) % mo;
    else
      ans = (ans + two[f[i]]) % mo;
  }
  printf("%d", ans);
}
int main() {
  work();
  return 0;
}
