#include <bits/stdc++.h>
using namespace std;
template <class T>
bool gmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool gmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const long long N = 110;
const long long K = 100010;
const long long INF = 1e12;
long long a[N], b[N], dp[N][2 * K];
long long n, k;
long long Rec(long long idx, long long sum) {
  if (idx == n) {
    return sum ? -INF : 0;
  }
  long long& ans = dp[idx][sum];
  if (ans + 1) return ans;
  ans = -INF;
  gmax(ans, Rec(idx + 1, sum));
  gmax(ans, a[idx] + Rec(idx + 1, sum + a[idx] - b[idx]));
  return ans;
}
void solve() {
  cin >> n >> k;
  for (long long i = 0; i < (n); i++) cin >> a[i];
  for (long long i = 0; i < (n); i++) cin >> b[i];
  for (long long i = 0; i < (n); i++) b[i] *= k;
  memset(dp, (long long)(-1), sizeof(dp));
  long long Ans = Rec(0, 0);
  cout << (Ans <= 0 ? -1 : Ans) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
