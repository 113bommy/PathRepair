#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7, oo = 1e9;
const ll loo = 1e18;
ll modpow(ll a, ll b) {
  ll ans = 1;
  for (; b; b /= 2, a = a * a % mod)
    if (b & 1) ans = (ans * a) % mod;
  return ans;
}
ll gcd(ll a, ll b) {
  while (a) b %= a, swap(a, b);
  return b;
}
const bool DEBUG = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  n *= 2;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  auto cmp = [&](int i, int j) { return a[i] < a[j]; };
  int b[n];
  for (int i = 0; i < n; i++) b[i] = i;
  sort(b, b + n, cmp);
  int ans[n];
  for (int i = 0; i < n; i++) ans[i] = -1;
  for (int i = 0; i < n; i++) {
    int k = i;
    while (k < n && a[b[k]] == a[b[i]]) k++;
    if (k - i >= 2) {
      ans[b[i]] = 1;
      ans[b[i + 1]] = 2;
    }
    i = k - 1;
  }
  int c = 0;
  for (int i = n - 1; i >= 0; i--)
    if (ans[b[i]] == -1)
      if ((i || a[b[i]] != a[b[i] - 1]) &&
          (i == n - 1 || a[b[i]] != a[b[i + 1]]))
        ans[b[i]] = 1 + c, c ^= 1;
  c = n / 2;
  for (int i = 0; i < n; i++)
    if (ans[i] == 2) c--;
  for (int i = 0; i < n; i++)
    if (ans[i] == -1) ans[i] = 1 + (c-- > 0);
  set<int> x, y;
  for (int i = 0; i < n; i++)
    if (ans[i] == 1)
      x.insert(a[i]);
    else
      y.insert(a[i]);
  stringstream ss;
  ss << 1LL * x.size() * y.size() << endl;
  for (int i = 0; i < n; i++) ss << ans[i] << " ";
  cout << ss.str() << endl;
  return 0;
}
