#include <bits/stdc++.h>
using namespace std;
long long dif[1000005], a[1000005], val[1000005];
;
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i <= a[i] && a[i] <= n) {
      dif[1]--;
      dif[a[i] - i + 1]++;
      dif[a[i] - i + 1]++;
      dif[n - i + 1]--;
      dif[n - i + 1] += abs(1 - a[i]) - abs(n - a[i]);
      dif[n - i + 2] -= abs(1 - a[i]) - abs(n - a[i]);
      dif[n - i + 2]--;
      dif[n]++;
    } else {
      dif[1]++;
      dif[n - i + 1]--;
      dif[n - i + 1] += abs(1 - a[i]) - abs(n - a[i]);
      dif[n - i + 2] -= abs(1 - a[i]) - abs(n - a[i]);
      dif[n - i + 2]--;
      dif[n - i + a[i] + 1]++;
      dif[n - i + a[i] + 1]++;
      dif[n]--;
    }
  }
  for (int i = 2; i < n; i++) dif[i] += dif[i - 1];
  for (int i = 2; i <= n; i++) val[i] += val[i - 1] + dif[i - 1];
  pair<long long, int> p = make_pair(1e18, 1000000000);
  for (int i = 1; i <= n; i++) {
    p = min(p, make_pair(val[i], i));
  }
  int x = p.second - 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    x++;
    if (x == n + 1) x = 1;
    ans += abs(x - a[i]);
  }
  cout << ans << " " << --p.second << endl;
}
