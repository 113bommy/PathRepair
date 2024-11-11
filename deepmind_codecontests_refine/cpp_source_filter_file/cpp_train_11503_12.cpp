#include <bits/stdc++.h>
using namespace std;
long long d[100005], h[100005];
long long ans = 0;
int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> d[i] >> h[i];
  }
  for (int i = 2; i <= m; i++) {
    long long di = max(h[i], h[i - 1]) - min(h[i], h[i - 1]);
    long long di2 = d[i] - d[i - 1];
    if (di2 < di) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    if ((di2 - di) / 2 + max(h[i], h[i - 1]) > ans)
      ans = (di2 - di) / 2 + max(h[i], h[i - 1]);
  }
  if (d[1] + h[1] > ans) ans = d[1] + h[1];
  if (h[m] + n - d[m] > ans) ans = h[m] + n - d[m];
  cout << ans;
  return 0;
}
