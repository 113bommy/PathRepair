#include <bits/stdc++.h>
using namespace std;
const int inf = ((1 << 30) - 1) << 1;
const long long mod = 1000000007;
const int maxn = 1e5 + 5;
using namespace std;
long long n, cnt;
long long fib[maxn], dp[maxn][2];
long long sta[maxn];
void pre() {
  fib[1] = 1;
  fib[2] = 2;
  cnt = 2;
  while (fib[cnt] <= (long long)1e18) {
    cnt++;
    fib[cnt] = fib[cnt - 1] + fib[cnt - 2];
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tim;
  cin >> tim;
  pre();
  while (tim--) {
    cin >> n;
    long long ans = 1;
    long long res_cnt = 0;
    while (n) {
      long long p = upper_bound(fib + 1, fib + cnt + 1, n) - fib - 1;
      sta[++res_cnt] = p;
      n -= fib[p];
    }
    for (long long i = 1; i <= res_cnt / 2; i++) {
      swap(sta[i], sta[res_cnt - i + 1]);
    }
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (long long i = 1; i <= res_cnt; i++) {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][1] = (dp[i - 1][0]) * ((sta[i] - sta[i - 1] - 1) / 2) +
                 dp[i - 1][1] * ((sta[i] - sta[i - 1]) / 2);
    }
    cout << dp[res_cnt][1] + dp[res_cnt][0] << "\n";
  }
  return 0;
}
