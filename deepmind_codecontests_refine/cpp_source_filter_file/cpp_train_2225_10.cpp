#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
bool nprime[MAXN];
vector<long long> prime[MAXN];
int dp[MAXN];
int main() {
  nprime[0] = nprime[1] = true;
  for (long long i = 2; i < MAXN; i++)
    if (!nprime[i])
      for (long long j = i; j < MAXN; j += i) {
        prime[j].push_back(i);
        nprime[j] = true;
      }
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x == 1) continue;
    int ans = 0;
    for (int j = 0; j < prime[x].size(); j++) ans = max(ans, dp[prime[x][j]]);
    ans++;
    for (int j = 0; j < prime[x].size(); j++) dp[prime[x][j]] = ans;
  }
  int ans = 0;
  for (int i = 2; i < MAXN; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
