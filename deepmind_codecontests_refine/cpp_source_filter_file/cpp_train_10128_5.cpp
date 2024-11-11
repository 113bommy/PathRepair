#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 1e9 + 9;
const long long int MOD = 1e9 + 696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;
template <class T>
int size(T &&x) {
  return int(x.size());
}
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &p) {
  return out << '(' << p.first << ", " << p.second << ')';
}
template <class T>
auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
  out << '{';
  for (auto it = x.begin(); it != x.end(); ++it)
    out << *it << (it == prev(x.end()) ? "" : ", ");
  return out << '}';
}
void dump() {}
template <class T, class... Args>
void dump(T &&x, Args... args) {
  cerr << x << ";  ";
  dump(args...);
}
mt19937_64 rng(0);
int random(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
inline void addmod(int &x, int val) {
  x += val;
  while (x >= mod) x -= mod;
}
const int maxn = 1000100;
int n, m;
string s[110];
bool tab[110][110];
vector<vector<int> > res;
void oper(int a, int b, int c, int d, int e, int f) {
  tab[a][b] ^= 1;
  tab[c][d] ^= 1;
  tab[e][f] ^= 1;
  res.push_back({a, b, c, d, e, f});
}
vector<vector<int> > solver[2][2][2][2];
int xd[2][2];
void zamien(int cell) {
  pair<int, int> du = {0, 0};
  if (cell == 1) du = {0, 1};
  if (cell == 2) du = {1, 1};
  if (cell == 3) du = {1, 0};
  for (int i = (0); i <= (1); ++i)
    for (int j = (0); j <= (1); ++j)
      if (make_pair(i, j) != du) xd[i][j] ^= 1;
}
vector<int> opuj(int opp) {
  if (opp == 0) return {1, 2, 2, 1, 2, 2};
  if (opp == 1) return {1, 1, 2, 1, 2, 2};
  if (opp == 2) return {1, 1, 1, 2, 2, 1};
  if (opp == 3) return {1, 2, 1, 1, 2, 2};
}
void make_solver() {
  for (int a = 0; a < 4; ++a)
    for (int b = 0; b < 4; ++b)
      for (int c = 0; c < 4; ++c) {
        for (int i = (0); i <= (1); ++i)
          for (int j = (0); j <= (1); ++j) xd[i][j] = 0;
        zamien(a);
        zamien(b);
        zamien(c);
        if (solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].empty()) {
          solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(a));
          solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(b));
          solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(c));
        }
      }
  for (int a = 0; a < 4; ++a)
    for (int b = 0; b < 4; ++b)
      for (int c = 0; c < 4; ++c)
        for (int d = 0; d < 4; ++d) {
          for (int i = (0); i <= (1); ++i)
            for (int j = (0); j <= (1); ++j) xd[i][j] = 0;
          zamien(a);
          zamien(b);
          zamien(c);
          zamien(d);
          if (solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].empty()) {
            solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(a));
            solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(b));
            solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(c));
            solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(d));
          }
        }
}
void solveone() {
  cin >> n >> m;
  int N = n;
  int M = m;
  res = {};
  for (int i = (1); i <= (n); ++i) cin >> s[i];
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j)
      if (s[i][j - 1] == '1')
        tab[i][j] = 1;
      else
        tab[i][j] = 0;
  while (m >= 2) {
    for (int i = 1; i < n; ++i) {
      if (tab[i][m]) {
        if (tab[i + 1][m])
          oper(i, m - 1, i, m, i + 1, m);
        else
          oper(i, m - 1, i, m, i + 1, m - 1);
      }
    }
    if (tab[n][m]) oper(n, m, n, m - 1, n - 1, m - 1);
    m--;
  }
  while (n >= 2) {
    if (tab[n][1] && tab[n][2]) {
      oper(n, 1, n, 2, n - 1, 1);
    } else if (tab[n][1]) {
      oper(n, 1, n - 1, 2, n - 1, 1);
    } else if (tab[n][2]) {
      oper(n, 2, n - 1, 2, n - 1, 1);
    }
    --n;
  }
  for (auto move : solver[tab[1][1]][tab[1][2]][tab[2][1]][tab[2][2]]) {
    res.push_back(move);
  }
  cout << (int)res.size() << "\n";
  for (auto u : res) {
    for (int j = 0; j < 6; ++j) cout << u[j] << ' ';
    cout << "\n";
  }
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  make_solver();
  for (int a = (0); a <= (1); ++a)
    for (int b = (0); b <= (1); ++b)
      for (int c = (0); c <= (1); ++c)
        for (int d = (0); d <= (1); ++d) {
          if (solver[a][b][c][d].empty()) 0 && cerr;
          assert(!solver[a][b][c][d].empty());
        }
  int tests;
  cin >> tests;
  for (int _ = (1); _ <= (tests); ++_) solveone();
}
