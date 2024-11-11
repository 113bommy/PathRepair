#include <bits/stdc++.h>
const long long MOD = 1000000007;
const double EPS = 1e-4;
using namespace std;
struct mint {
  long long x;
  mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(MOD - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& V) {
  long long N = V.size();
  if (N == 0) {
    os << '.';
    return os;
  }
  for (long long i = 0; i < N - 1; i++) {
    os << V[i] << ' ';
  }
  os << V[N - 1];
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& V) {
  long long N = V.size();
  for (long long i = 0; i < N - 1; i++) cout << V[i] << "\n";
  cout << V[N - 1];
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> const& P) {
  os << P.first << ' ' << P.second;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& S) {
  auto it = S.begin();
  while (it != S.end()) {
    os << *it;
    if (next(it, 1) != S.end()) os << ' ';
    it++;
  };
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& q) {
  for (auto it = q.begin(); it < q.end(); it++) {
    os << *it;
    if (it + 1 != q.end()) os << " ";
  }
  return os;
}
template <typename T>
void Vin(vector<T>& v) {
  long long n = v.size();
  for (long long i = 0; i < n; i++) cin >> v[i];
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long mypow(long long x, long long n, long long m) {
  if (n == 0) return 1;
  if (n % 2 == 0)
    return mypow(x * x % m, n / 2, m);
  else
    return x * mypow(x, n - 1, m) % m;
}
long long scomb(long long n, long long r) {
  if (r < 0 || r > n) return 0;
  if ((n - r) < r) r = n - r;
  long long a = 1;
  for (long long i = n; i > n - r; --i) {
    a = a * i;
  }
  for (long long i = 1; i < r + 1; ++i) {
    a = a / i;
  }
  return a;
}
vector<long long> vis(vector<long long>& v) {
  vector<long long> S(v.size() + 1);
  for (long long i = 1; i < S.size(); i++) S[i] += v[i - 1] + S[i - 1];
  return S;
}
long long digitsum(long long n) {
  long long ret = 0;
  while (n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}
long long digit(long long k, long long i) {
  string s = to_string(k);
  return s[s.size() - i] - '0';
}
template <typename T>
void press(T& v) {
  v.erase(unique((v).begin(), (v).end()), v.end());
}
vector<long long> zip(vector<long long> b) {
  long long Z = b.size();
  pair<long long, long long> p[Z + 10];
  long long a = b.size();
  vector<long long> l(a);
  for (long long i = 0; i < a; i++) p[i] = make_pair(b[i], i);
  sort(p, p + a);
  long long w = 0;
  for (long long i = 0; i < a; i++) {
    if (i && p[i].first != p[i - 1].first) w++;
    l[p[i].second] = w;
  }
  return l;
}
vector<long long> nibe2V() {
  vector<long long> a(60);
  long long q = 1;
  for (long long i = 0; i < 60; i++) {
    a[i] = q;
    q *= 2;
  }
  return a;
}
long long modiv(long long a, long long b) {
  return a * mypow(b, MOD - 2, MOD) % MOD;
}
long long SMALLER(vector<long long>& a, long long x) {
  return lower_bound(a.begin(), a.end(), x) - a.begin();
}
long long orSMALLER(vector<long long>& a, long long x) {
  return upper_bound(a.begin(), a.end(), x) - a.begin();
}
long long BIGGER(vector<long long>& a, long long x) {
  return a.size() - orSMALLER(a, x);
}
long long orBIGGER(vector<long long>& a, long long x) {
  return a.size() - SMALLER(a, x);
}
long long COUNT(vector<long long>& a, long long x) {
  return upper_bound((a).begin(), (a).end(), x) -
         lower_bound((a).begin(), (a).end(), x);
}
long long maxind(vector<long long>& a) {
  return max_element((a).begin(), (a).end()) - a.begin();
}
long long minind(vector<long long>& a) {
  return min_element((a).begin(), (a).end()) - a.begin();
}
vector<long long> stpowV() {
  vector<long long> a(1000005);
  a[0] = 1;
  for (long long i = 1; i <= 1000004; i++) a[i] = a[i - 1] * i % MOD;
  return a;
}
void sol() {
  long long n, v;
  cin >> n >> v;
  vector<pair<long long, long long>> one, two;
  for (long long i = 0; i < n; i++) {
    long long qw, er;
    cin >> qw >> er;
    if (qw == 1) {
      one.push_back(make_pair(er, i + 1));
    } else
      two.push_back(make_pair(er, i + 1));
  }
  for (long long i = 0; i < 5; i++)
    one.push_back(make_pair(0, 3000000000000000000));
  for (long long i = 0; i < 5; i++)
    two.push_back(make_pair(0, 3000000000000000000));
  sort((one).begin(), (one).end());
  sort((two).begin(), (two).end());
  long long ans = 0;
  vector<long long> ans2;
  long long ol = one.size() - 1, tl = two.size() - 1;
  while (1) {
    long long os, ts;
    if (v == 0) break;
    os = one[ol].first + one[ol - 1].first;
    ts = two[tl].first;
    if (ts == 0 && os == 0) break;
    if (v == 1) {
      v--;
      ans += one[ol].first;
      ans2.push_back(one[ol].second);
      ol--;
      break;
    }
    if (os <= ts) {
      ans += ts;
      ans2.push_back(two[tl].second);
      tl--;
      v -= 2;
    } else {
      ans += one[ol].first;
      ans2.push_back(one[ol].second);
      ol--;
      v -= 1;
    }
    if (v == 0) break;
  }
  cout << ans << "\n";
  sort((ans2).begin(), (ans2).end());
  while (ans2.size() > 0 && ans2.back() == 3000000000000000000) ans2.pop_back();
  if (ans2.size() > 0) cout << ans2 << "\n";
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  long long q = 1;
  while (q--) sol();
  return 0;
}
