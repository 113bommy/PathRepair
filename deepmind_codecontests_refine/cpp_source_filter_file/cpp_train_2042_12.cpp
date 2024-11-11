#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 16;
int n, x, y;
int arr[N];
int cnt[N];
bool prime[N];
long long sum[N];
long long solve(int k) {
  long long ans = 0;
  int d = min(k - 1, x / y);
  for (long long i = k; i < N; i += k) {
    ans += (long long)x * (cnt[i - d - 1] - cnt[i - k]);
    long long need = i * (cnt[i - 1] - cnt[i - d - 1]);
    ans += (long long)y * (need - (sum[i - 1] - sum[i - d - 1]));
  }
  return ans;
}
int main() {
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    cnt[arr[i]]++;
    sum[arr[i]] += arr[i];
  }
  for (int i = 1; i < N; i++) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  long long ans = 2e18 + 16;
  memset(prime, 1, sizeof prime);
  for (long long i = 2; i < N; i++) {
    if (prime[i]) {
      ans = min(ans, solve(i));
      for (long long j = i * i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
