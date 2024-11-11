#include <bits/stdc++.h>
using namespace std;
long long powM(long long a, long long b, long long m) {
  long long ans = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}
int main() {
  long long n, k, i, j, ans = 0, d;
  cin >> d >> n;
  long long arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  for (i = 1; i < n; i++) ans += d - arr[i];
  cout << ans << "\n";
  return 0;
}
