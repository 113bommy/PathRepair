#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll llinf = (1ll << 61) - 1;
const double eps = 1e-6, ldeps = 1e-9;
struct Dbg {
  static constexpr auto &os = cout;
  template <class C>
  static auto dud(C *x) -> decltype(os << *x, 0);
  template <class C>
  static char dud(...);
  template <class C>
  typename enable_if<sizeof dud<C>(0) != 1, Dbg &>::type operator<<(
      const C &x) {
    os << x;
    return *this;
  }
  template <class C>
  Dbg &dump(C b, C e) {
    *this << "\n[";
    int cur = 0;
    for (C i = b; i != e and cur < 26; i++, cur++)
      *this << ", " + 2 * (i == b) << *i;
    return *this << ']';
  }
  template <class C>
  typename enable_if<sizeof dud<C>(0) == 1, Dbg &>::type operator<<(
      const C &x) {
    return dump(begin(x), end(x));
  }
  template <class C, size_t X>
  typename enable_if<sizeof(C) != 1, Dbg &>::type operator<<(C (&x)[X]) {
    return dump(begin(x), end(x));
  }
  template <class B, class C>
  Dbg &operator<<(const pair<B, C> &x) {
    return *this << '{' << x.first << ", " << x.second << '}';
  }
  template <class C, size_t Y>
  struct TP {
    void operator()(Dbg &os, const C &t) {
      TP<C, Y - 1>()(os, t);
      os << ", " << get<Y - 1>(t);
    }
  };
  template <class C>
  struct TP<C, 1> {
    void operator()(Dbg &os, const C &t) { os << get<0>(t); }
  };
  template <class... C>
  Dbg &operator<<(const tuple<C...> &t) {
    os << '{', TP<decltype(t), sizeof...(C)>()(*this, t);
    return *this << '}';
  }
  Dbg &operator<<(ostream &(*x)(std::ostream &)) {
    os << x;
    return *this;
  }
} dbg;
void err(istringstream *iss) { delete iss; }
template <class C, class... Args>
void err(istringstream *iss, const C &val, const Args &...args) {
  string name;
  *iss >> name;
  if (name.back() == ',') name.pop_back();
  dbg << name << " = " << val << "; ", err(iss, args...);
}
int m, K, T, Q, cn;
const int inf = 1000000007, mxn = 21;
vector<int> borrow[mxn];
vector<pair<int, int> > os[mxn];
deque<int> a;
ll n, ans[7];
pair<int, int> o[7][mxn];
int nxt[7][mxn];
bitset<mxn> vstd[7];
bool memo[7][mxn];
bool dp(int b, int at) {
  if (!at) return !b;
  bool &ret = memo[b][at];
  if (vstd[b][at]) return ret;
  vstd[b][at] = 1;
  int x = a[at] - b + 10 * (a[at] < b);
  ret = 0;
  auto it = os[x].begin();
  for (auto &i : borrow[x]) {
    if (dp((a[at] < b) + i, at - 1)) {
      ret = 1, o[b][at] = *it, nxt[b][at] = (a[at] < b) + i;
      break;
    }
    it++;
  }
  return ret;
}
void resetAll() { memset(vstd, 0, sizeof(vstd)), a.clear(); }
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.precision(11);
  for (int i = 0; i <= 6; i++) {
    for (int j = 0; i + j <= 6; j++) {
      int x = i * 4 + j * 7;
      borrow[x % 10].push_back(x / 10), os[x % 10].push_back({i, j});
    }
  }
  cin >> T;
  while (cn++ != T) {
    resetAll();
    cin >> n;
    while (n) {
      a.push_front(int(n % 10)), n /= 10;
    }
    a.push_front(0);
    auto x = dp(0, int(a.size()) - 1);
    if (!x) {
      cout << "-1\n";
      continue;
    }
    memset(ans, 0, sizeof(ans));
    int b = 0, p10 = 1;
    for (int i = int(a.size()) - 1; i >= 1; i--) {
      for (int j = 0; j < o[b][i].first; j++) {
        ans[j] += p10 * 4;
      }
      for (int j = 0; j < o[b][i].second; j++) {
        ans[j + o[b][i].first] += p10 * 7;
      }
      b = nxt[b][i], p10 *= 10;
    }
    for (int i = 0; i < 6; i++) {
      cout << ans[i] << " \n"[i == 5];
    }
  }
}
