#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vvi = std::vector<vi>;
using vii = std::vector<pii>;
using vll = std::vector<ll>;
using pll = std::pair<ll, ll>;
template <typename T>
int sign(const T& t) {
  return (t > 0) - (t < 0);
}
template <typename T, typename U>
bool remax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T, typename U>
bool remin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
T gcd(T a, T b) {
  a = std::abs(a);
  b = std::abs(b);
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  a = std::abs(a);
  b = std::abs(b);
  return a / gcd(a, b) * b;
}
double get_time() { return static_cast<double>(clock()) / CLOCKS_PER_SEC; }
uint32_t mrand_32t() {
  static std::random_device rd;
  static std::mt19937 rng(rd());
  return rng();
}
uint64_t mrand_64t() {
  static std::random_device rd;
  static std::mt19937_64 rng(rd());
  return rng();
}
template <typename T>
void make_unique(std::vector<T>& v) {
  std::sort(std::begin(v), std::end(v));
  v.erase(std::unique(std::begin(v), std::end(v)), std::end(v));
}
namespace std {
template <typename A, typename B>
string to_string(const pair<A, B>& p) {
  string str;
  str += "(";
  str += to_string(p.first);
  str += ", ";
  str += to_string(p.second);
  str += ")";
  return str;
}
string to_string(bool value) { return value ? "true" : "false"; }
template <typename T>
string to_string(const vector<T>& vec) {
  string str = "{ ";
  bool first = true;
  for (const auto& it : vec) {
    if (!first) {
      str += ", ";
    }
    str += to_string(it);
    first = false;
  }
  str += " }";
  return str;
}
template <typename T>
string to_string(const set<T>& s) {
  string str = "{ ";
  bool first = true;
  for (const auto& it : s) {
    if (!first) {
      str += ", ";
    }
    str += to_string(it);
    first = false;
  }
  str += " }";
  return str;
}
template <typename K, typename V>
string to_string(const map<K, V>& m) {
  string str = "{ ";
  bool first = true;
  for (const auto& it : m) {
    if (!first) {
      str += ", ";
    }
    first = false;
    str += to_string(it.first);
    str += " -> ";
    str += to_string(it.second);
  }
  str += " }";
  return str;
}
string to_string(const string& s) { return "\"" + s + "\""; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(char ch) { return "\'" + string(1, ch) + "\'"; }
template <size_t N>
string to_string(const bitset<N>& b) {
  string res(N, '0');
  for (size_t i = 0; i < N; ++i) {
    res[i] = '0' + b[i];
  }
  return res;
}
template <typename T>
string to_string(const T& t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}
}  // namespace std
void debug_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  std::cerr << " " << std::to_string(H);
  debug_out(T...);
}
using namespace std;
namespace suff_arr {
const int MAXN = 1e6 + 10;
const int LOG = 20;
string s;
int n;
int p[MAXN];
int lcp[MAXN];
int pos[MAXN];
int c[MAXN];
int table[LOG][MAXN];
int log2[MAXN];
void init() {
  for (int len = int(0); len < int(MAXN); ++len) {
    int j = 0;
    while ((1 << j) <= len) {
      ++j;
    }
    log2[len] = j - 1;
  }
}
const int INF = 1e9;
int get_min(int l, int r) {
  if (l > r) {
    return INF;
  }
  int len = r - l + 1;
  int k = log2[len];
  int ans = table[k][l];
  remin(ans, table[k][r - (1 << k) + 1]);
  return ans;
}
void print() {
  return;
  ;
  for (int i = int(0); i < int(int((s).size())); ++i) {
    ;
  };
}
void build(const string& s_) {
  static int cnt[MAXN];
  static int np[MAXN];
  static int nc[MAXN];
  ;
  s = s_;
  n = int((s).size());
  memset(cnt, 0, sizeof cnt);
  for (char ch : s) {
    ++cnt[int(ch)];
  }
  for (int i = int(0); i < int(256); ++i) {
    cnt[i + 1] += cnt[i];
  }
  for (int i = int(0); i < int(int((s).size())); ++i) {
    p[--cnt[int(s[i])]] = i;
  }
  int cls = 1;
  c[p[0]] = cls - 1;
  for (int i = 1; i < n; ++i) {
    if (s[p[i]] != s[p[i - 1]]) {
      ++cls;
    }
    c[p[i]] = cls - 1;
  }
  for (int len = 1; len <= n; len *= 2) {
    memset(cnt, 0, sizeof(int) * cls);
    for (int i = int(0); i < int(n); ++i) {
      ++cnt[c[i]];
    }
    for (int i = int(0); i < int(cls - 1); ++i) {
      cnt[i + 1] += cnt[i];
    }
    for (int i = int(n) - 1; i >= int(0); --i) {
      const int j = p[i];
      int j2 = (j - len + n) % n;
      np[--cnt[c[j2]]] = j2;
    }
    memcpy(p, np, sizeof(int) * n);
    cls = 1;
    nc[p[0]] = cls - 1;
    for (int i = 1; i < n; ++i) {
      if (c[p[i]] != c[p[i - 1]] ||
          c[(p[i] + len) % n] != c[(p[i - 1] + len) % n]) {
        ++cls;
      }
      nc[p[i]] = cls - 1;
    }
    memcpy(c, nc, sizeof(int) * n);
  }
  for (int i = int(0); i < int(n); ++i) {
    pos[p[i]] = i;
  }
  int pref = 0;
  for (int i = int(0); i < int(n); ++i) {
    int pi = pos[i];
    if (pi == n - 1) {
      continue;
    }
    int j = p[pi + 1];
    while (i + pref < n && j + pref < n && s[i + pref] == s[j + pref]) {
      ++pref;
    }
    lcp[pi] = pref;
    pref = max(0, pref - 1);
  }
  for (int i = int(0); i < int(n - 1); ++i) {
    table[0][i] = lcp[i];
  }
  for (int k = int(1); k < int(LOG); ++k) {
    for (int i = int(0); i < int(n - 1); ++i) {
      table[k][i] = table[k - 1][i];
      int j = i + (1 << (k - 1));
      remin(table[k][i], table[k - 1][min(n - 2, j)]);
    }
  }
}
int get_lcp(int i, int j) {
  if (i == j) {
    return INF;
  }
  int l = pos[i];
  int r = pos[j];
  if (l > r) {
    swap(l, r);
  }
  int ans = get_min(l, r - 1);
  ;
  return ans;
}
};  // namespace suff_arr
string s;
string t;
bool read() {
  if (!(cin >> s)) {
    return 0;
  }
  cin >> t;
  return 1;
}
bool check(int r0, int r1) {
  int pos0 = 0;
  int pos1 = -1;
  int ptr = 0;
  for (int i = int(0); i < int(int((s).size())); ++i) {
    if (s[i] == '0') {
      if (suff_arr::get_lcp(pos0, ptr) < r0) {
        return 0;
      }
      ptr += r0;
    } else {
      if (pos1 == -1) {
        pos1 = ptr;
      }
      if (suff_arr::get_lcp(pos1, ptr) < r1) {
        return 0;
      }
      ptr += r1;
    };
  }
  if (r0 == r1 && suff_arr::get_lcp(pos0, pos1) >= r0) {
    return 0;
  };
  assert(ptr == int((t).size()));
  return 1;
}
void solve() {
  suff_arr::build(t);
  if (s[0] != '0') {
    for (auto& c : s) {
      c ^= '0' ^ '1';
    }
  }
  vi cnt(2);
  for (const auto& c : s) {
    ++cnt[c - '0'];
  }
  int ans = 0;
  for (int r0 = 1;; ++r0) {
    int rest = int((t).size()) - cnt[0] * r0;
    if (rest <= 0) {
      break;
    }
    if (rest % cnt[1] != 0) {
      continue;
    }
    int r1 = rest / cnt[1];
    if (check(r0, r1)) {
      ++ans;
    }
  }
  cout << ans << endl;
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cout.precision(12);
  cout << fixed;
  suff_arr::init();
  while (read()) {
    solve();
  }
  return 0;
}
