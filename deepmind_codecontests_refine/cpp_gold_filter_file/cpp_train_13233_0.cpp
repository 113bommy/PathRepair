#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
class xxx {
 public:
  xxx(int x) : i(x) {}
  int i;
  void operator()() const { cout << i << endl; }
};
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long mod = 1e9 + 7;
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
class RMQ {
 public:
  std::vector<long long> v;
  vector<vector<long long>> f;
  RMQ(vector<long long> &t) {
    v = t;
    build();
  }
  void build() {
    int n = v.size();
    int level = log(n) / log(2) + 1;
    f = vector<vector<long long>>(n, vector<long long>(level, 0));
    for (int i = 0; i < n; ++i) f[i][0] = v[i];
    for (int i = 1; i < level; ++i) {
      for (int j = 0; j <= n - (1 << i); ++j) {
        f[j][i] = gcd(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
      }
    }
  }
  long long query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
  }
};
const long long INF = LLONG_MAX;
const int maxn = 2e5 + 5;
long long n, m;
long long sums = 0;
int k;
void read1() {}
const int N = 200010;
long long a[N];
long long pre[N];
int l[N], r[N];
int b[N][19];
void solve() {
  int n;
  cin >> n;
  long long sum = 0;
  unordered_map<long long, int> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    m[a[i]]++;
  }
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    if ((sum - a[i]) % 2) continue;
    long long tot = (sum - a[i]) / 2;
    m[a[i]]--;
    if (m.count(tot) and m[tot] >= 1) {
      res.push_back(i);
    }
    m[a[i]]++;
  }
  cout << res.size() << endl;
  for (auto x : res) {
    cout << x + 1 << " ";
  }
  cout << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int tests = 1;
  for (int tc = 1; tc <= tests; tc++) {
    solve();
    cout << flush;
  }
  return 0;
}
int _, __;
