#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6;
const long long mod = 998244353;
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n + 1];
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long i = 1, j = n;
    while ((i <= n) && (a[i] <= k)) i++;
    while ((j >= 1) && (a[j] <= k)) j--;
    if (j <= i)
      cout << n;
    else
      cout << (i - 1 + (n - j));
  }
  return 0;
}
