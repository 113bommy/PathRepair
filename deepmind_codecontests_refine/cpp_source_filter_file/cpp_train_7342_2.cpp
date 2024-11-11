#include <bits/stdc++.h>
using namespace std;
long long n, a[1002], b[1002];
long long x;
long long f[51];
long long d[51];
int ans;
long long ind;
int viz[10001];
map<int, int> mp;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 1; i--) b[n - i + 1] = a[i];
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < 44; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  ans = 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      d[0] = a[i];
      d[1] = a[j];
      if (d[0] == 0 && d[1] == 0) continue;
      int k;
      mp[d[0]]--;
      mp[d[1]]--;
      for (k = 2;; k++) {
        if (mp[d[k - 2] + d[k - 1]] == 0) break;
        mp[d[k - 2] + d[k - 1]]--;
        d[k] = d[k - 2] + d[k - 1];
        ans = max(ans, k + 1);
      }
      d[0] = a[i];
      d[1] = a[j];
      mp[d[0]]--;
      mp[d[1]]--;
      for (int k1 = 2; k1 < k; k1++) {
        d[k1] = d[k1 - 2] + d[k1 - 1];
        mp[d[k1 - 2] + d[k1 - 1]]++;
      }
    }
  }
  cout << max(ans, mp[0]);
  return 0;
}
