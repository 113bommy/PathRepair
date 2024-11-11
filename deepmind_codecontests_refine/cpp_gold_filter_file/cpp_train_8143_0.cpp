#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.fr >> a.sc;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << a.fr << " " << a.sc;
  return out;
}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e6 + 3;
const int32_t MM = 998244353;
const long long N = 10000;
long long pw(long long a, long long p = M - 2, long long MOD = M) {
  long long result = 1;
  while (p > 0) {
    if (p & 1) result = a * result % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return result;
}
long long fact[N], invfact[N];
void init() {
  long long p = M;
  fact[0] = 1;
  long long i;
  for (i = 1; i < N; i++) {
    fact[i] = i * fact[i - 1] % p;
  }
  i--;
  invfact[i] = pw(fact[i], p - 2, p);
  for (i--; i >= 0; i--) {
    invfact[i] = invfact[i + 1] * (i + 1) % p;
  }
}
long long ncr(long long n, long long r) {
  if (r > n || n < 0 || r < 0) return 0;
  return fact[n] * invfact[r] % M * invfact[n - r] % M;
}
class DisjointSet {
 public:
  DisjointSet(long long n) {
    for (long long i = 1; i <= n; i++) {
      parent_.push_back(i);
    }
    num_groups_ = n;
    num_items_ = n;
  }
  long long find(long long u) {
    while (u != parent_[u]) {
      u = parent_[u];
    }
    return u;
  }
  void merge(long long u, long long v) {
    long long g1 = find(u);
    long long g2 = find(v);
    parent_[g2] = g1;
  }

 private:
  vector<long long> parent_;
  long long num_groups_;
  long long num_items_;
};
void printV(vector<long long> &v) {
  for (auto &x : v) cout << x << " ";
  cout << "\n";
}
string unary(char ch) {
  if (ch == '>') return "1000";
  if (ch == '<') return "1001";
  if (ch == '+') return "1010";
  if (ch == '-') return "1011";
  if (ch == '.') return "1100";
  if (ch == ',') return "1101";
  if (ch == ',') return "1101";
  if (ch == '[') return "1110";
  if (ch == ']') return "1111";
}
void solve() {
  long long n, m, k = 0, i, j, res = 0, q = 0;
  string s, ans = "";
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    ans += unary(s[i]);
  }
  j = 0;
  for (i = ans.size() - 1; i >= 0; i--) {
    long long val = (ans[i] - '0') * pw(2, j);
    val = val % M;
    res += val;
    res = res % M;
    j++;
  }
  cout << res;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long t = 1;
  while (t--) solve();
  return 0;
}
