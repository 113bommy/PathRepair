#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1000 * 100 + 100;
int gcd(int a, int b) {
  if (!a) return b;
  return gcd(b % a, a);
}
int a[MAXN], n, cnt, pr[MAXN], coun[MAXN], m, gcd_;
long long ans;
int used[32258070];
int get_gcd() {
  int res = a[1] - 1;
  for (int i = 2; i <= n; i++)
    res = gcd(min(res, a[i] - 1), max(res, a[i] - 1));
  return res;
}
void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void calc(long long x) {
  while (x <= m) {
    ans += m - x + 0ll;
    x *= 2ll;
  }
}
void solve() {
  gcd_ = get_gcd();
  while (gcd_ % 2 == 0 && gcd != 0) gcd_ /= 2;
  for (int i = 1; i <= sqrt(gcd_); i++)
    if (gcd_ % i == 0) {
      calc(i + 0ll);
      if (gcd_ / i != i) calc(gcd_ / i + 0ll);
    }
}
void write() { cout << ans; }
int main() {
  read();
  solve();
  write();
}
