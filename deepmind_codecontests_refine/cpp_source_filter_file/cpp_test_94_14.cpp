#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PIL = pair<int, ll>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
template <class T>
using PQmax = priority_queue<T>;
template <class T>
using PQmin = priority_queue<T, std::vector<T>, std::greater<T>>;
const int inf = 1 << 29;
const ll INF = 1LL << 60;
const ll MOD = 1000000007LL;
const ld pi = 3.14159265358979;
const ld eps = 1e-10;
const ld dinf = 1e12;
inline bool dequal(const double &a, const double &b) {
  return fabs(a - b) < eps;
}
inline int sgn(const ld &r) { return ((r > eps) - (r < -eps)); }
inline int sgn(const ld &a, const ld &b) { return sgn(a - b); }
ld degtorad(ld deg) { return deg * pi / 180.0; }
ld radtodeg(ld rad) { return rad * 180 / pi; }
const vector<int> h_idx4 = {-1, 0, 0, 1};
const vector<int> w_idx4 = {0, -1, 1, 0};
const vector<int> h_idx8 = {-1, -1, -1, 0, 0, 1, 1, 1};
const vector<int> w_idx8 = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T>
void show_vec(T v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}
template <class T>
void show_pair(T p) {
  cout << p.first << " " << p.second << endl;
}
void YESNO(bool f) { cout << ((f) ? "YES" : "NO") << endl; }
void YesNo(bool f) { cout << ((f) ? "Yes" : "No") << endl; }
void yesno(bool f) { cout << ((f) ? "yes" : "no") << endl; }
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool judge_digit(T bit, T i) {
  return (((bit & (1LL << i)) != 0) ? 1 : 0);
}
template <class T>
T ROUNDUP(T a, T b) {
  return ((a + b - 1) / b);
}
template <class T>
T tousa_sum1(T a, T l, T n) {
  return n * (a + l) / 2;
}
template <class T>
T tousa_sum2(T a, T d, T n) {
  return n * ((2 * a) + ((n - 1) * d)) / 2;
}
ll intpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res *= a;
    }
    a = a * a;
    n >>= 1;
  }
  return res;
}
ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}
template <class T>
T GCD(T a, T b) {
  if (b == 0) return a;
  return (GCD(b, a % b));
}
template <class T>
T LCM(T a, T b) {
  if (b == 0) return (0);
  return ((a / GCD(a, b)) * b);
}
template <class T>
T extGCD(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  T d = extGCD(b, a % b, y, x);
  y -= ((a / b) * x);
  return d;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int test;
  cin >> test;
  for (int testcase = 0; testcase < int(test); testcase++) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool flag = false;
    for (ll i = 0; i < n - 1; i++) {
      ll counter = 0;
      for (ll j = 0; j <= i; j++) {
        counter += intpow(10LL, a[j + 1] - a[j]) - 1;
      }
      if (counter >= k) {
        ll ans = 0;
        k++;
        for (int j = 0; j <= i; j++) {
          if (intpow(10LL, a[j + 1] - a[j]) - 1 <= k) {
            ans += (intpow(10LL, a[j + 1] - a[j]) - 1) * intpow(10LL, a[j]);
            k -= intpow(10LL, a[j + 1] - a[j]) - 1;
          } else {
            ans += k * intpow(10LL, a[j]);
            break;
          }
        }
        cout << ans << endl;
        flag = true;
        break;
      }
    }
    if (flag) continue;
    k++;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (i < n - 1 && intpow(10LL, a[i + 1] - a[i]) - 1 <= k) {
        ans += (intpow(10LL, a[i + 1] - a[i]) - 1) * intpow(10LL, a[i]);
        k -= intpow(10LL, a[i + 1] - a[i]) - 1;
      } else {
        ans += k * intpow(10LL, a[i]);
        break;
      }
    }
    cout << ans << endl;
  }
}
