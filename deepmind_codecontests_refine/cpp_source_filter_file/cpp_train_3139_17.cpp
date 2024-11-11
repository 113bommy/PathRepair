#include <bits/stdc++.h>
using namespace std;
long long h, d[200005];
int main() {
  int n;
  cin >> h >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d[i] += d[i - 1];
    if (-d[i] >= h) return cout << ++i, 0;
  }
  if (d[n - 1] >= 0) return cout << -1, 0;
  long long ans = h * n;
  for (int i = 0; i < n; i++)
    ans = min(ans, (h + d[i] - d[n - 1]) / -d[n - 1] * n + i + 1);
  cout << ans;
}
