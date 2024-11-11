#include <bits/stdc++.h>
const int mod = 1000000007;
const int gmod = 5;
const int inf = 1039074182;
const double eps = 1e-9;
const long long llinf = 1LL * inf * inf;
template <typename T1, typename T2>
inline void chmin(T1 &x, T2 b) {
  if (b < x) x = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &x, T2 b) {
  if (b > x) x = b;
}
inline void chadd(int &x, int b) {
  x += b - mod;
  x += (x >> 31 & mod);
}
template <typename T1, typename T2>
inline void chadd(T1 &x, T2 b) {
  x += b;
  if (x >= mod) x -= mod;
}
template <typename T1, typename T2>
inline void chmul(T1 &x, T2 b) {
  x = 1LL * x * b % mod;
}
template <typename T1, typename T2>
inline void chmod(T1 &x, T2 b) {
  x %= b, x += b;
  if (x >= b) x -= b;
}
template <typename T>
inline T mabs(T x) {
  return (x < 0 ? -x : x);
}
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec) {
  cout << "{";
  for (int i = 0; i < (int)vec.size(); i++) {
    cout << vec[i];
    if (i != (int)vec.size() - 1) cout << ',';
  }
  cout << "}";
  return cout;
}
template <typename T>
void operator*=(vector<T> &vec, int k) {
  for (auto &x : vec) x *= k;
}
template <typename T>
void operator-=(vector<T> &a, const vector<T> &b) {
  assert(a.size() == b.size());
  for (size_t it = 0; it < a.size(); it++) {
    a[it] -= b[it];
  }
}
template <typename T>
vector<T> operator*(const vector<T> &vec, int k) {
  vector<T> res(vec);
  res *= k;
  return res;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p) {
  cout << "(" << p.first << ',' << p.second << ")";
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, queue<T> q) {
  vector<T> t;
  while (q.size()) {
    t.push_back(q.front());
    q.pop();
  }
  cout << t;
  return cout;
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m) {
  for (auto &x : m) {
    cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
  }
  return cout;
}
template <typename T>
T operator*(vector<T> v1, vector<T> v2) {
  assert(v1.size() == v2.size());
  int n = v1.size();
  T res = 0;
  for (int i = 0; i < n; i++) {
    res += v1[i] * v2[i];
  }
  return res;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
  return make_pair(x.first + y.first, x.second + y.second);
}
template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
  x.first += y.first;
  x.second += y.second;
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x) {
  return make_pair(-x.first, -x.second);
}
template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec) {
  vector<vector<T>> v;
  int n = vec.size(), m = vec[0].size();
  v.resize(m);
  for (int i = 0; i < m; i++) {
    v[i].resize(n);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = vec[j][i];
    }
  }
  return v;
}
void print0x(int x) {
  std::vector<int> vec;
  while (x) {
    vec.push_back(x & 1);
    x >>= 1;
  }
  std::reverse(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    std::cout << vec[i];
  }
  std::cout << ' ';
}
template <typename T>
void print0x(T x, int len) {
  std::vector<int> vec;
  while (x) {
    vec.push_back(x & 1);
    x >>= 1;
  }
  reverse(vec.begin(), vec.end());
  for (int i = vec.size(); i < len; i++) {
    putchar('0');
  }
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
  }
  std::cout << ' ';
}
using namespace std;
int n, q;
int k, d;
pair<int, int> nxt[22][1000005];
int toPos[1000005];
int num[1000005];
char buf[1000005];
char c[1000005];
inline pair<int, int> getNext(int pos, int k) {
  pair<int, int> res = make_pair(pos, 0);
  for (int i = 0; i < 22; i++) {
    if ((1 << i) & k) {
      res = make_pair(nxt[i][res.first].first,
                      nxt[i][res.first].second + res.second);
    }
    if (res.first == -1) return res;
  }
  return res;
}
inline void calcTimes() {
  for (int i = n - 1; i >= 0; i--) {
    num[i] = num[i + 1] + 1;
  }
  for (int i = 0; i < d; i++) {
    num[i] = num[d - 1];
  }
}
inline void solve() {
  scanf("%d%d", &d, &k);
  vector<int> vid;
  vector<int> ivid;
  for (int i = 0; i < d; i++) {
    vid.push_back(i);
  }
  ivid.resize(d);
  sort(vid.begin(), vid.end(), [](int a, int b) {
    if (a % k != b % k) return (a % k) < (b % k);
    return (a / k) < (b / k);
  });
  for (int i = 0; i < d; i++) {
    ivid[vid[i]] = i;
  }
  for (int i = 0; i < d; i++) {
    nxt[0][i] = make_pair(ivid[i] - 1, 1);
  }
  for (int lg = 1; lg < 22; lg++) {
    for (int i = 0; i < d; i++) {
      nxt[lg][i] =
          ((nxt[lg - 1][i].first == -1)
               ? nxt[lg - 1][i]
               : make_pair(nxt[lg - 1][nxt[lg - 1][i].first].first,
                           nxt[lg - 1][i].second +
                               nxt[lg - 1][nxt[lg - 1][i].first].second));
    }
  }
  calcTimes();
  for (int i = 0; i < n; i++) {
    int pos = (i < d ? i : d - 1);
    pair<int, int> t = getNext(pos, num[i]);
    toPos[i] = t.first + t.second + max(0, i - d + 1);
    buf[toPos[i]] = c[i];
  }
  printf("%s\n", buf);
  for (int i = 0; i < n; i++) {
    c[i] = buf[i];
  }
}
int main() {
  scanf("%s", c);
  n = strlen(c);
  cin >> q;
  for (int i = 0; i < q; i++) {
    solve();
  }
  return 0;
}
