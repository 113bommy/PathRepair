#include <bits/stdc++.h>
using namespace std;
using abu_bakr = int;
long long mull(long long a, long long b, long long m) {
  return ((a % m) * (b % m)) % m;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  while (a != 0 && b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
unsigned long long nCr(int n, int r) {
  if (r > n) return 0;
  r = max(r, n - r);
  unsigned long long ans = 1, div = 1, i = r + 1;
  while (i <= n) {
    ans *= i;
    i++;
    ans /= div;
    div++;
  }
  return ans;
}
void solve() {
  int a, b;
  cin >> a >> b;
  if (!a && !b)
    cout << 0;
  else if (abs(a - b) == 0)
    cout << 1;
  else if (abs(a - b) == 1)
    cout << -1;
  else
    cout << 2;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
