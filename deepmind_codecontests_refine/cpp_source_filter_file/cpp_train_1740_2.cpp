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
int d[2][3] = {{4, 9, 49}, {40, 45, 49}};
const int AA = 1000;
bitset<500000> dp;
void solve0(int n) {
  dp[0] = 1;
  int bb = 0;
  for (int i = (1); i <= (n); ++i) {
    for (int j = bb; j >= 0; j--) {
      if (!dp[j]) continue;
      for (int k = 0; k < (3); ++k) dp[j + d[0][k]] = 1;
    }
    bb += 49;
  }
  W(dp.count());
}
int main() {
  int n;
  R(n);
  if (n <= AA) {
    solve0(n);
  } else {
    W(48753 + 49 * (n - AA));
  }
  return 0;
}
