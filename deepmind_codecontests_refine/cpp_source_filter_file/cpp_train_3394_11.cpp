#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long N = 1e6 + 5;
void pairsort(long long a[], long long b[], long long n) {
  pair<long long, long long> pairt[n];
  for (long long i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
long long C(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long mod = 1e9 + 7;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % mod;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % mod;
    res %= mod;
  }
  return res;
}
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(std::pair<T1, T2> const &pair) const {
    std::size_t h1 = std::hash<T1>()(pair.first);
    std::size_t h2 = std::hash<T2>()(pair.second);
    return h1 ^ h2;
  }
};
long long n, x, y, f[N], vis[N], a[N], k;
set<pair<long long, long long>, greater<pair<long long, long long>>> s;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> x;
  for (long long i = 1; i <= n; i++) {
    cin >> y, a[i] = y;
    if (x == y)
      f[x]++;
    else {
      s.erase({f[y], y}), f[y]++, s.insert({f[y], y});
      pair<long long, long long> p = *s.begin();
      if (p.first >= f[x]) k = 1;
    }
  }
  if (!k) return cout << -1, 0;
  memset(f, 0, sizeof(f));
  unordered_set<pair<long long, long long>, pair_hash> ss;
  for (long long i = 1; i <= 2e5; i++)
    if (x != i) ss.insert({0, i});
  for (long long i = 1; i <= n; i++) {
    if (x == a[i]) {
      f[x]++;
      vector<long long> vv;
      for (auto it = ss.begin(); it != ss.end(); it++)
        if ((*it).first < f[x])
          vv.push_back({(*it).second}), vis[(*it).second] = 1;
      for (long long i = 0; i < vv.size(); i++) ss.erase({f[vv[i]], vv[i]});
    } else if (!vis[a[i]])
      ss.erase({f[a[i]], a[i]}), f[a[i]]++, ss.insert({f[a[i]], a[i]});
  }
  vector<long long> vv;
  for (auto it = ss.begin(); it != ss.end(); it++)
    if (vis[(*it).second]) vv.push_back((*it).second);
  for (long long i = 0; i < vv.size(); i++) ss.erase({f[vv[i]], vv[i]});
  if (!ss.size()) return cout << -1, 0;
  cout << (*ss.begin()).second;
  return 0;
}
