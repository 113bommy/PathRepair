#include <bits/stdc++.h>
using namespace std;
long long fpow(long long x, long long y, long long p = 1000000007) {
  x = x % p;
  long long sum = 1;
  while (y) {
    if (y & 1) sum = sum * x;
    sum %= p;
    y = y >> 1;
    x = x * x;
    x %= p;
  }
  return sum;
}
long long modmul(long long x, long long y) { return (x * y) % 1000000007; }
long long modadd(long long x, long long y) { return (x + y) % 1000000007; }
long long modsub(long long x, long long y) {
  return (x - y + 1000000007) % 1000000007;
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  int o = 0, e = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2)
      o++;
    else
      e++;
  }
  if (o % 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
