#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7;
template <class A, class B>
pair<A, B> operator+(pair<A, B>& a, pair<A, B>& b) {
  return {a.first + b.first, a.second + b.second};
}
template <class A, class B>
pair<A, B> operator-(pair<A, B>& a, pair<A, B>& b) {
  return {a.first - b.first, a.second - b.second};
}
template <class A, class B>
istream& operator>>(istream& is, pair<A, B>& a) {
  return is >> a.first >> a.second;
}
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& a) {
  return os << "< " << a.first << " , " << a.second << " >";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
  os << '[';
  if (!v.empty()) {
    os << v[0];
    for (int i = (1); i < (v.size()); i++) os << ',' << v[i];
  }
  return os << ']';
}
template <class T>
ostream& operator<<(ostream& os, set<T> v) {
  os << '{';
  if (!v.empty()) {
    os << *v.begin();
    for (auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it;
  }
  return os << '}';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);
const int MAX = 1e6 + 10;
int c, n;
int divs[MAX];
void precalc() {
  fill(divs, divs + MAX, -1);
  for (int i = (2); i < (MAX); i++) {
    if (divs[i] != -1) continue;
    for (int j = i; j < MAX; j += i) divs[j] = i;
  }
}
int f(int first) {
  int xx = first;
  vector<int> d;
  while (first > 1) {
    d.emplace_back(divs[first]), first /= divs[first];
  }
  sort(d.begin(), d.end()), d.resize(unique(d.begin(), d.end()) - d.begin());
  for (int dd : d) first *= dd;
  return first;
}
vector<vector<int>> solve(vector<int>& a, int need) {
  const int M = 260;
  int n = a.size();
  assert(n <= M);
  vector<bitset<20>> mat(n);
  vector<bitset<M>> who(n);
  for (int i = (0); i < (n); i++) mat[i] = a[i], who[i][i] = 1;
  int row = 0;
  vector<int> col(20, -1);
  for (int j = (0); j < (20); j++) {
    int good = -1;
    for (int i = (row); i < (n); i++)
      if (mat[i][j]) {
        good = i;
        break;
      }
    if (good == -1) continue;
    col[j] = row;
    swap(mat[row], mat[good]);
    swap(who[row], who[good]);
    for (int i = (row + 1); i < (n); i++)
      if (mat[i][j]) mat[i] ^= mat[row], who[i] ^= who[row];
    row++;
  }
  vector<bool> can(M + 1);
  vector<vector<int>> res;
  for (int it = (0); it < (400); it++) {
    bitset<M> w;
    bitset<20> b = need;
    for (int i = (row); i < (n); i++)
      if (rng() % 2) {
        if (mat[i] != 0) exit(4);
        w ^= who[i], b ^= mat[i];
      }
    for (int j = (0); j < (20); j++) {
      if (b[j]) {
        int i = col[j];
        assert(i != -1);
        w ^= who[i], b ^= mat[i];
      }
    }
    assert(b == 0);
    int sz = w.count();
    if (!can[sz]) {
      can[sz] = 1;
      res.emplace_back(vector<int>(0));
      for (int i = (0); i < (n); i++)
        if (w[i]) res.back().emplace_back(a[i]);
    }
    if (row == n) break;
  }
  return res;
}
void gauss(int need, vector<int>& lst, vector<int>& ans,
           vector<vector<int>>& sz, vector<vector<vector<int>>>& v) {
  int n = lst.size();
  vector<bitset<20>> a(n);
  for (int i = 0; i < n; i++) a[i] = lst[i];
  bitset<20> b = need;
  vector<bitset<260>> l(n);
  for (int i = 0; i < n; i++) l[i][i] = 1;
  int i = 0;
  vector<int> col(20, -1);
  int bas_sz = 0;
  for (int j = 0; j < 20 && i < n; j++) {
    int i1 = i;
    while (i1 < n && a[i1][j] == 0) i1++;
    if (i1 == n) continue;
    swap(a[i], a[i1]);
    swap(l[i], l[i1]);
    bas_sz++;
    col[j] = i;
    for (int i2 = i + 1; i2 < n; i2++) {
      if (a[i2][j]) {
        a[i2] ^= a[i];
        l[i2] ^= l[i];
      }
    }
    i++;
  }
  bitset<20> res;
  bitset<260> path;
  for (int j = 0; j < 20; j++) {
    if (res[j] != b[j] && col[j] == -1) {
      exit(0);
    }
    if (res[j] == b[j]) continue;
    res ^= a[col[j]];
    path ^= l[col[j]];
  }
  if (a.back().count() != 0) {
    for (int i = 0; i < n; i++) {
      if (path[i]) ans.emplace_back(lst[i]);
    }
    return;
  }
  vector<int> diff_sz(300);
  sz.emplace_back();
  v.emplace_back();
  for (int it = 0; it < 100; it++) {
    bitset<260> now = path;
    for (int i = 0; i < n - bas_sz; i++) {
      if (rng() % 2) now ^= l[bas_sz + i];
    }
    int now_sz = now.count();
    if (diff_sz[now_sz]) continue;
    v.back().emplace_back();
    for (int i = 0; i < n; i++) {
      if (now[i]) v.back().back().emplace_back(lst[i]);
    }
    diff_sz[now_sz] = 1;
    sz.back().emplace_back(now_sz);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin >> c >> n;
  precalc();
  vector<vector<int>> gs(c + 1);
  for (int i = (1); i < (c + 1); i++) {
    gs[f(i)].emplace_back(i);
  }
  vector<int> ask;
  for (int i = (1); i < (c + 1); i++)
    if (gs[i].size()) ask.emplace_back(i);
  vector<int> ans(c + 1);
  cout << ask.size() << " ";
  for (auto i : ask) cout << i << " ";
  cout << endl;
  for (int i : ask) {
    int first;
    cin >> first;
    ans[i] = first;
  }
  int all = ans[1];
  vector<int> lrg(c + 1);
  for (int i = (1); i < (c + 1); i++) {
    if (!gs[i].size()) continue;
    for (int j = i; j <= c; j += i) lrg[j] ^= (ans[i] ^ all);
  }
  lrg[1] = all;
  vector<int> exc = lrg;
  for (int i = (c + 1) - 1; i >= (1); i--) {
    if (!gs[i].size()) continue;
    for (int j = 2 * i; j <= c; j += i)
      if (gs[j].size()) exc[i] ^= exc[j];
  }
  vector<int> res;
  vector<vector<int>> sz;
  vector<vector<vector<int>>> opt;
  for (int i = (1); i < (c + 1); i++) {
    if (!gs[i].size()) continue;
    gauss(exc[i], gs[i], res, sz, opt);
  }
  vector<bitset<40000>> bag(sz.size() + 1);
  bag[0][0] = 1;
  for (int i = 1; i <= (int)sz.size(); i++) {
    for (auto& first : sz[i - 1]) {
      bag[i] |= (bag[i - 1] << first);
    }
  }
  int now = n - res.size();
  for (int i = (int)sz.size(); i >= 1; i--) {
    for (int j = 0; j < (int)sz[i - 1].size(); j++) {
      int first = sz[i - 1][j];
      if (now - first >= 0 && bag[i - 1][now - first]) {
        now -= first;
        for (auto& second : opt[i - 1][j]) res.emplace_back(second);
        break;
      }
    }
  }
  sort(res.begin(), res.end());
  for (auto& c : res) cout << c << " ";
  cout << endl;
  return 0;
}
