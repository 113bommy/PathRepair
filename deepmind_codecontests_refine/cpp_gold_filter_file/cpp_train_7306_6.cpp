#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, INF = 1e9;
const bool debug = 0;
long long n, k, a, d[N];
long long ans;
unordered_map<long long, long long> m;
long long binpow(long long a, long long b) {
  int res = 1;
  if (b >= 20 && a > 1) return 0;
  for (; b; b >>= 1) {
    if (b & 1) res *= a;
    a *= a;
    if (res >= 1e12 || a >= 1e12) return 0;
  }
  return res;
}
int norm(int n) {
  vector<pair<int, int> > divs;
  int res = 1;
  divs.emplace_back(d[n], 1);
  n /= d[n];
  while (n > 1) {
    if (d[n] != divs.back().first) divs.emplace_back(d[n], 0);
    ++divs.back().second;
    n /= d[n];
  }
  for (const pair<int, int>& i : divs) {
    res *= binpow(i.first, i.second % k);
  }
  return res;
}
int obr(int n) {
  n = norm(n);
  vector<pair<int, int> > divs;
  int res = 1;
  divs.emplace_back(d[n], 1);
  n /= d[n];
  while (n > 1) {
    if (d[n] != divs.back().first) divs.emplace_back(d[n], 0);
    ++divs.back().second;
    n /= d[n];
  }
  for (const pair<int, int>& i : divs) {
    res *= binpow(i.first, k - i.second);
  }
  return res;
}
int main() {
  if (debug) freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  d[1] = 1;
  for (int i = 2; i * i < N; ++i) {
    if (d[i]) continue;
    d[i] = i;
    for (int j = i * i; j < N; j += i)
      if (!d[j]) d[j] = i;
  }
  for (int i = 2; i < N; ++i)
    if (!d[i]) d[i] = i;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a, ++m[norm(a)];
  for (const auto& i : m) {
    if (!m.count(obr(i.first))) continue;
    if (obr(i.first) == norm(i.first))
      ans += m[i.first] * (m[obr(i.first)] - 1);
    else
      ans += m[i.first] * m[obr(i.first)];
  }
  cout << ans / 2;
  return 0;
}
