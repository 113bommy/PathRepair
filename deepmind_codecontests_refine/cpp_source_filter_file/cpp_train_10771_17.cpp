#include <bits/stdc++.h>
using namespace std;
void setIO(const string &name = "") {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  if (name.length()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
template <typename T>
void read(vector<T> &a) {
  for (auto &x : a) cin >> x;
}
template <typename T>
void read(vector<T> &a, long long n) {
  a.resize(n);
  for (auto &x : a) cin >> x;
}
template <class T, class U>
ostream &operator<<(ostream &out, const pair<T, U> &v) {
  out << "(";
  out << v.first << "," << v.second;
  return out << ")";
}
template <class T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (auto(i) = 0; (i) < ((long long)(v).size()); (i)++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
template <typename T>
void print(vector<T> &a) {
  for (const auto &x : a) cout << x << ' ';
  cout << '\n';
}
void MOD(long long &x, long long m = 1000000007) {
  x %= m;
  if (x < 0) x += m;
}
template <typename T>
void dbg(const char *name, T &&arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename T, typename... U>
void dbg(const char *names, T &&arg1, U &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  dbg(comma + 1, args...);
}
template <class T>
void read(T &x) {
  cin >> x;
}
template <class T, class... U>
void read(T &t, U &...u) {
  read(t);
  read(u...);
}
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
struct SegTree {
  long long size = 1;
  vector<long long> elements;
  void build(long long x, long long lx, long long rx) {
    if (rx - lx == 1) return;
    long long mid = (lx + rx) / 2;
    build(2 * x + 1, lx, mid);
    build(2 * x + 2, mid, rx);
    elements[x] = elements[2 * x + 1] + elements[2 * x + 2];
  }
  void init(const long long &n) {
    while (size < n) size *= 2;
    elements.assign(2 * size, 1);
    build(0, 0, size);
  }
  void toggle(long long i, long long x, long long lx, long long rx) {
    if (rx - lx == 1) {
      elements[x] = 0;
      return;
    }
    long long mid = (lx + rx) / 2;
    if (i < mid)
      toggle(i, 2 * x + 1, lx, mid);
    else
      toggle(i, 2 * x + 2, mid, rx);
    elements[x] = elements[2 * x + 1] + elements[2 * x + 2];
  }
  void toggle(long long i) { toggle(i, 0, 0, size); }
  long long find_at_pos(long long i, long long x, long long lx, long long rx) {
    if (rx - lx == 1) return lx;
    long long mid = (lx + rx) / 2;
    if (elements[2 * x + 1] >= i + 1) {
      return find_at_pos(i, 2 * x + 1, lx, mid);
    } else {
      return find_at_pos(i - elements[2 * x + 1], 2 * x + 2, mid, rx);
    }
  }
  long long find_at_pos(long long i) {
    assert(elements[0] >= i + 1);
    return find_at_pos(i, 0, 0, size);
  }
  long long calc_sum(long long l, long long r, long long x, long long lx,
                     long long rx) {
    if (lx >= r or rx <= l) return 0;
    if (l <= lx and rx <= r) return elements[x];
    long long mid = (lx + rx) / 2;
    long long s1 = calc_sum(l, r, 2 * x + 1, lx, mid);
    long long s2 = calc_sum(l, r, 2 * x + 2, mid, rx);
    return s1 + s2;
  }
  long long calc_sum(long long l, long long r) {
    return calc_sum(l, r, 0, 0, size);
  }
};
struct Perm {
  long long n = 1;
  vector<long long> num, actual;
  void init(const long long &x) {
    n = x;
    num.assign(n, 0);
  }
  Perm operator+(const Perm &x) {
    assert(x.n == n);
    Perm ret;
    ret.init(n);
    long long carry = 0, cur;
    for (long long i = n - 1; i >= 0; i--) {
      cur = x.num[i] + num[i] + carry;
      ret.num[i] += cur % (n - i);
      carry = cur / (n - i);
    }
    return ret;
  }
  void recover() {
    actual.resize(n);
    SegTree st;
    st.init(n);
    for (auto(i) = 0; (i) < (n); (i)++) {
      actual[i] = st.find_at_pos(num[i]);
      st.toggle(actual[i]);
    }
  }
  void perm_to_num(const vector<long long> &x) {
    SegTree st;
    st.init(n);
    for (auto(i) = 0; (i) < (n); (i)++) {
      num[i] = st.calc_sum(0, x[i] + 1) - 1;
      st.toggle(num[i]);
    }
  }
};
long long n;
vector<long long> a, b;
void solve() {
  read(n);
  read(a, n);
  read(b, n);
  Perm x, y;
  x.init(n);
  x.perm_to_num(a);
  y.init(n);
  y.perm_to_num(b);
  Perm z = x + y;
  z.recover();
  print(z.actual);
}
int32_t main() {
  setIO();
  long long test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
