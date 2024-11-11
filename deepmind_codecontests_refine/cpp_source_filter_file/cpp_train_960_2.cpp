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
  _W(x.F);
  putchar(' ');
  _W(x.S);
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
const int MAXN = 1e6 + 10, MAXM = 4e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
const int inv2 = 5e8 + 4;
const int Lim = 1 << 20;
long long a, b, q;
long long dp[MAXN];
long long calc(long long x) {
  long long ans = 0;
  ans = dp[a * b] * (x / (a * b));
  return ans + dp[x % (a * b)];
}
void solve() {
  R(a, b, q);
  vector<int> ans;
  for (int i = 1; i <= a * b; i++) {
    dp[i] = (((i % a) % b) != ((i % b) % a));
    dp[i] += dp[i - 1];
  }
  while (q--) {
    long long x, y;
    R(x, y);
    ans.push_back(calc(y) - calc(x - 1));
  }
  W(ans);
}
int main() {
  int t = 1;
  R(t);
  while (t--) solve();
  return 0;
}
