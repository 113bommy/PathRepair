#include <bits/stdc++.h>
using namespace std;
long long a[1005];
long long b[2005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, p;
  cin >> n >> k >> p;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= k; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + 1 + k);
  long long ans = 100000000000000;
  for (long long i = 1; i <= k - n + 1; i++) {
    long long s = 0;
    for (long long j = 1; j <= n; j++) {
      s = max(abs(a[j] - b[i + j - 1]) + abs(p - b[i + j - 1]), s);
    }
    ans = min(ans, s);
  }
  cout << ans;
}
