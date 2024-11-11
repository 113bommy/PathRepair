#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
T add(T x, T y, T m) {
  return ((x % m) + (y % m)) % m;
}
template <typename T>
T mul(T x, T y, T m) {
  return ((x % m) * (long long)(y % m)) % m;
}
template <typename T>
T sub(T x, T y, T m) {
  return add(x, -y + m);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int lg2(long long x) { return 64 - __builtin_clzll(x) - 1; }
int lg2(int x) { return 32 - __builtin_clzll(x) - 1; }
struct pair_hash {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto h1 = hash<T1>{}(p.first);
    auto h2 = hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long int LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1);
map<ll, bool> exist;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll sum = 0;
  vector<ll> v(n);
  for (auto &x : v) {
    cin >> x;
    sum += x;
  }
  if (sum & 1) {
    cout << "NO" << '\n';
    return 0;
  }
  vector<ll> pre(n);
  pre[0] = v[0];
  for (ll i = 1; i < n; ++i) {
    pre[i] = v[i] + pre[i - 1];
  }
  vector<ll> suff(n);
  suff[n - 1] = v[n - 1];
  for (ll i = n - 2; i >= 0; --i) {
    suff[i] = v[i] + suff[i + 1];
  }
  bool found = false;
  for (int i = 0; i < n - 1; ++i) {
    if (exist[pre[i]] || pre[i] == sum / 2) {
      found = true;
      break;
    }
    exist[sum / 2LL + v[i]] = true;
  }
  exist.clear();
  for (int i = n - 1; !found && i > 0; --i) {
    if (exist[suff[i]] || suff[i] == sum / 2) {
      found = true;
      break;
    }
    exist[sum / 2LL + v[i]] = true;
  }
  cout << (found ? "YES" : "NO") << '\n';
  return 0;
}
