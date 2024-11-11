#include <bits/stdc++.h>
using namespace std;
int n, r, res;
int a[200005];
int dd[200005];
void xuli() {
  for (int i = 1; i <= n; i++)
    if (a[i])
      for (int j = max(1, i - r + 1); j <= min(n, i + r - 1); j++) dd[j]++;
  for (int i = 1; i <= n; i++)
    if (!dd[i]) {
      cout << -1;
      return;
    }
  for (int i = 1; i <= n; i++) {
    int cnt = 1000;
    for (int j = max(1, i - r + 1); j <= min(n, i + r - 1); j++)
      cnt = min(cnt, dd[j]);
    if (cnt > 1) {
      res--;
      for (int j = max(1, i - r + 1); j <= min(n, i + r - 1); j++) dd[j]--;
    }
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> r;
  for (int i = 1; i <= n; i++) cin >> a[i], res += a[i];
  xuli();
}
