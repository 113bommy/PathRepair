#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 10;
int get(int n) {
  int res = 0;
  while (n) {
    res = max(res, n % 10);
    n /= 10;
  }
  return res;
}
const long long INF = (long long)1e18;
int mx[N];
long long dp[N][10];
long long neg[N][10];
long long work(long long n) {
  if (n == 0) return 0;
  if (n < 1000 * 1000) return work(n - mx[n]) + 1;
  long long __div__ = n / (1000 * 1000);
  long long mod = n % (1000 * 1000);
  long long add = dp[mod][mx[__div__]];
  return work(__div__ * 1000ll * 1000 + neg[mod][mx[__div__]]) + add;
}
int main() {
  ios_base::sync_with_stdio(0);
  mx[0] = 0;
  for (int i = 1; i < N; i++) mx[i] = get(i);
  for (int i = 0; i < N; i++)
    for (int j = 1; j < 10; j++) {
      dp[i][j] = INF;
      int d = max(j, mx[i]);
      int to = i - d;
      if (to < 0) {
        dp[i][j] = 1;
        neg[i][j] = to;
      } else {
        dp[i][j] = dp[to][j] + 1;
        neg[i][j] = neg[to][j];
      }
    }
  long long n;
  cin >> n;
  cout << work(n);
  return 0;
}
