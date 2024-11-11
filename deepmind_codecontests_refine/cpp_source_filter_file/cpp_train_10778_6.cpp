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
  if (b == 0) return 1;
  long long c = binpowmod(a, b >> 1, mod);
  return (((c * c) % mod) * (b & 1 ? a : 1)) % mod;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long c = binpow(a, b >> 1);
  return c * c * (b & 1 ? a : 1);
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
  return countbit(int(x & INT_MAX)) + countbit(int(x >> 32) & INT_MAX);
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
  do {
    run();
    if (0) {
      0 ? printf("-------------------------------\n") : 0;
      0 ? printf("-------------------------------\n") : 0;
    }
  } while (0);
  return 0;
}
const int mod = 1e9 + 7;
int a[200005 + 5];
vector<int> v[200005 + 5];
struct SegmentTree {
  vector<long long> tr;
  vector<int> mn;
  vector<int> mnpos;
  vector<int> psh;
  int n;
  SegmentTree(int cnt) : n(cnt) {
    tr.resize(4 * n);
    mn.resize(4 * n);
    mnpos.resize(4 * n);
    psh.resize(4 * n, -1);
    build(1, 0, n - 1);
  }
  void build(int v, int l, int r) {
    if (l == r) {
      tr[v] = l;
      mn[v] = l;
      mnpos[v] = l;
    } else {
      int mid = (l + r) >> 1;
      build(v + v, l, mid);
      build(v + v + 1, mid + 1, r);
      merge(v);
    }
  }
  void merge(int v) {
    tr[v] = tr[v + v] + tr[v + v + 1];
    mn[v] = mn[v + v];
    if (mn[v + v] < mn[v + v + 1])
      mnpos[v] = mnpos[v + v];
    else
      mnpos[v] = mnpos[v + v + 1];
  }
  void push(int v, int l, int r) {
    if (psh[v] == -1 || l == r) return;
    int mid = (l + r) >> 1;
    update(v + v, l, mid, l, mid, psh[v]);
    update(v + v + 1, mid + 1, r, mid + 1, r, psh[v]);
    psh[v] = -1;
  }
  void update(int v, int l, int r, int L, int R, int val) {
    if (R < L) return;
    if (l == L && r == R) {
      tr[v] = 1ll * (r - l + 1) * val;
      psh[v] = val;
      mn[v] = val;
      mnpos[v] = r;
    } else {
      int mid = (l + r) >> 1;
      push(v, l, r);
      update(v + v, l, mid, L, min(mid, R), val);
      update(v + v + 1, mid + 1, r, max(mid + 1, L), R, val);
      merge(v);
    }
  }
  void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }
  int query(int v, int l, int r, int k) {
    if (mn[v] >= k) return -1;
    if (l == r) return l;
    push(v, l, r);
    int mid = (l + r) >> 1;
    if (mn[v + v + 1] < k)
      return query(v + v + 1, mid + 1, r, k);
    else
      return query(v + v, l, mid, k);
  }
  int query(int k) { return query(1, 0, n - 1, k); }
  int sum() { return tr[1]; }
};
long long H[200005 + 5];
void run() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    int to = sqrt(a[i]);
    for (int j = 1; j <= to; ++j) {
      if (a[i] % j == 0) {
        v[j].push_back(i);
        if (j * j != a[i]) v[a[i] / j].push_back(i);
      }
    }
  }
  SegmentTree tree(n);
  for (int i = 200005; i > 0; --i) {
    if (((int)v[i].size()) > 1) {
      tree.update(0, min(v[i][0], tree.query(v[i][((int)v[i].size()) - 2])),
                  v[i][((int)v[i].size()) - 2]);
      tree.update(v[i][0] + 1, min(v[i][1], tree.query(v[i].back())),
                  v[i].back());
      tree.update(v[i][1] + 1, n - 1, n);
    }
    H[i] = 1ll * n * n - tree.sum();
  }
  long long res = 0;
  for (int i = 1; i < 200005; ++i) res += (H[i + 1] - H[i]) * i;
  printf(0 ? "%lld" : "%I64d", res);
  putchar('\n');
}
