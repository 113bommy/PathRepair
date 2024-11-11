#include <bits/stdc++.h>
using namespace std;
const int maxn = 1003;
const long long mod = 1000000007;
int n;
string word;
int ma[26];
bool cmp(int *now, int len) {
  for (int e = 0; e < 26; e++)
    if (len > ma[e] && now[e] > 0) return false;
  return true;
}
long long ways[maxn];
long long nways(int cur) {
  if (cur == n) return 1;
  if (ways[cur] != -1) return ways[cur];
  long long ans = 0;
  int now[26];
  memset(now, 0, sizeof now);
  for (int e = cur; e < n; e++) {
    now[word[e] - 'a']++;
    if (cmp(now, e - cur + 1))
      ans += nways(e + 1);
    else
      break;
    ans %= mod;
  }
  return ways[cur] = ans;
}
int maxstr() {
  int ans = 0;
  for (int e = 0; e < n; e++) {
    int now[26];
    memset(now, 0, sizeof now);
    for (int f = e; f <= n; f++) {
      if (f == n) {
        ans = max(ans, f - e);
        break;
      }
      now[word[f] - 'a']++;
      if (!cmp(now, f - e + 1)) {
        ans = max(ans, f - e);
        break;
      }
    }
  }
  return ans;
}
int dp[maxn];
int min_number(int cur) {
  if (cur == n) return 0;
  if (dp[cur] != -1) return dp[cur];
  int ans = n;
  int now[26];
  memset(now, 0, sizeof now);
  for (int e = cur; e < n; e++) {
    now[word[e] - 'a']++;
    if (cmp(now, e - cur + 1)) {
      ans = min(ans, 1 + min_number(e + 1));
    } else {
      break;
    }
  }
  return dp[cur] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> word;
  for (int e = 0; e < 26; e++) cin >> ma[e];
  memset(ways, -1, sizeof ways);
  memset(dp, -1, sizeof dp);
  printf("%lld\n%d\n%d\n", nways(0), maxstr(), min_number(0));
  return 0;
}
