#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline long long power(long long bs, long long k) {
  long long x = 1LL, y = bs;
  if (k == 0) return 1LL;
  while (k > 0) {
    if (k % 2) x *= y;
    y *= y;
    k /= 2;
  }
  return x;
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
string to_str(T t) {
  stringstream ss;
  ss << t;
  return ss.str();
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
clock_t tStart = clock();
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
struct node {
  vector<long long> elem;
} seg[4 * 10010];
bitset<10010> ans;
void update(long long nd, long long l, long long r, long long x, long long y,
            long long val) {
  if (x > r || y < l) return;
  if (x <= l && y >= r) {
    seg[nd].elem.emplace_back(val);
    return;
  }
  long long mid = (l + r) >> 1LL, lf = (nd << 1LL);
  update(lf, l, mid, x, y, val);
  update(lf + 1, mid + 1, r, x, y, val);
}
void query(long long nd, long long l, long long r, bitset<10010> dp) {
  for (auto x : seg[nd].elem) {
    dp |= (dp << x);
  }
  if (l == r) {
    ans |= dp;
    return;
  }
  long long mid = (l + r) >> 1LL, lf = nd << 1LL;
  query(lf, l, mid, dp);
  query(lf + 1, mid + 1, r, dp);
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cout.unsetf(ios::floatfield);
  cout.precision(10);
  cout.setf(ios::fixed, ios::floatfield);
  ;
  bitset<10010> dp;
  long long n, q, i, j, l, r, x;
  dp[0] = 1;
  cin >> n >> q;
  for (i = 0; i < q; ++i) {
    cin >> l >> r >> x;
    update(1LL, 1, n, l, r, x);
  }
  query(1, 1, n, dp);
  vector<long long> res;
  for (i = 1; i <= n; ++i)
    if (ans[i]) res.emplace_back(i);
  cout << (long long)res.size() << '\n';
  for (auto x : res) cout << x << ' ';
  return 0;
}
