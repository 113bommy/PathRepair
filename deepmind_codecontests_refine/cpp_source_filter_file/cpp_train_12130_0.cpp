#include <bits/stdc++.h>
using namespace std;
inline int add(int a, int b, int m = 1000000007) {
  a += b;
  if (a >= m) a -= m;
  return a;
}
inline int mul(int a, int b, int m = 1000000007) {
  return (int)(((long long)a * (long long)b) % m);
}
inline int norm(int x, int m = 1000000007) {
  if (x >= m) x %= m;
  if (x < 0) x += m;
  return x;
}
inline int neg(int x, int m = 1000000007) {
  x = -x;
  return norm(x);
}
const int N = (1e5) + 10;
pair<int, int> a[N];
int dp[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
  sort(a + 1, a + n + 1);
  a[0] = {-1000000007, -1000000007};
  dp[0] = 0;
  dp[1] = 0;
  int ans = n;
  for (int i = 2; i <= n; ++i) {
    int pos =
        lower_bound(a, a + i + 1, make_pair(a[i].first - a[i].second, -1)) - a;
    dp[i] = i - pos + dp[pos - 1];
    ans = min(ans, dp[i] + n - i);
  }
  cout << ans;
  return 0;
}
