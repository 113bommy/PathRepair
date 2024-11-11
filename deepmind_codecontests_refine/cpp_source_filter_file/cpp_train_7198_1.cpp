#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = ans * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}
const int N = 2e5 + 11;
struct uzi {
  int a, b;
  bool operator<(const uzi &t) const { return -a - t.b < -b - t.a; }
} p[N];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i].a >> p[i].b;
  sort(p + 1, p + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += p[i].a * (i - 1) + p[i].b * (n - i);
  cout << ans << endl;
  return 0;
}
