#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1 << 18;
const long long maxF = 18;
long double dp[maxN];
bool vis[maxN];
long double prob[maxF][maxF];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> prob[i][j];
    }
  }
  long long mask = (1 << n) - 1;
  dp[mask] = 1.0;
  queue<long long> q;
  q.push(mask);
  vis[mask] = 1;
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    long long c = __builtin_popcount(x);
    long double w = 1.0 * ((c * (c - 1)) / 2);
    for (long long i = 0; i < 18; i++) {
      if ((x & (1 << i)) == 0) continue;
      for (long long j = 0; j < 17; j++) {
        if (i == j || (x & (1 << j)) == 0) continue;
        long long nm = x - (1 << j);
        long double p = (1.0 * prob[i][j] * dp[x]) / w;
        dp[nm] += p;
        if (!vis[nm]) {
          q.push(nm);
          vis[nm] = 1;
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << fixed << setprecision(6) << dp[(1 << i)] << " ";
  }
  cout << endl;
  return 0;
}
