#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const double inf = 1e121;
const double eps = 1e-10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long l, long long r) {
  long long out = rng() % (r - l + 1) + l;
  return out >= l ? out : out + r - l + 1;
}
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
  for (long long i = 0; i < static_cast<long long>(v.size()); i++) {
    if (!first) {
      res += ",";
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
      res += ",";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + "," + to_string(get<1>(p)) + "," +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + "," + to_string(get<1>(p)) + "," +
         to_string(get<2>(p)) + "," + to_string(get<3>(p)) + ")";
}
template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
  return "(" + to_string(get<0>(p)) + "," + to_string(get<1>(p)) + "," +
         to_string(get<2>(p)) + "," + to_string(get<3>(p)) + "," +
         to_string(get<4>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long INF = 0x3f3f3f3f3f3f3f3fll;
template <typename T>
typename enable_if<!is_integral<T>::value, void>::type read(T& x) {
  cin >> x;
}
long long read() {
  char c;
  long long out = 0, f = 1;
  for (c = getchar(); !isdigit(c) && c != '-'; c = getchar())
    ;
  if (c == '-') {
    f = -1;
    c = getchar();
  }
  for (; isdigit(c); c = getchar()) out = (out << 3) + (out << 1) + c - '0';
  return out * f;
}
template <typename T>
typename enable_if<is_integral<T>::value, T>::type read(T& x) {
  char c;
  T f = 1;
  x = 0;
  for (c = getchar(); !isdigit(c) && c != '-'; c = getchar())
    ;
  if (c == '-') {
    f = -1;
    c = getchar();
  }
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  return x *= f;
}
char read(char& x) {
  for (x = getchar(); isspace(x); x = getchar())
    ;
  return x;
}
double read(double& x) {
  scanf("%lf", &x);
  return x;
}
long double read(long double& x) {
  scanf("%Lf", &x);
  return x;
}
template <typename T>
typename enable_if<!is_integral<T>::value, void>::type write(const T& x) {
  cout << x;
}
template <typename T>
typename enable_if<is_integral<T>::value, void>::type write(const T& x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void write(const char& x) { putchar(x); }
void write(const double& x) { printf("%.10lf", x); }
void write(const long double& x) { printf("%.10Lf", x); }
template <typename T, typename... Args>
void read(T& x, Args&... args) {
  read(x);
  read(args...);
}
template <
    typename OutputIt,
    typename = typename enable_if<
        is_same<output_iterator_tag,
                typename iterator_traits<OutputIt>::iterator_category>::value ||
        (is_base_of<forward_iterator_tag, typename iterator_traits<OutputIt>::
                                              iterator_category>::value &&
         !is_const<OutputIt>::value)>::type>
void read(OutputIt __first, OutputIt __last) {
  for (; __first != __last; ++__first) read(*__first);
}
template <
    typename InputIt,
    typename = typename enable_if<is_base_of<
        input_iterator_tag,
        typename iterator_traits<InputIt>::iterator_category>::value>::type>
void wts(InputIt __first, InputIt __last) {
  bool isFirst = true;
  for (; __first != __last; ++__first) {
    if (isFirst)
      isFirst = false;
    else
      putchar(' ');
    write(*__first);
  }
  putchar('\n');
}
template <
    typename InputIt,
    typename = typename enable_if<is_base_of<
        input_iterator_tag,
        typename iterator_traits<InputIt>::iterator_category>::value>::type>
void wtb(InputIt __first, InputIt __last) {
  for (; __first != __last; ++__first) {
    write(*__first);
    putchar('\n');
  }
}
template <typename T>
void wts(const T& x) {
  write(x);
  putchar(' ');
}
template <typename T>
void wtb(const T& x) {
  write(x);
  putchar('\n');
}
template <typename T>
void wte(const T& x) {
  write(x);
  exit(0);
}
template <typename T, typename... Args>
void wts(const T& x, Args... args) {
  wts(x);
  wts(args...);
}
template <typename T, typename... Args>
void wtb(const T& x, Args... args) {
  wts(x);
  wtb(args...);
}
template <typename T, typename... Args>
void wte(const T& x, Args... args) {
  wts(x);
  wte(args...);
}
template <typename T>
inline bool up(T& x, const T& y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool dn(T& x, const T& y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool inRange(const T& x, const T& l, const T& r) {
  return !(x < l) && !(r < x);
}
template <typename valueType, typename tagType>
class segmentTreeNode {
 public:
  long long id, left, right;
  valueType val;
  tagType tag;
};
template <typename valueType, typename tagType,
          valueType (*merge)(valueType, valueType),
          void (*update)(segmentTreeNode<valueType, tagType>&, tagType)>
class segmentTree {
 private:
  std::vector<segmentTreeNode<valueType, tagType>> nodes;
  long long leftRange, rightRange;
  valueType valueZero;
  tagType tagZero;
  void pushup(long long cur) {
    nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
  }
  void pushdown(long long cur) {
    update(nodes[cur << 1], nodes[cur].tag);
    update(nodes[cur << 1 | 1], nodes[cur].tag);
    nodes[cur].tag = tagZero;
  }
  void build(long long cur, long long l, long long r,
             const std::vector<valueType>& initValue) {
    nodes[cur].id = cur;
    nodes[cur].left = l;
    nodes[cur].right = r;
    nodes[cur].tag = tagZero;
    if (l == r - 1)
      nodes[cur].val = initValue[l - leftRange];
    else {
      build(cur << 1, l, (l + r) >> 1, initValue);
      build(cur << 1 | 1, (l + r) >> 1, r, initValue);
      pushup(cur);
    }
  }
  void init(const std::vector<valueType>& _initValue,
            const valueType& _valueZero, const tagType& _tagZero) {
    valueZero = _valueZero;
    tagZero = _tagZero;
    nodes.resize((rightRange - leftRange) << 2);
    build(1, leftRange, rightRange, _initValue);
  }
  void modify(long long cur, long long l, long long r, long long L, long long R,
              const tagType& tag) {
    if (l >= R || r <= L) return;
    if (L <= l && r <= R)
      update(nodes[cur], tag);
    else {
      pushdown(cur);
      modify(cur << 1, l, (l + r) >> 1, L, R, tag);
      modify(cur << 1 | 1, (l + r) >> 1, r, L, R, tag);
      pushup(cur);
    }
  }
  valueType query(long long cur, long long l, long long r, long long L,
                  long long R) {
    if (l >= R || r <= L) return valueZero;
    if (L <= l && r <= R) return nodes[cur].val;
    pushdown(cur);
    return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                 query(cur << 1 | 1, (l + r) >> 1, r, L, R));
  }

 public:
  segmentTree() {}
  segmentTree(long long _leftRange, long long _rightRange,
              const std::vector<valueType>& _initValue,
              const valueType& _valueZero, const tagType& _tagZero) {
    leftRange = _leftRange;
    rightRange = _rightRange;
    init(_initValue, _valueZero, _tagZero);
  }
  segmentTree(long long size, const std::vector<valueType>& _initValue,
              const valueType& _valueZero, const tagType& _tagZero) {
    leftRange = 1;
    rightRange = size + 1;
    init(_initValue, _valueZero, _tagZero);
  }
  void modify(long long l, long long r, const tagType& tag) {
    modify(1, leftRange, rightRange, l, r, tag);
  }
  void modify(long long p, const tagType& tag) { modify(p, p + 1, tag); }
  valueType query(long long l, long long r) {
    return query(1, leftRange, rightRange, l, r);
  }
  valueType query(long long p) { return query(p, p + 1); }
};
class maxFlow {
 private:
  std::queue<long long> q;
  std::vector<long long> head, cur, nxt, to, dep;
  std::vector<long long> cap;

 public:
  maxFlow(long long _n = 0) { init(_n); }
  void init(long long _n) {
    head.clear();
    head.resize(_n + 1, 0);
    nxt.resize(2);
    to.resize(2);
    cap.resize(2);
  }
  void init() { init(head.size() - 1); }
  void add(long long u, long long v, long long w) {
    nxt.push_back(head[u]);
    head[u] = to.size();
    to.push_back(v);
    cap.push_back(w);
  }
  void Add(long long u, long long v, long long w) {
    add(u, v, w);
    add(v, u, 0);
  }
  void del(long long x) { cap[x << 1] = cap[x << 1 | 1] = 0; }
  bool bfs(long long s, long long t) {
    dep.clear();
    dep.resize(head.size(), -1);
    dep[s] = 0;
    q.push(s);
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      for (long long i = head[u]; i; i = nxt[i]) {
        long long v = to[i];
        long long w = cap[i];
        if (w > 0 && dep[v] == -1) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return ~dep[t];
  }
  long long dfs(long long u, long long flow, long long t) {
    if (dep[u] == dep[t]) return u == t ? flow : 0;
    long long out = 0;
    for (long long& i = cur[u]; i; i = nxt[i]) {
      long long v = to[i];
      long long w = cap[i];
      if (w > 0 && dep[v] == dep[u] + 1) {
        long long f = dfs(v, std::min(w, flow - out), t);
        cap[i] -= f;
        cap[i ^ 1] += f;
        out += f;
        if (out == flow) return out;
      }
    }
    return out;
  }
  long long maxflow(long long s, long long t) {
    long long out = 0;
    while (bfs(s, t)) {
      cur = head;
      out += dfs(s, 0x7fffffffffffffffll, t);
    }
    return out;
  }
  long long getflow(long long x) const { return cap[x << 1 | 1]; }
};
struct customHash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = rng();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const long long mod = 998244353;
long long qpow(long long x, long long y) {
  long long out = 1;
  while (y) {
    if (y & 1) out = out * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return out;
}
set<long long> s;
long long n, q, ans;
vector<long long> p, inv, sum, mul;
long long calc(long long l, long long r) {
  return (sum[r - 1] - sum[l - 1]) * mul[r - 1] % mod;
}
signed main() {
  read(n, q);
  p.resize(n + 1);
  read(p.begin() + 1, p.end());
  inv.resize(101);
  for (long long i = (1), iend = (100); i <= iend; ++i)
    inv[i] = qpow(i, mod - 2);
  mul.resize(n + 1, 1);
  sum.resize(n + 1, 0);
  long long tmp = 1;
  for (long long i = (1), iend = (n); i <= iend; ++i) {
    mul[i] = mul[i - 1] * inv[p[i]] % mod * 100 % mod;
    sum[i] = (sum[i - 1] + tmp) % mod;
    tmp = tmp * p[i] % mod * inv[100] % mod;
  }
  ans = calc(1, n + 1);
  s.insert(1);
  s.insert(n + 1);
  while (q--) {
    long long x = read();
    auto it = s.lower_bound(x);
    if (*it == x) {
      ans = (ans - calc(*prev(it), x) - calc(x, *next(it)) +
             calc(*prev(it), *next(it)) + 2 * mod) %
            mod;
      s.erase(it);
    } else {
      ans = (ans - calc(*prev(it), *it) + mod + calc(*prev(it), x) +
             calc(x, *it)) %
            mod;
      s.insert(x);
    }
    wtb(ans);
  }
  return 0;
}
