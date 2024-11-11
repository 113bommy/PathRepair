#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long c[100006], freq[100006], people[100006], h[100006];
long long catche[5005][505];
long long dp(long long left, long long pep) {
  if (left == 0 || pep == 0) return 0;
  long long &ans = catche[left][pep];
  if (ans != -1) return ans;
  ans = 0;
  for (long long j = 1; j <= min(left, k); j++) {
    ans = max(ans, h[j] + dp(left - j, pep - 1));
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  long long ans = 0;
  long long i, j;
  for (i = 1; i <= (n * k); i++) {
    long long x;
    cin >> x;
    freq[x]++;
  }
  for (i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    people[x]++;
  }
  for (i = 1; i <= k; i++) {
    cin >> h[i];
  }
  for (i = 1; i <= 100005; i++) {
    if (!people[i]) {
      continue;
    }
    for (j = 0; j <= freq[i]; j++) {
      for (long long kk = 0; kk <= people[i]; kk++) {
        catche[j][kk] = -1;
      }
    }
    ans += dp(freq[i], people[i]);
  }
  cout << ans << '\n';
}
