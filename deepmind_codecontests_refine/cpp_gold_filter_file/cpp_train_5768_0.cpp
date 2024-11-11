#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAX_N = (int)1e5 + 20;
long double a[MAX_N];
long double b[MAX_N];
long double dp[MAX_N];
int qu[MAX_N];
int n, head, tail;
int go(int i) {
  return dp[qu[head]] + b[qu[head]] * a[i] >=
         dp[qu[head + 1]] + b[qu[head + 1]] * a[i];
}
int isOk(int i) {
  return (dp[qu[tail]] - dp[i]) / (b[i] - b[qu[tail]]) <
         (dp[qu[tail - 1]] - dp[i]) / (b[i] - b[qu[tail - 1]]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i(0); i < int(n); i++) cin >> a[i];
  for (int i(0); i < int(n); i++) cin >> b[i];
  qu[0] = 0;
  for (int i(1); i < int(n); i++) {
    while (head < tail && go(i)) ++head;
    dp[i] = dp[qu[head]] + b[qu[head]] * a[i];
    while (head < tail && isOk(i)) --tail;
    qu[++tail] = i;
  }
  cout << fixed << setprecision(0) << dp[n - 1] << endl;
  return 0;
}
