#include <bits/stdc++.h>
using namespace std;
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
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
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
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
string s, t;
string one, two;
const int inf = 400, inf2 = 2e6 + 5;
int tab[inf][inf];
vector<pair<pair<int, int>, int> > add[inf2];
vector<pair<pair<int, int>, int> > rem[inf2];
vector<pair<int, int> > fin[inf2];
int ans[inf2];
pair<int, int> parent[inf][inf];
int act[inf][inf];
int glo = 1;
pair<int, int> fnd(pair<int, int> x) {
  if (parent[x.first][x.second] == x) {
    return x;
  }
  auto pr = fnd(parent[x.first][x.second]);
  return parent[x.first][x.second] = pr;
}
int uni(pair<int, int> a, pair<int, int> b) {
  if (act[a.first][a.second] != glo || act[b.first][b.second] != glo) return 0;
  auto fa = fnd(a);
  auto fb = fnd(b);
  if (fa == fb) return 0;
  parent[fa.first][fa.second] = fb;
  return 1;
}
void calc(vector<pair<int, int> > start,
          vector<pair<pair<int, int>, int> > work, int mul) {
  if (work.size() == 0) return;
  42;
  glo++;
  int n = start.size() + work.size();
  for (auto x : start) {
    parent[x.first][x.second] = x;
    act[x.first][x.second] = glo;
  }
  for (auto x : work) {
    parent[x.first.first][x.first.second] = x.first;
  }
  for (auto x : start) {
    uni(x, {x.first - 1, x.second});
    uni(x, {x.first + 1, x.second});
    uni(x, {x.first, x.second - 1});
    uni(x, {x.first, x.second + 1});
  }
  for (auto ev : work) {
    auto x = ev.first;
    act[x.first][x.second] = glo;
    int cnt = 1;
    cnt -= uni(x, {x.first - 1, x.second});
    cnt -= uni(x, {x.first + 1, x.second});
    cnt -= uni(x, {x.first, x.second - 1});
    cnt -= uni(x, {x.first, x.second + 1});
    int t = ev.second;
    int val = cnt * mul;
    42;
    ans[ev.second] -= cnt * mul;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  int ran = max(2e6 / (double)(n * m) + 1, (double)1000);
  for (int i = 0; i < q; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    add[c].push_back({{x, y}, i});
    rem[tab[x][y]].push_back({{x, y}, i});
    tab[x][y] = c;
  }
  vector<pair<int, int> > zero;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      zero.push_back({i, j});
      fin[tab[i][j]].push_back({i, j});
    }
  }
  for (int i = 0; i < ran; i++) {
    reverse(rem[i].begin(), rem[i].end());
  }
  calc({fin[0]}, rem[0], -1);
  for (int i = 1; i < ran; i++) {
    calc({}, add[i], 1);
    calc(fin[i], rem[i], -1);
  }
  int v = 1;
  for (int i = 0; i < q; i++) {
    cout << (v -= ans[i]) << " ";
  }
}
