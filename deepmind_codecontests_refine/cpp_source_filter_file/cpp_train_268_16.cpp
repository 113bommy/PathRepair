#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> k >> m;
  int a[k];
  int sum = 0;
  for (int i = 0; i < k; i++) cin >> a[i];
  sort(a, a + k);
  for (int i = 0; i < k; i++) sum += a[i];
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int temp = m, temp2 = i * (k + 1);
    if (i * sum > m) break;
    temp -= i * sum;
    for (int j = 0; j < k && temp > 0; j++) {
      int how = min(n - i, temp / a[k]);
      temp -= how * a[k];
      temp2 += how;
    }
    ans = max(ans, temp2);
  }
  cout << ans;
}
