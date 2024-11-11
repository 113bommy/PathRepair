#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 5;
const long long inf = 1e10;
const long long mod = 1e9 + 7;
long long n, x, y;
long long t;
long long cnt[maxN];
long long sum[maxN];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> x >> y;
  for (long long i = 1; i <= n; i++) {
    cin >> t;
    cnt[t]++;
    sum[t] += t;
  }
  for (long long i = 1; i <= 200000; i++) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  long long limit = x / y;
  long long res = n * x;
  for (long long i = 2; i <= 100000; i++) {
    long long ans = 0;
    for (long long j = i; j <= i + 100000; j += i) {
      long long f = max(j - i + 1, j - limit);
      ans += (cnt[f - 1] - cnt[j - i]) * x;
      ans += ((cnt[j] - cnt[f - 1]) * j - (sum[j] - sum[f - 1])) * y;
    }
    res = min(ans, res);
  }
  cout << res;
  return 0;
}
