#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, h, t;
long long c;
int q[N];
long long dp[N], s[N], v[N];
int main() {
  scanf("%d%I64d", &n, &c);
  for (int i = 1; i < n + n; i++) {
    scanf("%I64d", &s[i]);
    s[i] += s[i - 1];
  }
  int j = 0;
  h = 1;
  t = 1;
  q[1] = 0;
  for (int i = 1; i <= n; i++) {
    while (s[i + i - 1] - s[j + j] > c && j < i) {
      if (q[h] == j && h <= t) h++;
      j++;
    }
    if (j > 0) dp[i] = dp[j - 1] + c;
    if (h <= t) dp[i] = max(dp[i], v[q[h]] + s[i + i - 1]);
    v[i] = dp[i] - s[i + i];
    while (h <= t && v[i] > v[q[t]]) t--;
    q[++t] = i;
  }
  printf("%I64d\n", dp[n]);
  return 0;
}
