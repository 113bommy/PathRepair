#include <bits/stdc++.h>
using namespace std;
long long n, m;
bool proof(vector<long long> nab, long long time) {
  long long cnt = 0, cur = 0, sum = 0, ktime = time;
  while (cnt != m + 1 && cur != n + 1) {
    if (sum >= nab[cur]) {
      while (sum >= nab[cur] && cur != n + 1) {
        time--;
        if (sum != nab[cur]) sum--;
        cur++;
      }
    } else {
      if (cnt != m) sum += time;
      cnt++;
    }
  }
  if (sum >= nab[n])
    return true;
  else
    return false;
}
int main() {
  cin >> n >> m;
  vector<long long> nab(n + 1, 0);
  vector<long long> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &nab[i]);
    dp[i] = dp[i - 1] + nab[i];
  }
  long long l = 1, r = 1e18, m = (l + r) / 2;
  while (r - l >= 2LL) {
    bool flag = proof(dp, m);
    if (flag)
      r = m;
    else
      l = m;
    m = (l + r) / 2;
  }
  cout << r;
  return 0;
}
