#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxn = (int)3e6 + 10;
;
long long dp[maxn], q, n, num[maxn], pr[maxn];
int bf(int start) {
  int cnt = 0, i = start;
  while (start - i < n && i != -1) {
    i = pr[i];
    cnt++;
  }
  return max(cnt, 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < (int)(n); i++) {
    cin >> num[i];
    pr[i] = i;
  }
  for (int i = n; i < (int)(3 * n); i++) num[i] = num[i - n];
  for (int qq = 0; qq < (int)(q); qq++) {
    long long p = -1, sum = 0, b, mini = INFL, ii = -1;
    cin >> b;
    for (int i = 0; i < (int)(3 * n); i++) {
      sum += num[i];
      while (sum > b) {
        p++;
        sum -= num[p];
      }
      if (p == -1) {
        pr[i] = -1;
        dp[i] = 1;
      } else {
        pr[i] = p;
        dp[i] = dp[p] + 1;
      }
      if (i >= 2 * n && i - p < mini) {
        mini = i - p;
        ii = i;
      }
    }
    long long ans = INFL;
    for (int i = pr[ii]; i < (int)(ii + 1); i++) {
      mineq(ans, (long long)bf(i));
    }
    cout << ans << "\n";
  }
}
