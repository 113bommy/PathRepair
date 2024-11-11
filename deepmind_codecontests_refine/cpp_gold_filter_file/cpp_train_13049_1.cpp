#include <bits/stdc++.h>
using namespace std;
map<int, bool> mapi;
vector<pair<int, int> > p;
long long mod = 1e9 + 7;
char sl = '\n';
template <class T, class U>
inline void checkmin(T &x, U y) {
  if (y < x) x = y;
}
template <class T, class U>
inline void checkmax(T &x, U y) {
  if (y > x) x = y;
}
long long DP[101][101];
long long CB[101][101];
int n = 0;
vector<int> a(10);
int main() {
  cin >> n;
  for (int i = (0); i < (10); ++i) cin >> a[i];
  for (int i = (0); i < (101); ++i) {
    for (int j = (0); j < (101); ++j) {
      if (i < j) {
        CB[i][j] = 0;
      } else if (j == 0) {
        CB[i][j] = 1;
      } else {
        CB[i][j] = (CB[i - 1][j] + CB[i - 1][j - 1]) % mod;
      }
    }
  }
  DP[10][0] = 1;
  for (int i = 10 - 1; i >= 0; --i) {
    for (int j = (0); j < (n + 1); ++j) {
      for (int k = (a[i]); k < (j + 1); ++k) {
        DP[i][j] = (DP[i][j] + DP[i + 1][j - k] * CB[j][k] % mod) % mod;
      }
    }
  }
  long long ans = 0;
  for (int i = (a[0]); i < (n + 1); ++i) {
    for (int j = (a[0]); j < (i); ++j) {
      ans = (ans + DP[1][i - j] * CB[i - 1][j]) % mod;
    }
  }
  cout << ans << sl;
  return 0;
}
