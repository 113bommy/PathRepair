#include <bits/stdc++.h>
using namespace std;
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void yes(bool t = 1) { cout << yesno[t] << endl; }
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) {
  scan(p.first), scan(p.second);
}
template <class T>
void scan(vector<T> &);
template <class T>
void scan(vector<T> &a) {
  for (auto &i : a) scan(i);
}
template <class T>
void scan(T &a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}
vector<int> iota(int n) {
  vector<int> a(n);
  iota(begin(a), end(a), 0);
  return a;
}
template <typename T>
vector<int> iota(vector<T> &a, bool greater = false) {
  vector<int> res(a.size());
  iota(begin(res), end(res), 0);
  sort(begin(res), end(res), [&](int i, int j) {
    if (greater) return a[i] > a[j];
    return a[i] < a[j];
  });
  return res;
}
template <class T>
T POW(T x, int n) {
  T res = 1;
  for (; n; n >>= 1, x *= x)
    if (n & 1) res *= x;
  return res;
}
vector<pair<long long, long long>> factor(long long x) {
  vector<pair<long long, long long>> ans;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) {
      ans.push_back({i, 1});
      while ((x /= i) % i == 0) ans.back().second++;
    }
  if (x != 1) ans.push_back({x, 1});
  return ans;
}
template <class T>
vector<T> divisor(T x) {
  vector<T> ans;
  for (T i = 1; i * i <= x; i++)
    if (x % i == 0) {
      ans.push_back(i);
      if (i * i != x) ans.push_back(x / i);
    }
  return ans;
}
template <typename T>
void zip(vector<T> &x) {
  vector<T> y = x;
  sort(begin(y), end(y));
  for (int i = 0; i < x.size(); ++i) {
    x[i] = distance((y).begin(), lower_bound(begin(y), end(y), (x[i])));
  }
}
int popcount(long long x) { return __builtin_popcountll(x); }
int in() {
  int x;
  cin >> x;
  return x;
}
long long lin() {
  unsigned long long x;
  cin >> x;
  return x;
}
template <typename T>
struct edge {
  int from, to;
  T cost;
  int id;
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
  edge(int from, int to, T cost, int id)
      : from(from), to(to), cost(cost), id(id) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T>
using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
  Tree res(n);
  if (m == -1) m = n - 1;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a -= margin, b -= margin;
    res[a].emplace_back(b);
    if (!directed) res[b].emplace_back(a);
  }
  return move(res);
}
template <class T>
Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
  Wgraph<T> res(n);
  if (m == -1) m = n - 1;
  while (m--) {
    int a, b;
    T c;
    cin >> a >> b >> c;
    a -= margin, b -= margin;
    res[a].emplace_back(b, c);
    if (!directed) res[b].emplace_back(a, c);
  }
  return move(res);
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it = begin(v); it != end(v); ++it) {
    if (it == begin(v))
      os << *it;
    else
      os << " " << *it;
  }
  return os;
}
template <class T, class S>
ostream &operator<<(ostream &os, const pair<T, S> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <class S, class T>
string to_string(pair<S, T> p) {
  return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
}
template <class A>
string to_string(A v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto &x : v) ret += to_string(x) + ",";
  ret.back() = '}';
  return ret;
}
void dump() { cerr << endl; }
template <class Head, class... Tail>
void dump(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  dump(tail...);
}
template <typename T>
static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io {
  Setup_io() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
  }
} setup_io;
constexpr int N = 200001;
int a[N];
struct Mo {
  int n;
  vector<pair<int, int>> lr;
  explicit Mo(int n) : n(n) {}
  void add(int l, int r) { lr.emplace_back(l, r); }
  template <typename AL, typename AR, typename EL, typename ER, typename O>
  void build(const AL &add_left, const AR &add_right, const EL &erase_left,
             const ER &erase_right, const O &out) {
    int q = (int)lr.size();
    int bs = n / min<int>(n, sqrt(q));
    vector<int> ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if (ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? lr[a].second > lr[b].second
                          : lr[a].second < lr[b].second;
    });
    int l = 0, r = 0;
    for (auto idx : ord) {
      while (l > lr[idx].first) add_left(--l);
      while (r < lr[idx].second) add_right(r++);
      while (l < lr[idx].first) erase_left(l++);
      while (r > lr[idx].second) erase_right(--r);
      out(idx);
    }
  }
  template <typename A, typename E, typename O>
  void build(const A &add, const E &erase, const O &out) {
    build(add, add, erase, erase, out);
  }
};
int freq[N], s[N + 1];
int main() {
  int n;
  IN(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) a[i]--;
  const int T = 451;
  vector<int> cnt(n);
  for (long long i = 0; i < n; ++i) cnt[a[i]]++;
  int ma = 0, idx;
  int ans = 0;
  for (long long i = 0; i < n; ++i)
    if (chmax(ma, cnt[i])) idx = i;
  {
    vector<int> _mp(n * 2 + 1, -1);
    auto mp = _mp.begin() + n;
    for (long long t = 0; t < n; ++t) {
      if (t == idx) continue;
      if (cnt[t] < T) continue;
      mp[0] = 0;
      int cnt = 0;
      for (long long i = 0; i < n; ++i) {
        if (a[i] == idx)
          cnt++;
        else if (a[i] == t)
          cnt--;
        if (mp[cnt] != -1)
          chmax(ans, i + 1 - mp[cnt]);
        else
          mp[cnt] = i + 1;
      }
      for (long long i = -n; i <= n; ++i) mp[i] = -1;
    }
  }
  vector<int> id;
  for (long long i = 0; i < n; ++i)
    if (a[i] == idx) id.emplace_back(i + 1);
  for (long long i = 0; i < n; ++i) freq[a[i]] = 0, s[0]++;
  id.insert(id.begin(), 0);
  for (auto e : id) {
    int cnt = 0;
    for (long long i = e; i <= n - 1; ++i) {
      if (a[i] == idx) {
        cnt++;
        if (cnt == T) break;
      } else {
        s[freq[a[i]]]--;
        s[++freq[a[i]]]++;
      }
      if (s[cnt]) chmax(ans, i + 1 - e);
    }
    cnt = 0;
    for (long long i = e; i <= n - 1; ++i) {
      if (a[i] == idx) {
        cnt++;
        if (cnt == T) break;
      } else {
        s[freq[a[i]]--]--;
        s[freq[a[i]]]++;
      }
    }
  }
  cout << ans << '\n';
}
