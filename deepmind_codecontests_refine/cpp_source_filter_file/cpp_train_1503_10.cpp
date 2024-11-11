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
const int INF = 5e8;
int n;
int val[405], ar[405];
int con[405][405], dp[405][405], dp2[405][405];
int res[405];
int main() {
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> val[i];
  for (int i = 0; i < (n); ++i) cin >> ar[i];
  for (int l = 1; l <= n; ++l) {
    for (int i = 0; i < (n - l + 1); ++i) {
      int j = i + l, last = i + l - 1;
      if (l == 1) {
        con[i][j] = 0;
        dp[i][j] = dp2[i][j] = val[0];
        continue;
      }
      con[i][j] = -INF;
      for (int k = i + 1; k < j; ++k)
        if (abs(ar[i] - ar[k]) == 1 &&
            (ar[k] - ar[i]) * (long long int)(ar[last] - ar[k]) >= 0) {
          chmax(con[i][j], con[k][j] + dp2[i + 1][k]);
        }
      dp[i][j] = -INF;
      for (int k = i; k < j; ++k)
        if (ar[k] >= ar[i] && ar[k] >= ar[last]) {
          int len = ar[k] * 2 - ar[i] - ar[last];
          if (len >= n || len < 0) continue;
          chmax(dp[i][j], val[len] + con[i][k + 1] + con[k][j]);
        }
      dp2[i][j] = dp[i][j];
      for (int k = i + 1; k < j; ++k) {
        chmax(dp2[i][j], dp[i][k] + dp[k][j]);
      };
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      ;
    }
  }
  res[0] = 0;
  for (int i = 0; i < (n); ++i) {
    res[i + 1] = res[i];
    for (int j = 0; j < (i + 1); ++j) chmax(res[i + 1], res[j] + dp2[j][i + 1]);
  }
  cout << res[n] << endl;
  return 0;
}
