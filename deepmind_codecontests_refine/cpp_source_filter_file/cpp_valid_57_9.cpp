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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int inf = 1001001001;
const ll INF = 1001001001001001001ll;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    V<int> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    bool ok = true;
    for (ll i = 0; i < n; ++i) {
      if (a[i] % 2 == 1 && i % 2 == 1 || a[i] % 2 == 0 && i % 2 == 0) {
        cout << -1 << endl;
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    V<int> ans;
    for (int i = 1; i < n; i += 2) {
      int p, q;
      for (ll j = 0; j < n; ++j) {
        if (a[j] == i) p = j;
      }
      if (p != 0) ans.push_back(p + 1);
      reverse(a.begin(), a.begin() + p + 1);
      for (ll j = 0; j < n; ++j) {
        if (a[j] == i) p = j;
        if (a[j] == i + 1) q = j;
      }
      ans.push_back(q - 1);
      reverse(a.begin(), a.begin() + q);
      ans.push_back(q + 1);
      reverse(a.begin(), a.begin() + q + 2);
      ans.push_back(3);
      reverse(a.begin(), a.begin() + 3);
      ans.push_back(n - i + 1);
      reverse(a.begin(), a.end() - i + 1);
    }
    ans.push_back(n);
    cout << ((int)(ans).size()) << endl;
    for (ll i = 0; i < ((int)(ans).size()); ++i) cout << ans[i] << " ";
    cout << endl;
  }
}
