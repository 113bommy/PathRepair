#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5, INF = 0x7fffffff;
int n, K;
long long ans;
int p[MAXN];
int cnt[MAXN];
long long sum, add, sub;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    cnt[(p[i] >= i) ? p[i] - i : n - i + p[i]]++;
    sum += abs(p[i] - i);
    if (p[i] <= i)
      add++;
    else
      sub++;
  }
  ans = sum;
  for (int i = 1; i < n; i++) {
    sum += add - sub - 1;
    sum += (p[n - i + 1] - 1) - (n - p[n - i + 1]);
    add += cnt[i] - 1;
    sub -= cnt[i] - 1;
    if (sum < ans) ans = sum, K = i;
  }
  printf("%lld %d\n", ans, K);
  return 0;
}
