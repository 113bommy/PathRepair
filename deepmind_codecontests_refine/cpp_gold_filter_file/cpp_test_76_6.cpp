#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

 public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator<<(std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& in, modnum& n) {
    ll v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator*=(const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  friend modnum operator++(modnum& a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum& a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return modnum(a) /= b;
  }
};
template <typename T>
T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}
using num = modnum<int(1e9 + 13)>;
int n, m;
vector<set<int>> adj;
vector<int> friends;
vector<int> priorityList;
int randi() { return rand() % 1000 * 1000 + rand() % 1000; }
void bf(int i) {
  if (i == 5) {
    for (int j = 0; j < (5); j++) cout << friends[j] << " ";
    exit(0);
  }
  int last = friends[i - 1];
  for (int u : adj[last])
    if (u > last && adj[u].size() >= 4) {
      bool ok = true;
      for (int j = 0; j < (i); j++)
        if (!adj[u].count(friends[j])) {
          ok = false;
          break;
        }
      if (ok) {
        friends.push_back(u);
        bf(i + 1);
        friends.pop_back();
      }
    }
}
void bff(int i) {
  if (i == 5) {
    for (int j = 0; j < (5); j++) cout << friends[j] << " ";
    exit(0);
  }
  int last = friends[i - 1];
  for (int u = last + 1; u <= n; u++)
    if (adj[u].size() + 4 <= n) {
      bool ok = true;
      for (int j = 0; j < (i); j++)
        if (adj[u].count(friends[j])) {
          ok = false;
          break;
        }
      if (ok) {
        friends.push_back(u);
        bff(i + 1);
        friends.pop_back();
      }
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  adj.assign(n + 1, set<int>());
  for (int i = 0; i < (m); i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int i = 1; i <= n; i++) priorityList.push_back(i);
  sort(priorityList.begin(), priorityList.end(), [&](const int i, const int j) {
    if (adj[i].size() != adj[j].size()) {
      return adj[i].size() > adj[j].size();
    } else {
      return i < j;
    }
  });
  for (int i = 1; i <= n; i++)
    if (adj[i].size() >= 4) {
      friends.clear();
      friends.push_back(i);
      bf(1);
    }
  for (int i = 1; i <= n; i++)
    if (adj[i].size() + 4 <= n) {
      friends.clear();
      friends.push_back(i);
      bff(1);
    }
  cout << -1 << endl;
  return 0;
}
