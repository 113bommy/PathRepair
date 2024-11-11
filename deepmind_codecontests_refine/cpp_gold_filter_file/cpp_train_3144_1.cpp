#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
int sign(T a) {
  if (a == 0) return 0;
  return (a > 0 ? 1 : -1);
}
template <typename T1, typename T2>
T2 sum_mod(T1 x, T2 MOD) {
  if (x < 0) x += MOD;
  if (x >= MOD) x -= MOD;
  return x;
}
template <typename T1, typename T2>
T2 mul_mod(T1 x, T2 MOD) {
  if (x < 0) return (abs(x) % MOD == 0 ? 0 : MOD - abs(x) % MOD);
  return x % MOD;
}
template <typename T>
bool uax(T& a, const T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool uin(T& a, const T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << '(' << p.first << ' ' << p.second << ')';
  return out;
}
mt19937_64 gen_rand;
const int N = (int)3e5 + 7;
const int LOG = 17;
const int N_ = 1050;
const int MAXN = (int)3e6 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 + 7;
const int CONST = 200;
const long long LINF = (int64_t)2e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-6;
int m1 = (int)1e9 + 7, m2 = (int)1e9 + 9;
int p = 998244353, p1[N], p2[N];
struct Hash {
  int r1, r2;
  Hash(int r1, int r2) : r1(r1), r2(r2){};
};
void operator+=(Hash& a, const Hash& b) {
  a.r1 += b.r1;
  if (a.r1 >= m1) a.r1 -= m1;
  a.r2 += b.r2;
  if (a.r2 >= m2) a.r2 -= m2;
}
void operator-=(Hash& a, const Hash& b) {
  a.r1 -= b.r1;
  if (a.r1 < 0) a.r1 += m1;
  a.r2 -= b.r2;
  if (a.r2 < 0) a.r2 += m2;
}
void operator*=(Hash& a, int x) {
  a.r1 = (1LL * a.r1 * p1[x]) % m1;
  a.r2 = (1LL * a.r2 * p2[x]) % m2;
}
bool operator<(const Hash& a, const Hash& b) {
  return make_pair(a.r1, a.r2) < make_pair(b.r1, b.r2);
}
long long ans;
int n, a[N];
void read() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
}
void precalc() {
  p1[0] = p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p1[i] = (1LL * p1[i - 1] * p) % m1;
    p2[i] = (1LL * p2[i - 1] * p) % m2;
  }
}
vector<int> st;
map<Hash, int> cnt;
void rec(int l, int r) {
  if (r - l < 2) return;
  int m = (r + l) / 2;
  cnt.clear();
  st.clear();
  Hash val(0, 0);
  for (int i = m; i >= l; i--) {
    if (!st.empty() && st.back() == a[i]) {
      st.pop_back();
      Hash cur = Hash(a[i], a[i]);
      cur *= (int)st.size();
      val -= cur;
    } else {
      Hash cur = Hash(a[i], a[i]);
      cur *= (int)st.size();
      val += cur;
      st.push_back(a[i]);
    }
    if (val.r1 == 0 && val.r2 == 0) ans++;
    cnt[val]++;
  }
  st.clear();
  val.r1 = val.r2 = 0;
  for (int i = m + 1; i < r; i++) {
    if (!st.empty() && st.back() == a[i]) {
      st.pop_back();
      Hash cur = Hash(a[i], a[i]);
      cur *= (int)st.size();
      val -= cur;
    } else {
      Hash cur = Hash(a[i], a[i]);
      cur *= (int)st.size();
      val += cur;
      st.push_back(a[i]);
    }
    ans += cnt[val];
  }
  rec(l, m);
  rec(m + 1, r);
}
void solve() {
  ans = 0;
  rec(0, n);
  cout << ans << "\n";
}
double max_time = 0;
void gen() {}
void stupid() {}
void write() {}
void stress() {}
void check_time() {
  double start = clock();
  read(), solve();
  cout << "\nTime is " << (clock() - start) / 1000.0 << "s\n";
}
void check_rand_time() {
  gen_rand.seed(time(0));
  double start = clock();
  gen(), solve();
  double cur_time = (clock() - start) / 1000.0;
  uax(max_time, cur_time);
  cerr << "cur_time = " << cur_time << "    ||    "
       << "max_time = " << max_time << "\n";
}
int main() {
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  gen_rand.seed(time(0));
  int t = 1;
  cin >> t;
  precalc();
  while (t--) {
    read();
    solve();
  }
}
