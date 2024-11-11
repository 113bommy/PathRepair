#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x7FFFFFFF;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
int dp[5005];
int beg[5005], lst[5005];
int main() {
  int n, k;
  while (cin >> n >> k) {
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> beg[i] >> lst[i];
    beg[n] = 86401;
    lst[n] = 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) {
      if (beg[i] > dp[k] + 1) checkmax(ans, beg[i] - dp[k] - 1);
      int now = beg[i] + lst[i] - 1;
      for (int j = k; j > 0; j--) {
        if (dp[j] < beg[i])
          dp[j] = now;
        else
          dp[j] += lst[i];
        dp[j] = min(dp[j - 1], dp[j]);
      }
      if (dp[0] < beg[i])
        dp[0] = now;
      else
        dp[0] += lst[i];
    }
    cout << ans << endl;
  }
  return 0;
}
