#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d;
  cin >> n >> d;
  int a[n + 1], ans = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (a[i] - a[j] <= d && a[i] - a[j] >= -d) ans += 2;
  cout << ans;
  return 0;
}
