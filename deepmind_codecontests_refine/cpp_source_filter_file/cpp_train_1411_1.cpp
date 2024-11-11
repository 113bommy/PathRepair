#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-10;
const long long MOD = 1000000007ll;
const long long mod1 = 1000000009ll;
const long long mod2 = 1100000009ll;
int INF = (int)1e9 + 5;
long long INFINF = (long long)1e18;
double dp[(1 << 21)];
double result[22], prob[22];
queue<int> q;
double zero = 1e-8;
void update(int config, int n, int k) {
  double chance = 1;
  for (int i = 0; i < n; i++)
    if ((1 << i) & config) chance -= prob[i];
  int r = __builtin_popcount(config);
  if (r == k) {
    for (int i = 0; i < n; i++)
      if ((1 << i) & config) result[i] += dp[config];
    return;
  }
  for (int i = 0; i < n; i++)
    if (!((1 << i) && config)) {
      if (dp[config | (1 << i)] == 0.0 && prob[i] != 0.0)
        q.push((1 << i) | config);
      dp[(1 << i) | config] += dp[config] * (prob[i] / chance);
    }
}
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int prob_zero = 0;
  for (int i = 0; i < n; i++) {
    cin >> prob[i];
    if (prob[i] < zero) prob_zero++;
  }
  k = min(k, n - prob_zero);
  dp[0] = 1;
  q.push(0);
  while (!q.empty()) {
    update(q.front(), n, k);
    q.pop();
  }
  for (int i = 0; i < n; i++)
    cout << fixed << setprecision(10) << result[i] << " ";
  cout << endl;
  return 0;
}
