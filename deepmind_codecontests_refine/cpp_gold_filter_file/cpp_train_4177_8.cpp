#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 1, MOD = 998244353;
long long n, a[300000], even, odd, ans;
int main() {
  cin >> n;
  for (long long i = 0LL; i < n; i++) {
    scanf("%I64d", &a[i]);
    long long b = 0LL;
    while (a[i]) {
      b += a[i] % 2LL;
      a[i] /= 2LL;
    }
    a[i] = b;
    if (b % 2LL) {
      swap(even, odd);
      odd++;
    } else
      even++;
    ans += even;
    if (b % 2LL == 0LL) ans--;
    long long mx = a[i], sum = a[i];
    for (long long j = i - 1; j >= max(0LL, i - 100); j--) {
      sum += a[j];
      mx = max(a[j], mx);
      if (sum - mx < mx && sum % 2LL == 0LL) ans--;
    }
  }
  cout << ans;
}
