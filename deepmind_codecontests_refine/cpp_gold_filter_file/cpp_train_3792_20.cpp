#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T a) {
  return a < 0 ? -a : a;
}
template <typename T>
T sqr(T a) {
  return a * a;
}
const int INF = (int)1e9;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const int N = 2010;
const int M = 20010;
const int ADD = (M >> 1);
const int MOD = 1000000007;
int n;
int a[N];
int z[N][M];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  memset(z, 0, sizeof(z));
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int st = 0; st < M; ++st) {
      if (st == ADD || z[i - 1][st] != 0) {
        int cur = st - ADD;
        for (int mul = -1; mul <= 1; mul += 2) {
          int nx = cur + mul * a[i];
          if (0 <= nx + ADD && nx + ADD < M) {
            z[i][nx + ADD] += z[i - 1][st];
            if (cur == 0) z[i][nx + ADD]++;
            while (z[i][nx + ADD] >= MOD) z[i][nx + ADD] -= MOD;
          }
        }
      }
    }
    ans += z[i][ADD];
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << endl;
  return 0;
}
