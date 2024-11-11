#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;
using PII = pair<ll, ll>;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) {
  string s = {c};
  return s;
}
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
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
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
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
void yes() {
  cout << ("Yes") << '\n';
  exit(0);
}
void no() {
  cout << ("No") << '\n';
  exit(0);
}
void possible() {
  cout << ("Possible") << '\n';
  exit(0);
}
void impossible() {
  cout << ("Impossible") << '\n';
  exit(0);
}
ll SUM(VI& V) { return accumulate((V).begin(), (V).end(), 0LL); }
ll MIN(VI& V) { return *min_element((V).begin(), (V).end()); }
ll MAX(VI& V) { return *max_element((V).begin(), (V).end()); }
void print_vector(VI& V, ll offset = 0) {
  ll n = V.size();
  for (ll i = (0); i < (n); ++i) {
    if (i) cout << ' ';
    cout << V[i] + offset;
  }
  cout << endl;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  ll g = gcd(a, b);
  return a / g * b;
}
using ld = long double;
constexpr ld EPS = 1e-14;
constexpr bool equals(ld a, ld b) { return fabs((a) - (b)) < EPS; }
using inverse_priority_queue = priority_queue<ll, vector<ll>, greater<ll> >;
int popcount(ll t) { return __builtin_popcountll(t); }
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double PI = acos(-1);
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
ll ll_pow(ll a, ll n) {
  ll ans = 1;
  for (ll i = (0); i < (n); ++i) {
    ans *= a;
  }
  return ans;
}
struct mint {
  ll x;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};
VV load_graph(ll N, ll M) {
  VV G(N);
  for (ll i = (0); i < (M); ++i) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  return G;
}
VV load_tree(ll N) { return load_graph(N, N - 1); }
void solve() {
  ll N;
  cin >> N;
  VI A(N);
  for (ll i = (0); i < (N); ++i) {
    cin >> A[i];
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N, M;
  cin >> N >> M;
  VI A(M);
  for (ll i = (0); i < (M); ++i) {
    cin >> A[i];
  }
  42;
  ll base = 0;
  for (ll i = (0); i < (M - 1); ++i) {
    base += abs(A[i] - A[i + 1]);
  }
  42;
  set<ll> se;
  for (ll a : A) se.insert(a);
  map<ll, VI> index_map;
  for (ll i = (0); i < (M); ++i) {
    ll a = A[i];
    index_map[a].push_back(i);
  }
  ll mi = inf;
  map<ll, VI> mp;
  for (ll a : se) {
    for (ll i : index_map[a]) {
      if (i < M - 1) {
        if (A[i + 1] != a) mp[a].push_back(A[i + 1]);
      }
      if (i > 0) {
        if (A[i - 1] != a) mp[a].push_back(A[i - 1]);
      }
    }
    ll before = 0;
    for (ll v : mp[a]) {
      before += abs(a - v);
    }
    sort((mp[a]).begin(), (mp[a]).end());
    ll sz = mp[a].size();
    if (sz == 0) continue;
    ll med = mp[a][sz / 2];
    ll after = 0;
    for (ll v : mp[a]) {
      after += abs(med - v);
    }
    ll diff = before - after;
    ll candidate = base - diff;
    chmin(mi, candidate);
  }
  cout << (mi) << '\n';
  return 0;
}
