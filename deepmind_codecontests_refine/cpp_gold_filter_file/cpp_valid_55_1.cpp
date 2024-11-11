#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> P) {
  for (auto const &vv : P) os << "(" << vv.first << "," << vv.second << ")";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  os << "(" << P.first << "," << P.second << ")";
  return os;
}
inline int fstoi(const string &str) {
  auto it = str.begin();
  bool neg = 0;
  int num = 0;
  if (*it == '-')
    neg = 1;
  else
    num = *it - '0';
  ++it;
  while (it < str.end()) num = num * 10 + (*it++ - '0');
  if (neg) num *= -1;
  return num;
}
inline void getch(char &x) {
  while (x = getchar_unlocked(), x < 33) {
    ;
  }
}
inline void getstr(string &str) {
  str.clear();
  char cur;
  while (cur = getchar_unlocked(), cur < 33) {
    ;
  }
  while (cur > 32) {
    str += cur;
    cur = getchar_unlocked();
  }
}
template <typename T>
inline bool sc(T &num) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    if (c == EOF) return false;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  return true;
}
template <typename T, typename... Args>
inline void sc(T &num, Args &...args) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    ;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  sc(args...);
}
std::pair<int, int> t[1000001 << 2];
bool mark[1000001 << 2];
void build(int v, int tl, int tr, std::pair<int, int> arr[]) {
  if (tl == tr) {
    t[v] = arr[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  build(v << 1, tl, tm, arr);
  build(v << 1 | 1, tm + 1, tr, arr);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}
void push(int v) {
  t[v << 1] = t[v << 1 | 1] = t[v];
  mark[v << 1] = mark[v << 1 | 1] = 1;
  mark[v] = 0;
}
void modify(int v, int tl, int tr, int l, int r, std::pair<int, int> val) {
  if (l > r) return;
  if (tl == l && tr == r) {
    t[v] = val;
    mark[v] = 1;
    return;
  }
  if (mark[v]) push(v);
  int tm = (tl + tr) >> 1;
  modify(v << 1, tl, tm, l, min(tm, r), val);
  modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}
std::pair<int, int> query(int v, int tl, int tr, int l, int r) {
  if (l > r) return {1000001, 0};
  if (tl == l && tr == r) {
    return t[v];
  }
  if (mark[v]) push(v);
  int tm = (tl + tr) >> 1;
  return min(query(v << 1, tl, tm, l, min(tm, r)),
             query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  sc(n, m);
  std::vector<int> vec;
  int segs[m][3];
  for (auto &i : segs) {
    for (auto &i : (i)) sc(i);
    --i[0];
    vec.push_back(i[1]);
    vec.push_back(i[2]);
  }
  sort(begin(vec), end(vec));
  vec.erase(unique(begin(vec), end(vec)), vec.end());
  int nn = vec.size();
  std::pair<int, int> arr[nn];
  for (int i = (0); i < int((nn)); ++i) arr[i] = {0, -1};
  build(1, 0, nn - 1, arr);
  vector<std::pair<int, int> > rows[n];
  for (auto &i : segs) {
    i[1] = lower_bound(begin(vec), end(vec), i[1]) - vec.begin();
    i[2] = lower_bound(begin(vec), end(vec), i[2]) - vec.begin();
    rows[i[0]].push_back({i[1], i[2]});
  }
  int res = n;
  int pr[n];
  int resid = -1;
  for (int i = (0); i < int((n)); ++i) {
    int cr = n;
    int whpr = -1;
    for (auto &x : rows[i]) {
      std::pair<int, int> crrec = query(1, 0, nn - 1, x.first, x.second);
      if (i + crrec.first < cr) {
        cr = i + crrec.first;
        whpr = crrec.second;
      }
    }
    pr[i] = whpr;
    int put = cr + (n - i - 1);
    if (put < res) {
      res = put;
      resid = i;
    }
    for (auto &x : rows[i]) {
      modify(1, 0, nn - 1, x.first, x.second, {cr - i - 1, i});
    }
  }
  cout << res << '\n';
  std::vector<int> resvec;
  while (resid != -1) {
    resvec.push_back(resid);
    resid = pr[resid];
  }
  reverse(begin(resvec), end(resvec));
  auto it = resvec.begin();
  for (int i = (0); i < int((n)); ++i) {
    while (it != resvec.end() && *it < i) ++it;
    if (*it != i) cout << i + 1 << ' ';
  }
  cout << '\n';
}
