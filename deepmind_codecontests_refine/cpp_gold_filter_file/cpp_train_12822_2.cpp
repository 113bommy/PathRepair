#include <bits/stdc++.h>
using namespace std;
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void show_vec(int64_t v[], int64_t n) {
  for (int64_t i = 0; i < n; i++) cout << v[i] << " ";
  cout << "\n";
}
void inp_vec(vector<int64_t> &v, int64_t n) {
  for (int64_t i = 0; i < n; i++) cin >> v[i];
}
bool check_prime(int64_t n) {
  if (n <= 1) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int64_t i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
void solve() {
  int64_t n, m, k, i, ans = 0, y, x = 0;
  cin >> n >> m >> k;
  vector<int64_t> v(m);
  for (i = 0; i < m; i++) cin >> v[i];
  y = ceil(v[0] * 1.0 / k) * k;
  while (x < m) {
    int64_t cnt = 0;
    while (x < m && v[x] <= y) {
      x++;
      cnt++;
    }
    if (cnt == 0)
      y += (k * ((v[x] - y + k - 1) / k));
    else {
      ans++;
      y += cnt;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int64_t t = 1;
  while (t--) solve();
  return 0;
}
