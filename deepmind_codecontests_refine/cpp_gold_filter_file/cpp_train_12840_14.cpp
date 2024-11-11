#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = (10e5) + 4;
long long int a[MAXN];
long long int sum[MAXN];
long long int t[MAXN];
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  for (long long int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  if (sum[n] % 3 != 0) {
    cout << 0;
    return 0;
  }
  long long int k = sum[n] / 3;
  for (long long int i = 1; i <= n; i++) {
    t[i] = t[i - 1];
    if (sum[i] == k) t[i]++;
  }
  k *= 2;
  long long int ans = 0;
  for (long long int i = 1; i <= n - 1; i++) {
    if (sum[i] == k) ans += t[i - 1];
  }
  cout << ans;
  return 0;
}
