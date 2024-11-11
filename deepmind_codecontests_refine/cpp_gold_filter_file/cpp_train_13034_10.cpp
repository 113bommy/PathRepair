#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using namespace std;
const int INTMAX = 2147483647;
const int INTMIN = -2147483647;
const ll LLMAX = 9223372036854775807;
const ll LLMIN = -9223372036854775807;
ll MOD = 1000000007;
ll MOD2 = 998224353;
void open(const string &s) {
  string a = s + ".in";
  string b = s + ".out";
  freopen(a.c_str(), "r", stdin);
  freopen(b.c_str(), "w", stdout);
}
template <typename A, typename B>
ostream &operator<<(ostream &out, pair<A, B> const &pair);
template <typename T>
ostream &operator<<(ostream &out, unordered_set<T> const &s);
template <typename T>
ostream &operator<<(ostream &out, set<T> const &s);
template <typename T>
ostream &operator<<(ostream &out, multiset<T> const &s);
template <typename T>
ostream &operator<<(ostream &out, unordered_multiset<T> const &s);
template <typename K, typename V>
ostream &operator<<(ostream &out, multimap<K, V> const &m);
template <typename K, typename V>
ostream &operator<<(ostream &out, unordered_multimap<K, V> const &m);
template <typename T>
ostream &operator<<(ostream &out, vector<T> const &v);
template <typename K, typename V>
ostream &operator<<(ostream &out, map<K, V> const &m);
template <typename K, typename V>
ostream &operator<<(ostream &out, unordered_map<K, V> const &m);
template <typename A, typename B>
ostream &operator<<(ostream &out, pair<A, B> const &pair) {
  out << "(" << pair.first << ", " << pair.second;
  return out << ")";
}
template <typename T>
ostream &operator<<(ostream &out, unordered_set<T> const &s) {
  out << "[";
  int c = 0;
  for (T i : s) {
    if (c) out << ", ";
    out << i;
    c++;
  }
  return out << "]";
}
template <typename T>
ostream &operator<<(ostream &out, set<T> const &s) {
  out << "[";
  int c = 0;
  for (T i : s) {
    if (c) out << ", ";
    out << i;
    c++;
  }
  return out << "]";
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> const &v) {
  out << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
template <typename K, typename V>
ostream &operator<<(ostream &out, map<K, V> const &m) {
  out << "{";
  int c = 0;
  for (const auto &pair : m) {
    if (c) out << ", ";
    out << pair.first << "=" << pair.second;
    c++;
  }
  return out << "}";
}
template <typename K, typename V>
ostream &operator<<(ostream &out, unordered_map<K, V> const &m) {
  out << "{";
  int c = 0;
  for (const auto &pair : m) {
    if (c) out << ", ";
    out << pair.first << "=" << pair.second;
    c++;
  }
  return out << "}";
}
template <typename T>
ostream &operator<<(ostream &out, multiset<T> const &s) {
  out << "[";
  int c = 0;
  for (T i : s) {
    if (c) out << ", ";
    out << i;
    c++;
  }
  return out << "]";
}
template <typename T>
ostream &operator<<(ostream &out, unordered_multiset<T> const &s) {
  out << "[";
  int c = 0;
  for (T i : s) {
    if (c) out << ", ";
    out << i;
    c++;
  }
  return out << "]";
}
template <typename K, typename V>
ostream &operator<<(ostream &out, multimap<K, V> const &m) {
  out << "{";
  int c = 0;
  for (const auto &pair : m) {
    if (c) out << ", ";
    out << pair.first << "=" << pair.second;
    c++;
  }
  return out << "}";
}
template <typename K, typename V>
ostream &operator<<(ostream &out, unordered_multimap<K, V> const &m) {
  out << "{";
  int c = 0;
  for (const auto &pair : m) {
    if (c) out << ", ";
    out << pair.first << "=" << pair.second;
    c++;
  }
  return out << "}";
}
template <typename T>
void shuffle_array(T &arr, int l) {
  unsigned seed = 0;
  shuffle(arr, arr + l, default_random_engine(seed));
}
template <typename T>
void sort_array(T &arr, int l) {
  shuffle_array(arr, l);
  sort(arr, arr + l);
}
void reverse_array(int arr[], int l) {
  for (int i = 0; i < l / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[l - i - 1];
    arr[l - i - 1] = temp;
  }
}
vector<int> to_vec(const string &s) {
  vector<int> list;
  for (char i : s) {
    list.push_back(i - '0');
  }
  return list;
}
template <typename T, typename K>
void next_vec(vector<T> &vec, K &l) {
  vec.clear();
  vec = vector<T>(l, 0);
  for (int i = 0; i < l; i++) cin >> vec[i];
}
string join(vector<string> &vec, const string &t = " ") {
  string s;
  int l = vec.size();
  for (int i = 0; i < l; i++) {
    if (i == l - 1)
      s += vec[i];
    else
      s += vec[i] + t;
  }
  return s;
}
template <typename K, typename V>
V get_or_default(map<K, V> &m, K key, V value) {
  if (m.count(key)) {
    return m[key];
  }
  return value;
}
ll combo(ll n, ll d) {
  if (d > n) return 0;
  if (d * 2 > n) d = n - d;
  if (d == 0) return 1;
  ll res = n;
  for (ll i = 2; i <= d; i++) {
    res *= (n - i + 1);
    res /= i;
  }
  return res;
}
template <typename T>
ll sum(vector<T> &vec) {
  return accumulate(vec.begin(), vec.end(), 0);
}
template <typename T>
void sort_vec(vector<T> &vec) {
  sort(vec.begin(), vec.end());
}
template <typename T>
void shuffle_vec(vector<T> &vec) {
  shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
}
template <typename T>
bool contains(set<T> &s, T element) {
  return s.find(element) != s.end();
}
ll gcd(ll a, ll b) {
  ll mex = max(a, b);
  ll men = min(a, b);
  if (mex % men == 0) {
    return men;
  }
  return gcd(men, mex % men);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
vector<int> ll_to_vec(ll &n) { return to_vec(to_string(n)); }
vector<string> split(const string &str, const string &delim) {
  vector<string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == string::npos) pos = str.length();
    string token = str.substr(prev, pos - prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}
template <typename T>
T vec_max(vector<T> &vec) {
  if (vec.empty()) throw 20;
  T mex = vec[0];
  for (auto i : vec) mex = max(mex, i);
  return mex;
}
template <typename T>
T vec_min(vector<T> &vec) {
  if (vec.empty()) throw 20;
  T men = vec[0];
  for (auto i : vec) men = min(men, i);
  return men;
}
ll pow(ll a, ll b) {
  ll c = 1;
  for (ll i = 0; i < b; i++) c *= a;
  return c;
}
string get_next_line() {
  string line;
  while (getline(cin, line)) break;
  return line;
}
vector<char> to_char_array(const string &s) {
  int l = s.size();
  vector<char> vec;
  vec.reserve(l);
  for (int i = 0; i < l; i++) vec.push_back(s[i]);
  return vec;
}
inline void M998() { swap(MOD, MOD2); }
template <typename T>
int binary_search(vector<T> &vec, T n) {
  int l = vec.size();
  int left = 0;
  int right = l - 1;
  while (left != right) {
    int mid = (left + right + 1) / 2;
    if (vec[mid] > n)
      right = mid - 1;
    else
      left = mid;
  }
  return vec[left] == n ? left : -1;
}
ll to_ll(const string &s) {
  ll c = 0;
  int l = s.size();
  for (int i = 0; i < l; i++) {
    c += pow(2, l - i - 1) * (s[i] - '0');
  }
  return c;
}
ll to_ll(vector<char> &vec) {
  ll c = 0;
  int l = vec.size();
  for (int i = 0; i < l; i++) {
    c += pow(2, l - i - 1) * (vec[i] - '0');
  }
  return c;
}
string change_base(ll n, ll base, ll cur = 10) {
  ll a = 0;
  if (cur != 10) {
    string b = to_string(n);
    int l = b.size();
    for (int i = 0; i < l; i++) a += pow(cur, l - i - 1) * (b[i] - '0');
  } else
    a = n;
  ll mpow = 0;
  while (true) {
    mpow++;
    ll b = pow(base, mpow);
    if (b > a) {
      mpow--;
      break;
    } else if (b == a)
      break;
  }
  string s;
  for (int i = mpow; i >= 0; i--) {
    ll p = pow(base, i);
    ll m = a / p;
    a -= m * p;
    s += to_string(m);
  }
  return s;
}
void solve() {
  int l;
  cin >> l;
  vector<ll> vec;
  next_vec(vec, l);
  ll sum = 0;
  for (ll i : vec) sum += i;
  ll x = vec[0];
  for (int i = 1; i < l; i++) x = x ^ vec[i];
  cout << 2 << endl;
  cout << x << " " << sum + x << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  int MMR;
  cin >> MMR;
  for (int i = 0; i < MMR; i++) solve();
}
