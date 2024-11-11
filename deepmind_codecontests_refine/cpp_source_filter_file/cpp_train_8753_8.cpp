#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
template <typename T>
void view(T e) {
  std::cout << e << std::endl;
}
template <typename T>
void view(const std::vector<T>& v) {
  for (const auto& e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>>& vv) {
  cout << endl;
  int cnt = 0;
  for (const auto& v : vv) {
    cout << cnt << "th : ";
    view(v);
    cnt++;
  }
  cout << endl;
}
const ll mod = 998244353;
const int inf = 1001001001;
const ll INF = 1001001001001001001;
const int MAX = 2000005;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
template <class T>
bool chmax(T& a, const T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
ll modpow(ll a, ll p) {
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
int main() {
  ll n, k;
  cin >> n >> k;
  ll m;
  cin >> m;
  if (n == 2 && m != k) {
    cout << "NO" << endl;
    return 0;
  }
  if (n == 2 && m == k) {
    cout << "YES" << endl;
    for (int i = 0; i < k; i++) {
      if (i & 1)
        cout << 1 << " ";
      else
        cout << 2 << " ";
    }
    return 0;
  }
  if ((n - 1) * k < m) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    ll dist = m / k;
    if (dist == n - 1) {
      for (int i = 0; i < k; i++) {
        if (i % 2 == 0)
          cout << n << " ";
        else
          cout << 1 << " ";
      }
    } else {
      ll cnt = m - dist * k;
      ll now = 1;
      for (int i = 0; i < k; i++) {
        if (cnt > 0 && i % 2 == 0) {
          now += dist + 1;
          cout << now << " ";
          cnt--;
        } else if (cnt == 0 && i % 2 == 0) {
          now += dist;
          cout << now << " ";
        } else if (cnt > 0 && i % 2 == 1) {
          now = 1;
          cout << now << " ";
          cnt--;
        } else {
          now -= dist;
          cout << now << " ";
        }
      }
    }
  }
}
