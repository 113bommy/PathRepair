#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const int N = (int)5e5 + 5;
int n, a[N], k, d, dp[N], first[N];
void upd(int R) {
  while (R <= n) {
    first[R]++;
    R |= R + 1;
  }
}
int get(int R) {
  int res = 0;
  while (R >= 0) {
    res += first[R];
    R = (R & (R + 1)) - 1;
  }
  return res;
}
int get(int l, int r) {
  if (l > r) return 0;
  return get(r) - get(l - 1);
}
int main() {
  scanf("%d %d %d", &n, &k, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  int j = 0;
  dp[0] = 1;
  upd(0);
  for (int i = 1; i <= n; i++) {
    while (j <= i && a[i] - a[j] > d) j++;
    dp[i] = get(j - 1, i - k) > 0;
    if (dp[i]) upd(i);
  }
  puts(dp[n] ? "YES" : "NO");
  return 0;
}
