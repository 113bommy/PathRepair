#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T SQR(T x) {
  return x * x;
}
template <typename T>
inline T MIN(T x, T y) {
  return (x < y) ? x : y;
}
template <typename T>
inline T MAX(T x, T y) {
  return (x > y) ? x : y;
}
template <typename T>
inline T ABS(T x) {
  return (x > 0) ? x : -x;
}
template <typename T>
inline void UPDATE_MIN(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <typename T>
inline void UPDATE_MAX(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <typename T>
inline int ARGMAX(T cont) {
  return max_element(cont.begin(), cont.end()) - cont.begin();
}
template <typename T>
inline int ARGMIN(T cont) {
  return min_element(cont.begin(), cont.end()) - cont.begin();
}
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[";
  for (__typeof(n - 1) i = (0), __tmpvar__end69 = (n - 1); i < __tmpvar__end69;
       i++)
    s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
template <class T>
inline string TOSTR(const T &x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
inline int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
inline long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
inline long long powmod(long long a, long long p, long long m) {
  long long r = 1;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
struct pairhash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};
template <typename K, typename V>
V GetWithDef(const std::unordered_map<K, V> &m, const K &key, const V &defval) {
  auto it = m.find(key);
  return (it == m.end()) ? defval : it->second;
}
template <typename K, typename V>
void SetDef(std::unordered_map<K, V> &m, const K &key, const V &defval) {
  auto it = m.find(key);
  if (it == m.end()) m[key] = defval;
}
const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;
int N, M;
int now = 0;
int maxh = -1;
vector<int> children[500123];
int time_in[500123];
int time_out[500123];
vector<int> time_in_by_h[500123];
vector<int> acc_by_h[500123];
char sym[500123];
void dfs(int s, int h) {
  UPDATE_MAX(maxh, h);
  if (acc_by_h[h].size() == 0) acc_by_h[h].push_back(0);
  acc_by_h[h].push_back(acc_by_h[h].back() ^ (1 << sym[s]));
  time_in_by_h[h].push_back(now);
  time_in[s] = now++;
  for (auto &t : children[s]) {
    dfs(t, h + 1);
  }
  time_out[s] = now++;
}
int main() {
  scanf("%d %d\n", &N, &M);
  1;
  for (__typeof(N + 1) i = (2), __tmpvar__end177 = (N + 1);
       i < __tmpvar__end177; i++) {
    int parent;
    scanf("%d", &parent);
    assert(parent >= 1);
    assert(parent < N);
    children[parent].push_back(i);
  }
  scanf("\n");
  for (__typeof(N + 1) i = (1), __tmpvar__end185 = (N + 1);
       i < __tmpvar__end185; i++) {
    scanf("%c", &sym[i]);
    assert(sym[i] >= 'a');
    assert(sym[i] <= 'z');
    sym[i] -= 'a';
  }
  dfs(1, 1);
  for (__typeof(M) i = (0), __tmpvar__end192 = (M); i < __tmpvar__end192; i++) {
    int v, h;
    scanf("%d %d\n", &v, &h);
    assert(1 <= v);
    assert(1 <= h);
    assert(v <= N);
    assert(h <= N);
    if (h > maxh) {
      printf("Yes\n");
      continue;
    }
    auto &vec = time_in_by_h[h];
    auto it1 = lower_bound((vec).begin(), (vec).end(), time_in[v]);
    auto it2 = upper_bound((vec).begin(), (vec).end(), time_out[v]);
    if (it2 - it1 <= 0) {
      printf("Yes\n");
      continue;
    }
    int i1 = it1 - vec.begin();
    int i2 = it2 - vec.begin();
    int acc = acc_by_h[h][i2] ^ acc_by_h[h][i1];
    if (__builtin_popcount(acc) <= 1)
      printf("Yes\n");
    else {
      printf("No\n");
    }
  }
  return 0;
}
