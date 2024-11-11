#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, p, q, r;
  cin >> n >> p >> q >> r;
  long long int a[n], ans = INT_MIN;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int prefixMax[n], suffixMax[n];
  prefixMax[0] = p * a[0];
  suffixMax[n - 1] = r * a[n - 1];
  for (long long int i = 1; i < n; i++)
    prefixMax[i] = max(prefixMax[i - 1], p * a[i]);
  for (long long int i = n - 2; i >= 0; i--)
    suffixMax[i] = max(suffixMax[i + 1], r * a[i]);
  for (long long int i = 0; i < n; i++) {
    ans = max(ans, prefixMax[i] + suffixMax[i] + (q * a[i]));
  }
  cout << ans << endl;
  return 0;
}
