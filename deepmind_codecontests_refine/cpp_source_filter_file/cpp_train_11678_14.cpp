#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 5;
long long a[N];
long long sum[N];
long long pans[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long mins = 1e18;
    if (i <= m) {
      for (int j = 1; j < i; j++) {
        mins = min(mins, sum[j]);
      }
      pans[i] = sum[i] - mins - k;
      ans = max(pans[i], ans);
      continue;
    }
    for (int j = i - m + 1; j < i; j++) {
      mins = min(mins, sum[j]);
    }
    pans[i] = max(sum[i] - mins - k, pans[i - m] - k + sum[i] - sum[i - m]);
    ans = max(pans[i], ans);
  }
  cout << ans;
}
