#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_pq = priority_queue<T>;
const int inf = 2e9 + 5;
const long long l_inf = 2e18 + 5;
const int mod_v = 1e9 + 7;
const int max_n = 1e5 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template <typename T>
T gcd(T a, T b) {
  while (b) {
    T temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
template <typename T>
tuple<T, T, T> egcd(T a, T b) {
  T x1 = 1, x2 = 0, y1 = 0, y2 = 1;
  while (b) {
    T q = a / b, r = a % b;
    T new_x = x1 - q * x2, new_y = y1 - q * y2;
    x1 = x2, y1 = y2, x2 = new_x, y2 = new_y;
    a = b, b = r;
  }
  return make_tuple(a, x1, y1);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
template <typename T>
inline T mod(T a, T b = mod_v) {
  return (a % b + b) % b;
}
template <typename T>
inline T mod_inv(T a, T b = mod_v) {
  return mod(get<1>(egcd(a, b)), b);
}
template <typename T>
inline T sum(T a, T b, T m = mod_v) {
  return mod(mod(a, m) + mod(b, m), m);
}
template <typename T>
inline T difference(T a, T b, T m = mod_v) {
  return mod(mod(a, m) - mod(b, m), m);
}
inline long long product(long long a, long long b, long long m = mod_v) {
  return mod(mod(a, m) * mod(b, m), m);
}
inline long long quotient(long long a, long long b, long long m = mod_v) {
  return mod(mod(a, m) * mod_inv(b, m), m);
}
template <typename T, typename T2>
ostream &operator<<(ostream &s, const pair<T, T2> &p) {
  return s << p.first << ' ' << p.second << ' ';
}
template <typename T, typename T2>
istream &operator>>(istream &s, pair<T, T2> &p) {
  return s >> p.first >> p.second;
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
  for (auto it : v) s << it << ' ';
  return s;
}
template <typename T>
istream &operator>>(istream &s, vector<T> &v) {
  for (auto it = (v).begin(), it_ = (v).end(); it != it_; ++it) s >> *it;
  return s;
}
template <typename T>
void read_range(T beg, T end) {
  while (beg != end) cin >> *beg++;
}
template <typename T>
void print_range(T beg, T end) {
  while (beg != end) cout << *beg++ << ' ';
}
struct reader {
  template <typename T>
  reader &operator,(T &v) {
    cin >> v;
    return *this;
  }
} rdr;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << ", ";
    return *this;
  }
} dbg;
long long fen[2][5 * max_n];
void increase(int j, int i, int val) {
  while (i < max_n) {
    fen[j][i] += val;
    i += i & -i;
  }
}
long long sum(int j, int i) {
  long long ans = 0;
  while (i) {
    ans += fen[j][i];
    i -= i & -i;
  }
  return ans;
}
long long sum(int ind, int i, int j) { return sum(ind, j) - sum(ind, i - 1); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  for (int i = 0; i < q; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int day, val;
      cin >> day >> val;
      long long cur_a = sum(0, day, day);
      long long cur_b = sum(1, day, day);
      long long new_a = min(a, val + cur_a);
      long long new_b = min(b, cur_b + val);
      long long inc_a = new_a - cur_a;
      long long inc_b = new_b - cur_b;
      increase(0, day, inc_a);
      increase(1, day, inc_b);
    } else {
      int day;
      cin >> day;
      int l = day;
      int r = day + k - 1;
      long long ans = 0;
      if (l > 1) ans += sum(1, 1, l - 1);
      if (r < n) ans += sum(0, r + 1, n);
      cout << ans << '\n';
    }
  }
  return 0;
}
