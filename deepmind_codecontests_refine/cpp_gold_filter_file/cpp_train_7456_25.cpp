#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
void qread(int &x) {
  int neg = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = 10 * x + c - '0', c = getchar();
  x *= neg;
}
const int maxn = 1000005;
int n;
string s;
int a[maxn], alen, b[maxn], blen;
int sum[maxn], dp[maxn];
char c[maxn];
bool valid(int l, int r) {
  if (l > r) return true;
  return sum[r] - (!l ? 0 : sum[l - 1]) == 0;
}
bool check(int d) {
  dp[0] = -1;
  for (int(i) = 0; (i) < alen; i++) {
    dp[i + 1] = -1;
    if (valid(dp[i] + 1, a[i] - d - 1)) dp[i + 1] = max(dp[i + 1], a[i]);
    if (i >= 1 && valid(dp[i - 1] + 1, a[i] - d - 1))
      dp[i + 1] = max(dp[i + 1], a[i - 1] + d);
    if (valid(dp[i] + 1, a[i] - 1)) dp[i + 1] = max(dp[i + 1], a[i] + d);
  }
  return valid(dp[alen] + 1, n - 1);
}
int main() {
  scanf("%d%s", &n, c);
  s = c;
  for (int(i) = 0; (i) < n; i++) {
    if (s[i] == 'P')
      a[alen++] = i;
    else if (s[i] == '*')
      b[blen++] = i;
    sum[i] = (!i ? 0 : sum[i - 1]) + (s[i] == '*');
  }
  if (alen == 1) {
    int l = sum[a[0]], r = sum[n - 1] - sum[a[0]];
    if (l < r)
      printf("%d %d\n", r, b[blen - 1] - a[0]);
    else if (l > r)
      printf("%d %d\n", l, a[0] - b[0]);
    else
      printf("%d %d\n", l, min(b[blen - 1] - a[0], a[0] - b[0]));
    return 0;
  }
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%d %d\n", blen, r);
  return 0;
}
