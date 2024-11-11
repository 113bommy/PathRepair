#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int p[m];
  for (long long int i = 0; i < m; i++) cin >> p[i];
  int ans = 0, sum = 0, now = 0;
  while (now < m) {
    long long int r = ((p[now] - sum - 1) / k + 1) * k + sum;
    while (now < m && p[now] <= r) {
      sum++;
      now++;
    }
    ans++;
  }
  cout << ans;
  return 0;
}
