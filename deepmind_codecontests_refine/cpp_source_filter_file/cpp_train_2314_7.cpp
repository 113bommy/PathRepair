#include <bits/stdc++.h>
using namespace std;
const int inf_int = 1e9 + 100;
const long long inf_ll = 1e18;
const double pi = 3.1415926535898;
template <class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &rhs) {
  out << "( " << rhs.first << " , " << rhs.second << " )";
  return out;
}
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
template <typename A>
string to_string(vector<vector<A>> v) {
  bool first = true;
  string res = "\n{";
  for (const auto &x : v) {
    if (!first) {
      res += ",\n ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}\n";
  return res;
}
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
bool debug = 0;
const int MAXN = 1 << 18;
const int LOG = 20;
const int mod = 998244353;
const int MX = (2e4 + 100);
vector<int> ids[MAXN];
int parent[MAXN];
int get_parent(int v) {
  if (v == parent[v]) return v;
  return parent[v] = get_parent(parent[v]);
}
bool union_set(int a, int b) {
  a = get_parent(a);
  b = get_parent(b);
  if (a != b) {
    parent[a] = b;
    return true;
  }
  return false;
}
int cnt[MAXN];
bool used[MAXN];
void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
    ans -= x;
  }
  cnt[0]++;
  for (int i = 0; i <= n; ++i) {
    parent[i] = i;
  }
  for (int mask = (1 << 18) - 1; mask >= 0; --mask) {
    for (int sub = mask;; sub = (sub - 1) & mask) {
      int u = sub;
      int v = mask ^ sub;
      if (cnt[u] && cnt[v]) {
        if (union_set(u, v)) {
          int val;
          if (used[u] && used[v]) {
            val = 1;
          } else if (used[u]) {
            val = cnt[v];
          } else if (used[v]) {
            val = cnt[u];
          } else {
            val = cnt[v] + cnt[u] - 1;
          }
          ans += 1ll * val * mask;
        }
        used[u] = used[v] = true;
      }
      if (sub == 0) break;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(15);
  int t = 1;
  while (t--) solve();
  42;
}
