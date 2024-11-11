#include <bits/stdc++.h>
using namespace std;
long long int n, a[1000010], inv[1000010], s[1000010];
long long int pw(long long int k, long long int x) {
  if (x == 0) return 1;
  if (x == 1) return k;
  if (x % 2) {
    long long int tmp = pw(k, x / 2);
    return tmp * ((tmp * k) % 1000000007) % 1000000007;
  } else {
    long long int tmp = pw(k, x / 2);
    return (tmp * tmp) % 1000000007;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long int tmp = 1;
  for (long long int i = 1; i <= n; i++) tmp = (tmp * i) % 1000000007;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1])
      s[i] = i;
    else
      s[i] = s[i - 1];
  }
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) inv[i] = pw(i, 1000000007 - 2);
  for (int i = 0; i < n; i++) {
    if (a[i] == a[n - 1]) break;
    ans = ans + (((tmp * a[i]) % 1000000007) * inv[n - s[i]]) % 1000000007;
  }
  cout << ans << '\n';
  return 0;
}
