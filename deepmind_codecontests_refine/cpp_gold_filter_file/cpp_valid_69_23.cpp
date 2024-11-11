#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <typename T>
void view(T e) {
  std::cerr << e << std::endl;
}
template <typename T>
void view(const std::vector<T> &v) {
  for (const auto &e : v) {
    std::cerr << e << " ";
  }
  std::cerr << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
  cerr << endl;
  int cnt = 0;
  for (const auto &v : vv) {
    cerr << cnt << "th : ";
    view(v);
    cnt++;
  }
  cerr << endl;
}
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}
ll power(ll a, ll p) {
  ll ret = 1;
  while (p) {
    if (p & 1) {
      ret = ret * a;
    }
    a = a * a;
    p >>= 1;
  }
  return ret;
}
ll modpow(ll a, ll p, ll mod) {
  ll ret = 1;
  while (p) {
    if (p & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    p >>= 1;
  }
  return ret;
}
template <class T, class K>
bool chmax(T &a, const K b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class K>
bool chmin(T &a, const K b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int inf = 1001001001;
const ll INF = 1001001001001001001ll;
const ll mod = 1000000007;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  V<string> ss(60);
  for (ll i = 0; i < 60; ++i) ss[i] = to_string(power(2, i));
  while (tt--) {
    string t;
    cin >> t;
    int ans = inf;
    for (ll i = 0; i < 60; ++i) {
      int cur = 0;
      string s = ss[i];
      for (ll j = 0; j < ((int)(t).size()); ++j) {
        if (t[j] == s[cur]) cur++;
      }
      chmin(ans, ((int)(t).size()) - cur + ((int)(s).size()) - cur);
    }
    cout << ans << endl;
  }
}
