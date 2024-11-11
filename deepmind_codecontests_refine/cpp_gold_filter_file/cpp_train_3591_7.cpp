#include <bits/stdc++.h>
using namespace std;
long long G(long long a, long long b) {
  if (b == 0) return a;
  return G(b, a % b);
}
long long n, m, mx = -1, ans = -1;
long long f(long long a) {
  if (a == m) return 0;
  long long res = (abs(m - a) - 1) / 2;
  if (a < m) res += a - 1;
  if (a > m) res += n - a;
  return res + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  long long k = m;
  for (int i = -5; i < 5 && k + i <= n; i++) {
    if (k + i < 1) continue;
    if (f(k + i) > mx) {
      ans = k + i;
      mx = f(k + i);
    }
  }
  cout << ans;
}
