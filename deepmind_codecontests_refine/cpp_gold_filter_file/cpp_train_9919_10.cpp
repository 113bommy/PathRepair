#include <bits/stdc++.h>
using namespace std;
long long modex(long long a, long long b) {
  long long ans = 1;
  a %= 1000000007;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 1000000007;
    b = b >> 1;
    a = (a * a) % 1000000007;
  }
  return ans;
}
long long modex1(long long a, long long b) {
  long long ans = 1;
  a %= 998244353;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 998244353;
    b = b >> 1;
    a = (a * a) % 998244353;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  int n, x;
  cin >> n >> x;
  if (n <= 2)
    cout << 1 << "\n";
  else {
    n -= 2;
    int t = (n - 1) / x + 2;
    cout << t << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) solve();
}
