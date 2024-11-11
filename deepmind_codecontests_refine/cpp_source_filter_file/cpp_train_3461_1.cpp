#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
vector<long long int> pre;
long long int fun(long long int n, long long int r) {
  long long int num = pre[n];
  long long int d = (pre[n - r] * pre[r]) % N;
  long long int den = modInverse(d, N);
  long long int ans = (num * den) % N;
  return ans;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << 0 << endl;
    return 0;
  }
  long long int ans = 0;
  pre.resize(n + 1);
  pre[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    pre[i] = (pre[i - 1] * i) % N;
  }
  for (long long int i = 1; i <= k; i++) {
    long long int num = n / i;
    if (num < k) break;
    ans = (ans + fun(num - 1, k - 1)) % N;
  }
  cout << ans << endl;
  return 0;
}
