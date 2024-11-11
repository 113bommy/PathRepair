#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5000000000")
using namespace std;
using uint = uint32_t;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using vi = std::vector<int64_t>;
using vvi = std::vector<vi>;
using si = std::set<int64_t>;
using pii = std::pair<int64_t, int64_t>;
using pci = std::pair<int8_t, int64_t>;
using psi = std::pair<std::string, int64_t>;
using mii = std::map<int64_t, int64_t>;
using mci = std::map<int8_t, int64_t>;
using msi = std::map<std::string, int64_t>;
using vl = std::vector<ll>;
using vvl = std::vector<vl>;
using sl = std::set<ll>;
using pll = std::pair<ll, ll>;
using pil = std::pair<int64_t, ll>;
using pcl = std::pair<int8_t, ll>;
using psl = std::pair<std::string, ll>;
using mll = std::map<ll, ll>;
using mil = std::map<int64_t, ll>;
using mcl = std::map<int8_t, ll>;
using msl = std::map<std::string, ll>;
using vf = std::vector<ld>;
using vvf = std::vector<vf>;
using sf = std::set<ld>;
using pff = std::pair<ld, ld>;
using pif = std::pair<int64_t, ld>;
using plf = std::pair<ll, ld>;
using pcf = std::pair<int8_t, ld>;
using psf = std::pair<std::string, ld>;
using mff = std::map<ld, ld>;
using mif = std::map<int64_t, ld>;
using mlf = std::map<ll, ld>;
using mcf = std::map<int8_t, ld>;
using msf = std::map<std::string, ld>;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("rename-registers")
template <class T>
istream &operator>>(istream &in, vector<T> &vector) {
  for (auto &it : vector) in >> it;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, vector<T> &vector) {
  for (const auto &it : vector) out << it << ' ';
  return out;
}
template <class T, class U>
istream &operator>>(istream &in, pair<T, U> &pair) {
  in >> pair.first >> pair.second;
  return in;
}
template <class T, class U>
ostream &operator<<(ostream &out, pair<T, U> &pair) {
  out << pair.first << ' ' << pair.second;
  return out;
}
namespace X {
template <class T>
T gcd(T a, T b) {
  return !b ? a : X::gcd(b, a % b);
}
bool isPalindrom(std::string s) {
  for (ll(i) = 0; (i) < (s.length() / 2 + s.length() % 2); ++(i))
    if (s[i] != s[s.length() - 1 - i]) return false;
  return true;
}
void solve(void) { return; }
}  // namespace X
signed main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int64_t n, v0, v1;
  cin >> n >> v0 >> v1;
  vi a(n);
  cin >> a;
  pii _1;
  cin >> _1;
  ld t = 0;
  ld MN = INT32_MAX;
  int64_t iMN = -1;
  for (int64_t(i) = (1); (i) < (n); ++(i)) {
    t += (a[i] - a[i - 1]) * 1. / v0;
    ld _t = t + sqrt((_1.first - a[i]) * (_1.first - a[i]) +
                     _1.second * _1.second) /
                    v1;
    if (_t < MN) {
      MN = _t;
      iMN = i;
    }
  }
  cout << iMN + 1 << '\n';
  fprintf(stderr, "Time elapsed: %dms\n", 1000 * clock() / CLOCKS_PER_SEC);
  return 0;
}
