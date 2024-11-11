#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 20;
vector<pair<int, int> > e[SIZE];
vector<int> e2[SIZE];
int u[SIZE], tt;
char an[2][SIZE];
int cnt[2];
void dfs1(int x) {
  cnt[0]++;
  u[x] = tt;
  for (int y : e2[x]) {
    if (u[y] == tt) continue;
    dfs1(y);
  }
  for (auto &[y, id] : e[x]) {
    if (u[y] == tt) continue;
    if (id > 0)
      an[0][id] = '+';
    else
      an[0][id] = '-';
    dfs1(y);
  }
}
void dfs2(int x) {
  cnt[1]++;
  u[x] = tt;
  for (int y : e2[x]) {
    if (u[y] == tt) continue;
    dfs2(y);
  }
  for (auto &[y, id] : e[x]) {
    if (u[y] == tt) continue;
    if (id > 0)
      an[1][id] = '-';
    else
      an[1][id] = '+';
  }
}
int _ty[SIZE];
int main() {
  int n, m, s;
  R(n, m, s);
  for (int i = (1); i <= (m); ++i) {
    an[0][i] = an[1][i] = '-';
    int ty;
    int x, y;
    R(ty, x, y);
    _ty[i] = ty;
    if (ty == 2) {
      e[x].emplace_back(make_pair(y, i));
      e[y].emplace_back(make_pair(x, -i));
    } else {
      e2[x].emplace_back(y);
    }
  }
  tt++;
  dfs1(s);
  tt++;
  dfs2(s);
  for (int j = 0; j < (2); ++j) {
    W(cnt[j]);
    for (int i = (1); i <= (m); ++i) {
      if (_ty[i] == 2) putchar(an[j][i]);
    }
    W("");
  }
  return 0;
}
