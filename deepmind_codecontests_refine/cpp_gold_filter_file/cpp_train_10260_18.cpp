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
  run();
  return 0;
}
const int mod = 1e9 + 7;
const int N = 100005;
struct SegmentTreeMap {
  vector<int> tr;
  int n;
  SegmentTreeMap(int _n) : n(_n) { tr.resize(4 * n); }
  void change(int v, int l, int r, int pos, int val) {
    if (l == r)
      tr[v] += val;
    else {
      int mid = (l + r) >> 1;
      if (pos <= mid)
        change(v + v, l, mid, pos, val);
      else
        change(v + v + 1, mid + 1, r, pos, val);
      tr[v] = tr[v + v] | tr[v + v + 1];
    }
  }
  void inc(int pos) { change(1, 0, n - 1, pos, 1); }
  void dec(int pos) { change(1, 0, n - 1, pos, -1); }
  void push_to_queue(int v, int l, int r, deque<pair<int, int> > &q) {
    if (tr[v] == 0) return;
    if (l == r) {
      q.push_back({l, tr[v]});
    } else {
      int mid = (l + r) >> 1;
      push_to_queue(v + v, l, mid, q);
      push_to_queue(v + v + 1, mid + 1, r, q);
    }
  }
  void push_to_queue(deque<pair<int, int> > &q) {
    push_to_queue(1, 0, n - 1, q);
  }
};
struct query {
  int l, r, idx, l_idx;
  query(int _l = 0, int _r = 0, int _idx = 0)
      : l(_l), r(_r), l_idx(l / 300), idx(_idx) {}
  bool operator<(const query &other) const {
    if (l_idx == other.l_idx)
      return (l_idx & 1) ? (r < other.r) : (r > other.r);
    return l_idx < other.l_idx;
  }
};
int a[N];
vector<query> qs(N);
int cnt[N];
SegmentTreeMap mp(N);
int res[N];
deque<pair<int, int> > x, y;
inline pair<int, int> get(deque<pair<int, int> > &d) {
  return d.empty() ? make_pair(INT_MAX, INT_MAX) : d.front();
}
inline void writeln(int x) {
  char buf[8];
  int k = 0;
  do {
    buf[k++] = x % 10;
    x /= 10;
  } while (x > 0);
  while (k--) putchar(buf[k] + '0');
  putchar('\n');
}
int calc() {
  mp.push_to_queue(x);
  int res = 0;
  while (!(x.empty() && y.empty())) {
    0 ? (cout << "x"
              << " = " << (x) << ","
              << "y"
              << " = " << (y) << "\n")
      : cout;
    if (get(x).first <= get(y).first) {
      auto it = get(x);
      x.pop_front();
      if (it.second == 1) {
        auto it2 = min(get(x), get(y));
        if (it2.first == INT_MAX) continue;
        if (it2 == get(x))
          x.pop_front();
        else
          y.pop_front();
        res += it.first + it2.first;
        y.push_back({it.first + it2.first, 1});
        if (it2.second > 1) {
          if (it2.first <= get(x).first)
            x.push_front({it2.first, it2.second - 1});
          else
            y.push_front({it2.first, it2.second - 1});
        }
      } else {
        int c = it.second / 2;
        res += it.first * (it.second - it.second % 2);
        y.push_back({it.first * 2, c});
        if (it.second & 1) x.push_front({it.first, 1});
      }
    } else {
      auto it = get(y);
      y.pop_front();
      if (it.second == 1) {
        auto it2 = min(get(x), get(y));
        if (it2.first == INT_MAX) continue;
        if (it2 == get(x))
          x.pop_front();
        else
          y.pop_front();
        res += it.first + it2.first;
        y.push_back({it.first + it2.first, 1});
        if (it2.second > 1) {
          if (it2.first <= get(x).first)
            x.push_front({it2.first, it2.second - 1});
          else
            y.push_front({it2.first, it2.second - 1});
        }
      } else {
        int c = it.second / 2;
        res += it.first * (it.second - it.second % 2);
        y.push_back({it.first * 2, c});
        if (it.second & 1) y.push_front({it.first, 1});
      }
    }
  }
  return res;
}
void run() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) read_integer(a[i]);
  int q, l, r;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    read_integer(l);
    read_integer(r);
    qs[i] = query(l - 1, r - 1, i);
  }
  sort(qs.begin(), qs.begin() + q);
  l = 0, r = -1;
  for (int i = 0; i < q; ++i) {
    query &cur = qs[i];
    while (cur.l < l) {
      --l;
      if (cnt[a[l]]) mp.dec(cnt[a[l]]);
      cnt[a[l]]++;
      mp.inc(cnt[a[l]]);
    }
    while (r < cur.r) {
      ++r;
      if (cnt[a[r]]) mp.dec(cnt[a[r]]);
      ++cnt[a[r]];
      mp.inc(cnt[a[r]]);
    }
    while (l < cur.l) {
      mp.dec(cnt[a[l]]);
      cnt[a[l]]--;
      if (cnt[a[l]] > 0) mp.inc(cnt[a[l]]);
      ++l;
    }
    while (r > cur.r) {
      mp.dec(cnt[a[r]]);
      cnt[a[r]]--;
      if (cnt[a[r]] > 0) mp.inc(cnt[a[r]]);
      --r;
    }
    res[cur.idx] = calc();
  }
  for (int i = 0; i < q; ++i) writeln(res[i]);
}
