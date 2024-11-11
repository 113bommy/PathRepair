#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double Pi = acos(-1);
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
double dpow(double a, long long b) {
  double ans = 1.0;
  while (b) {
    if (b % 2) ans = ans * a;
    a = a * a;
    b /= 2;
  }
  return ans;
}
long long quick_pow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = ans * x % mod;
    }
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
int w[maxn];
long long f[maxn];
void upd(int l, int r, int val) {
  f[l] += val;
  f[r + 1] -= val;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 1; i < m; i++) {
    int l = w[i];
    int r = w[i + 1];
    if (l == r) continue;
    if (l > r) swap(l, r);
    upd(1, l - 1, r - l);
    upd(l, l, r - 1);
    upd(l + 1, r - 1, r - l - 1);
    upd(r, r, l);
    upd(r + 1, n, r - l);
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", f[i]);
  }
  printf("\n");
  return 0;
}
