#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void Max(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void Min(T &a, T b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % 1000000007;
    a = 1LL * a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
long long sqr(int first) { return 1LL * first * first; }
pair<int, int> a[100005], dp[100005];
long long val[100005];
int pr[100005];
int main() {
  int n, i, j, k, m = 0;
  scanf("%d", &n);
  int ly = 1000000007, ry = -1000000007;
  for (i = 0; i < n; i++)
    scanf("%d%d", &a[i].first, &a[i].second), Min(ly, a[i].second),
        Max(ry, a[i].second);
  sort(a, a + n);
  dp[n - 1] = make_pair(a[n - 1].second, a[n - 1].second);
  long long mx = sqr(a[n - 1].second);
  val[n - 1] = LLONG_MIN;
  for (i = n - 2; i >= 0; i--) {
    dp[i].first = max(dp[i + 1].first, a[i].second);
    dp[i].second = min(dp[i + 1].second, a[i].second);
    val[i] = mx + sqr(a[i].first);
    Max(mx, sqr(a[i].second));
  }
  dp[n] = make_pair(-1000000007, 1000000007);
  long long l = 0, r = sqr(ry - ly) - 1;
  while (l <= r) {
    long long t = (l + r) >> 1;
    if (sqr(a[n - 1].first - a[0].first) <= t) {
      r = t - 1;
      continue;
    }
    int lst = -1;
    for (i = 0; i < n; i++) {
      pr[i] = lst;
      if (val[i] <= t) lst = i;
    }
    pr[n] = lst;
    int ok = 0;
    j = 0;
    int L = 1000000007, R = -1000000007, lim = n - 1;
    long long mx = LLONG_MIN;
    for (i = 0; i < n && !ok; i++) {
      while (lim >= i && mx + sqr(a[lim].first) > t) lim--;
      if (lim < i) break;
      while (j < n && sqr(a[j].first - a[i].first) <= t) j++;
      k = pr[min(lim + 1, j)] + 1;
      if (k > i) {
        int y1 = min(L, dp[k].second), y2 = max(R, dp[k].first);
        if (sqr(y2 - y1) <= t &&
            sqr(max(abs(y1), abs(y2))) + sqr(a[i].first) <= t) {
          ok = 1;
          break;
        }
      }
      Min(L, a[i].second);
      Max(R, a[i].second);
      Max(mx, 1LL * a[i].second * a[i].second);
      if (mx > t) break;
    }
    if (ok)
      r = t - 1;
    else
      l = t + 1;
  }
  cout << r + 1 << "\n";
  return 0;
}
