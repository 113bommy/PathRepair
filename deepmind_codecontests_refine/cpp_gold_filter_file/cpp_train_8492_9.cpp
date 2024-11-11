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
long long binpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a;
    a *= a;
    b >>= 1;
  }
  return ret;
}
long long binpow(long long a, long long b, int mod) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ret;
}
inline int getbit(int x, int b) { return (x >> b) & 1; }
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
  return countbit(int(x & INT_MAX)) + countbit(int(x >> 31) & INT_MAX);
}
inline void printbit(int x, int len) {
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
template <typename A>
ostream &operator<<(ostream &stream, const deque<A> &v) {
  deque<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.front() << " ";
    q.pop_front();
  }
  stream << "]";
  return stream;
}
void run();
int main() {
  srand(time(NULL));
  run();
  return 0;
}
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
const int M = 50;
struct SegmentTree {
  vector<int> root;
  vector<int> tr, lp, rp;
  int free_idx = 1;
  int n;
  SegmentTree(int _n) : n(_n) {
    tr.resize(N * M);
    lp.resize(N * M);
    rp.resize(N * M);
    root.resize(1);
  }
  int get(int &v, int l, int r, int sum) {
    if (v == 0 || l == r) return l;
    int mid = (l + r) >> 1;
    if (tr[lp[v]] >= sum)
      return get(lp[v], l, mid, sum);
    else
      return get(rp[v], mid + 1, r, sum - tr[lp[v]]);
  }
  int get(int ver, int sum) { return get(root[ver], 0, n - 1, sum); }
  void set(int &v, int l, int r, int pos, int val) {
    int old = v;
    v = free_idx++;
    tr[v] = tr[old];
    lp[v] = lp[old];
    rp[v] = rp[old];
    if (l == r)
      tr[v] = val;
    else {
      int mid = (l + r) >> 1;
      if (pos <= mid)
        set(lp[v], l, mid, pos, val);
      else
        set(rp[v], mid + 1, r, pos, val);
      tr[v] = tr[lp[v]] + tr[rp[v]];
    }
  }
  int set(int pos, int val) {
    root.push_back(0);
    root.back() = root[((int)root.size()) - 2];
    set(root.back(), 0, n - 1, pos, val);
    return ((int)root.size()) - 1;
  }
  int sum(int ver) { return tr[root[ver]]; }
};
int a[N];
int lst[N];
int ver[N];
int res[N];
void run() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  SegmentTree tree(n + 5);
  for (int i = n - 1; i >= 0; --i) {
    if (lst[a[i]] > 0) tree.set(lst[a[i]], 0);
    ver[i] = tree.set(i, 1);
    lst[a[i]] = i;
  }
  for (int i = n; i >= 1; --i) {
    res[i] = 1;
    int l = 0;
    while (tree.sum(ver[l]) > i) {
      ++res[i];
      l = tree.get(ver[l], i + 1);
    }
  }
  for (int i = 1; i <= n; ++i, putchar(' ')) printf("%d", res[i]);
  putchar('\n');
}
