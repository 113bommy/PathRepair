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
int n, m;
vector<vector<int>> a;
const int LEFT = 0;
const int RIGHT = 1;
const int DOWN = 0;
const int UP = 1;
void check_min(int &x, int v) { x = min(x, v); }
void check_max(int &x, int v) { x = max(x, v); }
void solve() {
  vector<pair<int, int>> AA;
  for (int i = 0; i < (n); ++i) {
    AA.emplace_back(a[i][0], i);
  }
  sort((AA).begin(), (AA).end(), greater<pair<int, int>>());
  vector<vector<int>> dp[2][2];
  for (int i = 0; i < (2); ++i)
    for (int j = 0; j < (2); ++j) {
      dp[i][j].assign(n, vector<int>(m));
    }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      for (int k1 = 0; k1 < (2); ++k1)
        for (int k2 = 0; k2 < (2); ++k2) dp[k1][k2][i][j] = a[AA[i].second][j];
      if (i) check_min(dp[LEFT][DOWN][i][j], dp[LEFT][DOWN][i - 1][j]);
      if (j) check_min(dp[LEFT][DOWN][i][j], dp[LEFT][DOWN][i][j - 1]);
    }
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = m - 1; j >= 0; j--) {
      if (i) check_max(dp[RIGHT][DOWN][i][j], dp[RIGHT][DOWN][i - 1][j]);
      if (j + 1 < m)
        check_max(dp[RIGHT][DOWN][i][j], dp[RIGHT][DOWN][i][j + 1]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < (m); ++j) {
      if (i + 1 < n) check_max(dp[LEFT][UP][i][j], dp[LEFT][UP][i + 1][j]);
      if (j) check_max(dp[LEFT][UP][i][j], dp[LEFT][UP][i][j - 1]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i + 1 < n) check_min(dp[RIGHT][UP][i][j], dp[RIGHT][UP][i + 1][j]);
      if (j + 1 < m) check_min(dp[RIGHT][UP][i][j], dp[RIGHT][UP][i][j + 1]);
    }
  }
  for (int i = 0; i < (n - 1); ++i) {
    int ll = -1, rr = m - 2;
    while (ll < rr) {
      int mm = ll + (rr - ll + 1) / 2;
      if (dp[LEFT][DOWN][i][mm] > dp[LEFT][UP][i + 1][mm])
        ll = mm;
      else
        rr = mm - 1;
    }
    if (ll == -1) continue;
    if (dp[RIGHT][UP][i + 1][ll + 1] > dp[RIGHT][DOWN][i][ll + 1]) {
      W("YES");
      string an(n, 'B');
      for (int g = 0; g < (i + 1); ++g) {
        an[AA[g].second] = 'R';
      }
      W(an, ll + 1);
      return;
    }
  }
  W("NO");
}
void input() {
  R(n, m);
  a.assign(n, vector<int>(m));
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) R(a[i][j]);
}
int main() {
  int ___T;
  scanf("%d", &___T);
  for (int cs = 1; cs <= ___T; cs++) {
    input();
    solve();
  }
  return 0;
}
