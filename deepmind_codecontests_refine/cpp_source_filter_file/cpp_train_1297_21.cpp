#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
long long int readL() {
  long long int res;
  scanf("%I64d", &res);
  return res;
}
void printL(long long int res) { printf("%I64d", res); }
int n;
char s[55][25];
long long int share[1 << 21];
double dp[1 << 21];
int main() {
  cin >> n;
  for (int i = 0; i < (n); ++i) scanf("%s", s[i]);
  int m = strlen(s[0]);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j)
      if (i != j) {
        long long int same = 0;
        for (int k = 0; k < (m); ++k)
          if (s[i][k] == s[j][k]) same |= (1ll << k);
        share[same] |= (1ll << i);
      }
  for (int i = (1 << m) - 2; i >= 0; --i) {
    int other = 0;
    for (int j = 0; j < (m); ++j)
      if (!(i >> j & 1)) {
        share[i] |= share[i | (1 << j)];
        dp[i] += dp[i | (1 << j)];
        ++other;
      }
    dp[i] /= other;
    dp[i] += 1.0 / n * __builtin_popcount(share[i]);
  }
  printf("%.10f\n", dp[0]);
  return 0;
}
