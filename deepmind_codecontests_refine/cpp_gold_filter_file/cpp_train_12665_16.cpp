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
const int SIZE = 1e6 + 10;
char s[222][222];
int v[222][222];
int main() {
  int N, K;
  R(N, K);
  for (int i = (1); i <= (N); ++i) scanf("%s", (s[i] + 1));
  for (int j = (1); j <= (N); ++j)
    for (int k = (1); k <= (N - K + 1); ++k) {
      bool err = 0;
      for (int i = 0; i < (K); ++i) {
        if (s[j][k + i] == '#') err = 1;
      }
      if (!err)
        for (int i = 0; i < (K); ++i) v[j][k + i]++;
    }
  for (int k = (1); k <= (N); ++k)
    for (int j = (1); j <= (N - K + 1); ++j) {
      bool err = 0;
      for (int i = 0; i < (K); ++i) {
        if (s[j + i][k] == '#') err = 1;
      }
      if (!err)
        for (int i = 0; i < (K); ++i) v[j + i][k]++;
    }
  pair<int, int> an = {1, 1};
  int ma = -1;
  for (int i = (1); i <= (N); ++i)
    for (int j = (1); j <= (N); ++j) {
      if (s[i][j] != '#' && v[i][j] > ma) {
        ma = v[i][j];
        an = make_pair(i, j);
      }
    }
  W(an);
  return 0;
}
