#include <bits/stdc++.h>
using namespace std;
long n, k;
long ans;
vector<long> vt[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  long d = (n - 1) / k;
  ans = 2 * d;
  if (n - 1 - d * k > 0) ans++;
  if (n - 1 - d * k > 1) ans++;
  cout << ans << "\n";
  long cur = 2;
  for (long i = 1; i <= k; i++) {
    vt[i].push_back(1);
    for (long j = cur; j < cur + d; j++) {
      vt[i].push_back(j);
    }
    cur = cur + d;
    if (i <= n - 1 - d * k) {
      vt[i].push_back(cur);
      cur++;
    }
  }
  for (long i = 1; i <= k; i++) {
    for (long j = 0; j < vt[i].size() - 1; j++) {
      cout << vt[i][j] << ' ' << vt[i][j + 1] << "\n";
    }
  }
}
