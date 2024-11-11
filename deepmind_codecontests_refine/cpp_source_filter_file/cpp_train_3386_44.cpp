#include <bits/stdc++.h>
using namespace std;
int break_point() {
  char c;
  while ((c = getchar()) != '\n')
    ;
  return 0;
}
template <typename T>
void read_integer(T &r) {
  bool sign = 0;
  r = 0;
  char c;
  while (1) {
    c = getchar();
    if (c == '-') {
      sign = 1;
      break;
    }
    if (c != ' ' && c != '\n') {
      r = c - '0';
      break;
    }
  }
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n') break;
    r = r * 10 + (c - '0');
  }
  if (sign) r = -r;
}
long long binpowmod(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= mod;
      b--;
    } else {
      a *= a;
      a %= mod;
      b >>= 1;
    }
  }
  return res;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      b--;
    } else {
      a *= a;
      b >>= 1;
    }
  }
  return res;
}
inline int getbit(int x, int b) { return (x >> b) & 1; }
inline long long getbit(long long x, int b) { return (x >> b) & 1; }
inline unsigned long long getbit(unsigned long long x, int b) {
  return (x >> b) & 1;
}
inline int setbit(int x, int b) { return x | (1 << b); }
inline void _setbit(int &x, int b) { x = setbit(x, b); }
inline long long setbit(long long x, int b) { return x | (1ll << b); }
inline void _setbit(long long &x, int b) { x = setbit(x, b); }
inline int unsetbit(int x, int b) { return x & (INT_MAX - (1 << b)); }
inline void _unsetbit(int &x, int b) { x = unsetbit(x, b); }
inline int countbit(int x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
inline long long countbit(long long x) {
  int p1 = (x >> 32) & ((1ll << 32) - 1);
  int p2 = x & ((1ll << 32) - 1);
  return countbit(p1) + countbit(p2);
}
template <typename T>
void printbit(T x, int len) {
  for (int i = len - 1; i >= 0; i--) printf("%d", getbit(x, i));
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
template <typename A, typename B>
ostream &operator<<(ostream &stream, const pair<A, B> &p) {
  stream << "{" << p.first << "," << p.second << "}";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const vector<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A, typename B>
ostream &operator<<(ostream &stream, const map<A, B> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const set<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const stack<A> &v) {
  stack<A> st = v;
  stream << "[";
  while (!st.empty()) {
    stream << st.top() << " ";
    st.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const priority_queue<A> &v) {
  priority_queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.top() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const queue<A> &v) {
  queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.front() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
void run();
int main() {
  srand(time(NULL));
  do {
    run();
    if (0) {
      0 ? printf("-------------------------------\n") : 0;
      0 ? printf("-------------------------------\n") : 0;
      0 ? break_point() : 0;
    }
  } while (0);
  return 0;
}
const int mod = 1e9 + 7;
int a[200005];
long long sum[200005];
vector<pair<long long, long long> > pt;
long long line_value(pair<long long, long long> p, long long x) {
  return 1ll * p.first * x + p.second;
}
long long get(long long x) {
  int l = 0, r = ((int)pt.size()) - 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (line_value(pt[mid], x) <= line_value(pt[mid + 1], x))
      l = mid;
    else
      r = mid;
  }
  long long mx = line_value(pt[l], x);
  for (int i = l + 1; i <= r; i++) mx = max((mx), (line_value(pt[i], x)));
  return mx;
}
pair<long long, long long> toVector(pair<long long, long long> a,
                                    pair<long long, long long> b) {
  return {b.first - a.first, b.second - a.second};
}
long long vector_product(pair<long long, long long> a,
                         pair<long long, long long> b) {
  return 1ll * a.first * b.second - 1ll * a.second * b.first;
}
void add_line(long long k, long long b) {
  while (((int)pt.size()) > 1 &&
         vector_product(toVector(pt[((int)pt.size()) - 2], pt.back()),
                        toVector(pt.back(), {k, b})) <= 0) {
    pt.pop_back();
  }
  pt.push_back({k, b});
}
long long solve(int n) {
  pt.clear();
  long long ret = 0;
  add_line(1, 0);
  for (int i = 1; i < n; i++) {
    ret = max((ret), (get(a[i]) + sum[i - 1] - 1ll * a[i] * (i + 1)));
    add_line(i + 1, -sum[i - 1]);
  }
  return ret;
}
long long solve2(int n) {
  pt.clear();
  long long ret = 0;
  add_line(-n, -sum[n - 1]);
  for (int i = n - 2; i >= 0; --i) {
    ret = max((ret), (get(-a[i]) + sum[i] - 1ll * a[i] * (i + 1)));
    add_line(-(i + 1), -sum[i]);
  }
  return ret;
}
void run() {
  int n;
  scanf("%d", &n);
  long long init = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    init += 1ll * (i + 1) * a[i];
  }
  sum[0] = a[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
  long long res = 0;
  res = max((res), (solve(n)));
  res = max((res), (solve2(n)));
  printf(0 ? "%lld" : "%I64d", init + res);
  putchar('\n');
}
