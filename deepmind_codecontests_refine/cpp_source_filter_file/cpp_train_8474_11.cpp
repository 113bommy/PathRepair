#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int MOD = 7;
const double EPS = 1e-7;
char s[100010];
int n, x, sum[100010];
int vis[100010];
int check(int y) {
  if (y == 0) {
    if (x == 0)
      return n * (n - 1) / 2;
    else
      return 0;
  }
  if (x < y || x % y) return 0;
  int k = x / y;
  if (k <= sum[n]) return vis[k];
  return 0;
}
int main() {
  scanf("%d", &x);
  scanf("%s", s);
  n = strlen(s);
  for (int i = 1; i <= n; i++) sum[i] = (s[i - 1] - '0') + sum[i - 1];
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) vis[sum[j] - sum[i - 1]]++;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) ans += check(sum[j] - sum[i - 1]);
  printf("%I64d\n", ans);
  return 0;
}
