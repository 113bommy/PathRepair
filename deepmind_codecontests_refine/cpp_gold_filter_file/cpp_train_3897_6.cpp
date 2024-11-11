#include <bits/stdc++.h>
using namespace std;
const int maxn = 4000100;
const long long inf = 1e18;
long long n, k, arr[maxn];
long long dp[maxn], cnt[maxn];
long long f(long long cost) {
  long long maxdp = -inf;
  long long mincnt = 0;
  dp[0] = cnt[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    cnt[i] = cnt[i - 1];
    for (int j = i - 1; j >= 1; j--) {
      if (dp[i] < dp[j - 1] - arr[j] + arr[i] - cost) {
        dp[i] = dp[j - 1] - arr[j] + arr[i] - cost;
        cnt[i] = cnt[j - 1] + 1;
      } else if (dp[i] == dp[j - 1] - arr[j] + arr[i] - cost) {
        cnt[i] = min(cnt[i], cnt[j - 1] + 1);
      }
    }
  }
  return cnt[n];
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  long long index = -1;
  for (long long cekor = inf / 2; cekor > 0; cekor /= 2) {
    while (index + cekor < inf && f(index + cekor) > k) index += cekor;
  }
  index++;
  f(index);
  cout << dp[n] + k * index << "\n";
}
