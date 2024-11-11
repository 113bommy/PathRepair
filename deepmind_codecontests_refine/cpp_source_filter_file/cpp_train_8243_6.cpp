#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n;
long long f(long long m) {
  int pre = 0;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    pre += a[i] % m;
    pre %= m;
    res += min(1ll * pre, m - pre);
  }
  return res;
}
int main() {
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  if (sum == 1) {
    cout << "-1";
    return 0;
  }
  long long ans = 1e18;
  for (long long i = 2; i * i <= sum; i++) {
    if (sum % i == 0) {
      ans = min(ans, f(i));
      while (sum % i == 0) sum /= i;
    }
  }
  if (sum != 1) ans = min(ans, f(sum));
  cout << ans;
  return 0;
}
