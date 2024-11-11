#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
void useiostream() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(8);
}
void drop(char const* bu) {
  printf("%s", bu);
  exit(0);
}
ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ld const pi = acos(-1.0L);
ld const eps = 0.0001L;
template <typename T, typename TT>
bool mi(T& a, TT b) {
  return a > b ? (a = b, true) : false;
}
template <typename T, typename TT>
bool ma(T& a, TT b) {
  return a < b ? (a = b, true) : false;
}
mt19937 ran(996);
int const mod = 1000000007;
ull bm(ull a, ull p, ull mod) {
  return (a * p - (ll)((ld)a * p / mod) * mod + mod) % mod;
}
ull bp(ull a, ull p, ull mod) {
  ull re = 1;
  while (p) {
    if (p & 1) re = bm(re, a, mod);
    p >>= 1;
    a = bm(a, a, mod);
  }
  return re;
}
bool test(ull n) {
  ull p = 0;
  while ((n - 1) % (1ULL << p) == 0) p++;
  p--;
  ull t = (n - 1) / (1ULL << p);
  int cnt = 0;
  for (int k = 0; k < 20; k++) {
    ull a = ran();
    a %= n - 3;
    a += 2;
    ull x = bp(a, t, n);
    if (x == 1 || x == n - 1) continue;
    for (int j = 0; j < p - 1; j++) {
      x = bp(x, 2, n);
      if (x == 1) return true;
      if (x == n - 1) {
        cnt++;
      }
    }
    return true;
  }
  return false;
}
ull rho(ull a) {
  ull x = rand();
  x %= a - 2;
  x += 1;
  ull y = 1, i = 0, stage = 2;
  while (gcd(a, max(x, y) - min(x, y)) == 1) {
    if (i == stage) {
      y = x;
      stage *= 2;
    }
    x = bp(x, 2, a);
    if (x == 0)
      x = a - 1;
    else
      x--;
    i++;
  }
  return gcd(a, max(x, y) - min(x, y));
}
void kek(vector<pair<int, int> >& res, string& str, int l, int r) {
  res.emplace_back(l, r);
  reverse(str.begin() + l, str.begin() + r + 1);
}
void solve() {
  int n, k;
  vector<pair<int, int> > res;
  cin >> n >> k;
  string str;
  cin >> str;
  for (int i = 0; i < n / 2; i++) {
    if (str[i] == ')') {
      int id = 0;
      for (int j = i + 1; j < n; j++) {
        if (str[j] == '(') {
          id = j;
          break;
        }
      }
      kek(res, str, i, id);
    }
  }
  k--;
  int le = 1;
  int ri = n / 2;
  while (k--) {
    kek(res, str, le, ri);
    le += 2;
    ri++;
  }
  cout << (int)res.size() << "\n";
  for (auto& x : res) cout << x.first + 1 << " " << x.second + 1 << "\n";
}
int main() {
  useiostream();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
