#include <bits/stdc++.h>
using namespace std;
const int SZ = 1000010;
const int INF = 1000000010;
long long num[SZ], sum[SZ];
map<long long, int> mp;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &num[i]), num[i + n] = num[i];
  for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + num[i];
  for (int i = 2; i <= n + 1; i++) mp[sum[i]]++;
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, n - mp[sum[i]]);
    mp[sum[i + 1]]--;
    mp[sum[i + 1 + n]]++;
  }
  printf("%d\n", ans);
  return 0;
}
