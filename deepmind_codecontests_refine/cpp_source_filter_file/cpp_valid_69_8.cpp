#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
template <typename T>
void view(T e) {
  std::cerr << e << std::endl;
}
template <typename T>
void view(const std::vector<T>& v) {
  for (const auto& e : v) {
    std::cerr << e << " ";
  }
  std::cerr << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T> >& vv) {
  cerr << endl;
  int cnt = 0;
  for (const auto& v : vv) {
    cerr << cnt << "th : ";
    view(v);
    cnt++;
  }
  cerr << endl;
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
ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
template <class T, class K>
bool chmax(T& a, const K b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class K>
bool chmin(T& a, const K b) {
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
const ll mod = 1000000007;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  V<string> two(40);
  for (int i = 0; i < 40; i++) two[i] = to_string(1ll << i);
  while (t--) {
    string s;
    cin >> s;
    int ans = ((int)(s).size()) + 1;
    for (const string& t : two) {
      int k = 0;
      for (int i = 0; i < ((int)(s).size()); i++) {
        if (k < ((int)(t).size()) && s[i] == t[k]) k++;
      }
      chmin(ans, ((int)(s).size()) + ((int)(t).size()) - 2 * k);
    }
    cout << ans << endl;
  }
}
