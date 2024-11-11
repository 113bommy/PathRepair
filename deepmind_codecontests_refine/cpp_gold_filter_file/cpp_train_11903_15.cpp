#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;
long long sum[maxn];
char s[maxn];
int main() {
  int k;
  scanf("%d", &k);
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++) {
    sum[i] = sum[i - 1];
    if (s[i] == '1') sum[i] += 1;
  }
  long long ans = 0;
  for (int i = 1; i <= len; i++) {
    if (sum[i] >= k) {
      long long st = lower_bound(sum, sum + i, sum[i] - k) - sum;
      long long ed = upper_bound(sum, sum + i, sum[i] - k) - sum;
      ans += ed - st;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
