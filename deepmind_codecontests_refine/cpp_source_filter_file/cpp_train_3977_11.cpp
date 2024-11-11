#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:300000000")
using namespace std;
const double pi = 3.1415926535897932384626433832795;
template <class T>
T myabs(T a) {
  return a >= 0 ? a : -a;
};
template <class T>
T sqr(T x) {
  return x * x;
}
int n, m;
long long k, curK;
char ans[3000];
vector<vector<int> > p;
long long dp[210][210];
long long inf = 2LL * 1000000000 * 1000000000;
long long getCnt(char *s) {
  int len = n + m - 1;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= len; i++) {
    for (int j = 0; j < len / 2 + 1; j++) {
      if (s[i - 1] != '(') {
        dp[i][j] += dp[i - 1][j + 1];
      }
      if (s[i - 1] != ')') {
        if (j != 0) {
          dp[i][j] += dp[i - 1][j - 1];
        }
      }
      if (dp[i][j] > inf) dp[i][j] = inf;
    }
  }
  return dp[len][0];
}
int cx[300], cy[300];
int main() {
  cin >> n >> m >> k;
  k--;
  curK = 0;
  for (int i = 0; i < (n + m - 1); i++) ans[i] = '?';
  p.resize(n, vector<int>(m));
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++) {
      int p;
      cin >> p;
      p--;
      cx[p] = i;
      cy[p] = j;
    }
  for (int i = 0; i < (n * m); i++) {
    int ind = cx[i] + cy[i];
    if (ans[ind] != '?') continue;
    ans[ind] = '(';
    long long t = getCnt(ans);
    if (curK + t <= k) {
      curK += t;
      ans[ind] = ')';
    }
  }
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) cout << ans[i + j];
    cout << endl;
  }
}
