#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAXN = 2e3 + 5;
const long long INF = 2000000000;
const double EPS = 1e-6;
vector<long long> t(1000000);
void solve() {
  vector<long long> mas;
  long long n;
  cin >> n;
  if (n < 3) {
    cout << 0;
    return;
  }
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    mas.push_back(a);
  }
  int dp[n], cnt(0), sum(0), ans(0);
  for (int i = 0; i < n; i++) {
    sum += mas[i];
  }
  int tmp = sum / 3;
  if (sum != tmp * 3) {
    cout << 0;
    return;
  }
  dp[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    dp[i + 1] = dp[i] + mas[i];
  }
  for (int i = 2; i < n; i++) {
    if (dp[i - 1] == tmp) cnt++;
    if (dp[i] == 2 * tmp) ans += cnt;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
