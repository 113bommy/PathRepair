#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ld = long double;
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
ll SUM(VI& V) { return accumulate((V).begin(), (V).end(), 0LL); }
ll MIN(VI& V) { return *min_element((V).begin(), (V).end()); }
ll MAX(VI& V) { return *max_element((V).begin(), (V).end()); }
void print_vector(VI& V) {
  ll n = V.size();
  for (ll i = (0); i < (n); ++i) {
    if (i) cout << ' ';
    cout << V[i];
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
using inverse_priority_queue = priority_queue<ll, vector<ll>, greater<ll> >;
int popcount(ll t) { return __builtin_popcountll(t); }
void no() {
  cout << ("No") << '\n';
  exit(0);
}
void yes() {
  cout << ("Yes") << '\n';
  exit(0);
}
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double PI = acos(-1);
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
ll string_to_ll(string s) { return atoll(s.c_str()); }
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
  ll N, K, S;
  cin >> N >> K >> S;
  if (S < K) {
    cout << ("NO") << '\n';
    return 0;
  }
  ll len = N - 1;
  ll ma = len * K;
  if (ma < S) {
    cout << ("NO") << '\n';
    return 0;
  } else {
    cout << ("YES") << '\n';
  }
  VI D;
  while (S) {
    if (S >= len) {
      D.push_back(len);
      S -= len;
    } else {
      D.push_back(S);
      S = 0;
    }
  }
  42;
  ll one = 0;
  while (((int)(D).size()) < K) {
    ll diff = K - ((int)(D).size());
    ll v = D.back();
    D.pop_back();
    if (v - 1 >= diff) {
      one += diff;
      v -= diff;
      D.push_back(v);
      K = 0;
    } else {
      one += v;
      K -= v;
    }
  }
  while (one--) D.push_back(1);
  42;
  bool right = true;
  ll now = 1;
  VI Ans;
  for (ll d : D) {
    if (right) {
      now += d;
    } else {
      now -= d;
    }
    Ans.push_back(now);
    right = 1 - right;
  }
  print_vector(Ans);
  return 0;
}
