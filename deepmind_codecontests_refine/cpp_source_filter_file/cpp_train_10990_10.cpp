#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using PII = std::pair<int, int>;
using VPII = std::vector<std::pair<int, int>>;
using PLL = std::pair<ll, ll>;
using VPLL = std::vector<std::pair<ll, ll>>;
using TI3 = std::tuple<int, int, int>;
using TI4 = std::tuple<int, int, int, int>;
using TL3 = std::tuple<ll, ll, ll>;
using TL4 = std::tuple<ll, ll, ll, ll>;
const int mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
const int mod = mod1;
const ll inf = 1e18;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";
const string alphabets = "abcdefghijklmnopqrstuvwxyz";
template <typename T>
void show1dvec(const vector<T> &v) {
  if (v.size() == 0) return;
  int n = v.size() - 1;
  for (int i = 0; i < (int)(n); i++) cout << v[i] << wsp;
  cout << v[n] << rt;
  return;
}
template <typename T>
void show2dvec(const vector<vector<T>> &v) {
  int n = v.size();
  for (int i = 0; i < (int)(n); i++) show1dvec(v[i]);
}
template <typename T>
void range_sort(vector<T> &arr, int l, int r) {
  sort(arr.begin() + l, arr.begin() + r);
}
template <typename T, typename S>
void show1dpair(const vector<pair<T, S>> &v) {
  int n = v.size();
  for (int i = 0; i < (int)(n); i++)
    cout << v[i].first << wsp << v[i].second << rt;
  return;
}
template <typename T, typename S>
void pairzip(const vector<pair<T, S>> &v, vector<T> &t, vector<T> &s) {
  int n = v.size();
  for (int i = 0; i < (int)(n); i++) {
    t.push_back(v[i].first);
    s.push_back(v[i].second);
  }
  return;
}
template <typename T>
void maxvec(vector<T> &v) {
  T s = v[0];
  int n = v.size();
  for (int i = 0; i < (int)(n - 1); i++) {
    if (s > v[i + 1]) {
      v[i + 1] = s;
    }
    s = v[i + 1];
  }
}
template <typename T, typename S>
bool myfind(T t, S s) {
  return find(t.cbegin(), t.cend(), s) != t.cend();
}
bool check(int y, int x, int h, int w) {
  return 0 <= y && y < h && 0 <= x && x < w;
}
bool iskadomatsu(int a, int b, int c) {
  return (a != b && b != c && c != a) && ((a > b && b < c) || (a < b && b > c));
}
double euc_dist(PII a, PII b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
VS split(string s, char c) {
  VS ret;
  string part;
  s += c;
  for (int i = 0; i < (int)(s.length()); i++) {
    if (s[i] == c) {
      if (part != "") ret.emplace_back(part);
      part = "";
    } else if (s[i] != c) {
      part += s[i];
    }
  }
  return ret;
}
template <typename T, typename S, typename R>
ll pow_mod(T p, S q, R mod = 1ll) {
  ll ret = 1, r = p;
  while (q) {
    if (q % 2) ret *= r, ret %= mod;
    r = (r * r) % mod, q /= 2;
  }
  return ret % mod;
}
template <typename T, typename S>
ll pow_no_mod(T p, S q) {
  ll ret = 1, r = p;
  while (q) {
    if (q % 2) ret *= r;
    r = (r * r), q /= 2;
  }
  return ret;
}
void make_frac_tables(VL &frac_list, VL &frac_inv_list) {
  for (int i = 0; i < (int)(frac_list.size() - 1); i++) {
    frac_list[i + 1] *= frac_list[i] * (i + 1);
    frac_list[i + 1] %= mod;
    frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
    frac_inv_list[i + 1] %= mod;
  }
}
pair<VL, VL> make_frac_tables(int n) {
  VL frac_list(n + 1, 1), frac_inv_list(n + 1, 1);
  for (int i = 0; i < (int)(n); i++) {
    frac_list[i + 1] *= frac_list[i] * (i + 1);
    frac_list[i + 1] %= mod;
    frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
    frac_inv_list[i + 1] %= mod;
  }
  return make_pair(frac_list, frac_inv_list);
}
ll comb(int a, int b, const VL &frac_list, const VL &frac_inv_list) {
  if (a < b) return 0;
  if (b < 0) return 0;
  ll ret = frac_list[a];
  ret *= frac_inv_list[b];
  ret %= mod;
  ret *= frac_inv_list[a - b];
  ret %= mod;
  return ret;
}
void djkstra(int n, int s, int t, const vector<set<int>> &connect) {
  const int intm = 1e9;
  vector<int> shortest(n, intm);
  shortest[s] = 0;
  vector<int> search = {s};
  vector<int> new_search;
  while (!search.empty()) {
    for (auto i : search) {
      for (auto j : connect[i]) {
        if (shortest[j] > 1 + shortest[i]) {
          shortest[j] = 1 + shortest[i];
          new_search.emplace_back(j);
        }
      }
    }
    search.clear();
    search = new_search;
    new_search.clear();
  }
  if (shortest[t] == intm) shortest[t] = -1;
  printf("%d\n", shortest[t]);
}
struct node {
  int parent = -1;
  ll weight = 0;
  int depth = 0;
  int subtree = 0;
  VPII children;
  VPII connect;
  node(int n) {
    parent = -1;
    weight = 0;
    depth = 0;
    subtree = 0;
    children;
    connect;
  }
};
struct graph {
  int _n;
  int root = 0;
  vector<node> nodes;
  graph(int n) {
    _n = n;
    for (int i = 0; i < (int)(_n); i++) nodes.emplace_back(node(_n));
  }
  void showparent() {
    for (int i = 0; i < (int)(_n - 1); i++) cout << nodes[i].parent << wsp;
    cout << nodes[_n - 1].parent << rt;
  }
  void showweight() {
    for (int i = 0; i < (int)(_n - 1); i++) cout << nodes[i].weight << wsp;
    cout << nodes[_n - 1].weight << rt;
  }
  void showsubtree() {
    for (int i = 0; i < (int)(_n - 1); i++) cout << nodes[i].subtree << wsp;
    cout << nodes[_n - 1].subtree << rt;
  }
  void showdepth() {
    for (int i = 0; i < (int)(_n - 1); i++) cout << nodes[i].depth << wsp;
    cout << nodes[_n - 1].depth << rt;
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m, d;
  cin >> m >> d;
  int ans = 5;
  auto isbig = [](int m) {
    const VI v = {1, 3, 5, 7, 8, 10, 12};
    return myfind(v, m);
  };
  if (m == 2) {
    if (d == 0) ans = 4;
  } else if (isbig(m)) {
    if (d >= 6) ans = 6;
  } else {
    if (d == 7) ans = 6;
  }
  cout << ans << rt;
  return 0;
}
