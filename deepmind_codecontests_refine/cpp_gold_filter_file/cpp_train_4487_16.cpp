#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) { return a + b - max(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long arr[200005];
  for (long long i = 1; i <= (2 * n); i++) cin >> arr[i];
  arr[2 * n + 1] = arr[2 * n - n / 2 - 1];
  sort(arr + 1, arr + 2 * n + 1);
  long long ans = 1000000000000000000;
  for (long long i = 2; i <= n; i++) {
    ans = min(ans, (arr[i + n - 1] - arr[i]) * (arr[2 * n] - arr[1]));
  }
  ans = min(ans, (arr[n] - arr[1]) * (arr[2 * n] - arr[n + 1]));
  cout << ans;
}
