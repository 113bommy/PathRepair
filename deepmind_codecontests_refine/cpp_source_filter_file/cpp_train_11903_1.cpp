#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using pill = pair<int, ll>;
using vvi = vector<vi>;
ll gcd(ll a, ll b) {
  ll t;
  while ((t = a % b) != 0) {
    a = b;
    b = t;
  }
  return b;
}
ll fast_exp(ll base, ll n, ll m) {
  if (n == 0) return 1;
  ll t = fast_exp(base, n / 2, m);
  if (n % 2 == 0)
    return (t * t) % m;
  else
    return (((t * t) % m) * base) % m;
}
bool is_set(int i, ll mask) { return (mask >> i) & 1; }
int count_bits(ll mask) {
  int ans = 0;
  for (int i = 0; i < 64; ++i)
    if (is_set(i, mask)) ++ans;
  return ans;
}
int first_bit(ll mask) {
  int i = 0;
  while (i < 64)
    if (is_set(i++, mask)) return i - 1;
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = s.length();
  if (k == 0) {
    vll v;
    int c = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0')
        ++c;
      else {
        if (c > 0) v.push_back(c);
        c = 0;
      }
    }
    if (c > 0) v.push_back(c);
    ll ans = 0;
    for (auto x : v) ans += (x * (x + 1ll)) / 2;
    cout << ans << "\n";
    return 0;
  }
  vi v{-1};
  int i = 0;
  while (i < n and v.size() <= k) {
    if (s[i] == '1') v.push_back(i);
    ++i;
  }
  if (v.size() <= k) {
    cout << "0\n";
    return 0;
  }
  int p = 1, c = 1;
  ll ans = 0;
  while (i < n) {
    while (i < n and s[i] == '0') ++c, ++i;
    ans += (v[p] - v[p - 1]) * c;
    if (i < n)
      c = 1, ++p, v.push_back(i);
    else
      c = 0;
    ++i;
  }
  if (c) ans += c * (v[p] - v[p - 1]);
  cout << ans << "\n";
  return 0;
}
