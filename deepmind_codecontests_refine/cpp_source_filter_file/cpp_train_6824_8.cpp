#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 4;
int n, c[maxn];
string s[maxn];
long long dp[maxn][2];
long long best(int ind, bool rev) {
  if (ind == n) {
    return 0;
  }
  if (dp[ind][rev] != -1) {
    return dp[ind][rev];
  }
  string t = s[ind - 1];
  if (rev) {
    reverse(t.begin(), t.end());
  }
  string v = s[ind];
  reverse(v.begin(), v.end());
  if (s[ind] < t && v < t) {
    return dp[ind][rev] = 1e17;
  }
  if (s[ind] > t && v > t) {
    return dp[ind][rev] =
               min(c[ind] + best(ind + 1, true), best(ind + 1, false));
  }
  if (s[ind] > t) {
    return dp[ind][rev] = best(ind + 1, false);
  }
  return dp[ind][rev] = c[ind] + best(ind + 1, true);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  memset(dp, -1, sizeof dp);
  long long res1 = c[0] + best(1, true);
  long long res2 = best(1, false);
  long long res = min(res1, res2);
  if (res >= 1e17) {
    res = -1;
  }
  cout << res;
}
