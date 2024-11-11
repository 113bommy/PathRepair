#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 5;
pair<long long, long long> arr[N];
long long l[N];
long long s[N];
long long dp[N];
long long bit[N];
long long n;
void update(long long idx, long long val) {
  while (idx <= n) {
    bit[idx] = max(bit[idx], val);
    idx += idx & -idx;
  }
}
long long query(long long idx) {
  long long res = 0;
  while (idx) {
    res = max(res, bit[idx]);
    idx -= idx & -idx;
  }
  return res;
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long r, h;
    scanf("%lld%lld", &r, &h);
    arr[i] = pair<long long, long long>(r * r * h, i);
  }
  sort(arr + 1, arr + n + 1);
  for (long long i = 1; i <= n; i++) {
    dp[i] = max(arr[i].first, query(arr[i].second) + arr[i].first);
    update(arr[i].second, dp[i]);
  }
  printf("%.7f\n", 3.14159265358979323846 * query(n));
  return 0;
}
