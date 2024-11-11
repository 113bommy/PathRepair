#include <bits/stdc++.h>
using namespace std;
inline long long readInt();
inline long long readUInt();
inline void readWord(char *s);
inline long long fast_readchar();
inline void writeInt(long long first);
inline void fast_writechar(long long first);
inline void writeWord(const char *s);
inline void fast_flush();
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
template <typename T>
vector<T> readvector(size_t sz) {
  vector<T> res(sz);
  for (size_t i = 0; i < sz; ++i) {
    cin >> res[i];
  }
  return res;
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p) {
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
  return out;
}
inline long long binPow(long long first, long long deg, long long mod) {
  long long ans = 1;
  for (long long i = sizeof(deg) * CHAR_BIT - 1; i >= 0; i--) {
    ans *= ans;
    ans %= mod;
    if ((((deg) >> (i)) & 1)) ans *= first;
    ans %= mod;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
const long long MAXN = 3e5 + 10;
const long long MOD = 998244353;
const long long INF = 1e18;
long long operator*(pair<long long, long long> A,
                    pair<long long, long long> B) {
  return A.first * B.first + A.second * B.second;
}
long long operator%(pair<long long, long long> A,
                    pair<long long, long long> B) {
  return A.first * B.second - A.second * B.first;
}
pair<long long, long long> operator*(pair<long long, long long> A,
                                     long long c) {
  return {A.first * c, A.second * c};
}
pair<long long, long long> operator-(pair<long long, long long> A,
                                     pair<long long, long long> B) {
  return {A.first - B.first, A.second - B.second};
}
pair<long long, long long> operator+(pair<long long, long long> A,
                                     pair<long long, long long> B) {
  return {A.first + B.first, A.second + B.second};
}
vector<pair<long long, long long> > D = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
long long fact[MAXN], inv_fact[MAXN];
void precalc() {
  fact[0] = 1;
  for (long long i = 1; i < MAXN; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  inv_fact[MAXN - 1] = binPow(fact[MAXN - 1], MOD - 2, MOD);
  for (long long i = MAXN - 1; i > 0; i--) {
    inv_fact[i - 1] = (inv_fact[i] * i) % MOD;
  }
}
long long c(long long n, long long k) {
  if (k < 0 || k > n || n < 0) return 0;
  return ((fact[n] * inv_fact[k]) % MOD * inv_fact[n - k]) % MOD;
}
inline void solve() {
  precalc();
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long> > segs(n);
  for (long long i = 0; i < n; i++) {
    cin >> segs[i].first >> segs[i].second;
    segs[i].second++;
  }
  set<long long> elems;
  for (auto e : segs) {
    elems.insert(e.first);
    elems.insert(e.second);
  }
  unordered_map<long long, long long> code = {};
  for (auto e : elems) {
    long long id = code.size();
    code[e] = id;
  }
  for (long long i = 0; i < n; i++) {
    segs[i].first = code[segs[i].first];
    segs[i].second = code[segs[i].second];
  }
  long long bal = 0;
  unordered_map<long long, long long> opening, closing;
  for (auto e : segs) {
    opening[e.first]++;
    closing[e.second]++;
  }
  long long ans = 0;
  for (long long i = 0; i < elems.size(); i++) {
    bal -= closing[i];
    ans += max(0ll, c(bal + opening[i], k) - c(bal, k));
    bal += opening[i];
    ans %= MOD;
  }
  ans = ((ans % MOD) + MOD) % MOD;
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long i = 1; i <= t; ++i) {
    solve();
  }
  fast_flush();
  return 0;
}
static const long long buf_size = 4096;
inline long long fast_readchar() {
  static char buf[buf_size];
  static long long len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}
inline long long readUInt() {
  long long c = fast_readchar(), first = 0;
  while (c <= 32) c = fast_readchar();
  while ('0' <= c && c <= '9')
    first = first * 10 + c - '0', c = fast_readchar();
  return first;
}
inline long long readInt() {
  long long s = 1, c = fast_readchar();
  long long first = 0;
  while (c <= 32) c = fast_readchar();
  if (c == '-') s = -1, c = fast_readchar();
  while ('0' <= c && c <= '9')
    first = first * 10 + c - '0', c = fast_readchar();
  return first * s;
}
inline void readWord(char *s) {
  long long c = fast_readchar();
  while (c <= 32) c = fast_readchar();
  while (c > 32) *s++ = c, c = fast_readchar();
  *s = 0;
}
static long long write_pos = 0;
static char write_buf[buf_size];
inline void fast_writechar(long long first) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = first;
}
inline void fast_flush() {
  if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}
inline void writeInt(long long first) {
  if (first < 0) fast_writechar('-'), first = -first;
  char s[24];
  long long n = 0;
  while (first || !n) s[n++] = '0' + first % 10, first /= 10;
  while (n--) fast_writechar(s[n]);
}
inline void writeWord(const char *s) {
  while (*s) fast_writechar(*s++);
}
