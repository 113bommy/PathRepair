#include <bits/stdc++.h>
using namespace std;
int sum[5003] = {0};
int main() {
  int i, j, n, k;
  double ans = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }
  for (i = k; i <= n; i++)
    for (j = 1; j <= n - k + 1; j++) {
      ans = max(ans, double(sum[j + k - 1] - sum[j - 1]) / k);
    }
  cout << setprecision(15) << ans << endl;
  return 0;
}
