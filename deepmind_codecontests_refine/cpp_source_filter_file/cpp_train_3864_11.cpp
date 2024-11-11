#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
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
void _W(const long long &x) { printf("%lld", x); }
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
const int SIZE = 1024;
long long dp[SIZE][2][SIZE];
int main() {
  MOD = 998244353;
  int n, k;
  R(n, k);
  dp[1][0][1] = 2;
  dp[1][1][2] = 2;
  for (int i = (1); i < (n); ++i) {
    for (int r = (1); r <= (k); ++r) {
      ADD(dp[i + 1][0][r], dp[i][0][r]);
      ADD(dp[i + 1][0][r + 1], dp[i][0][r]);
      ADD(dp[i + 1][1][r + 1], dp[i][0][r] * 2);
      ADD(dp[i + 1][1][r], dp[i][1][r]);
      ADD(dp[i + 1][1][r + 2], dp[i][1][r]);
      ADD(dp[i + 1][0][r], dp[i][1][r] * 2);
    }
  }
  W((dp[n][0][k] + dp[n][1][k]) % MOD);
  return 0;
}
