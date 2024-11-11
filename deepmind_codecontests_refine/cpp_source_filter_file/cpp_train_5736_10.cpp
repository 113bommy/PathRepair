#include <bits/stdc++.h>
using namespace std;
long long a[200000 + 1], sum[200000 + 1], num[200000 << 1 | 1];
int main() {
  int n, m, pos;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == m) pos = i;
  }
  memset(num, 0, sizeof(num));
  num[200000]++;
  sum[0] = 0;
  long long ans = 0;
  for (int j = 1; j <= n; j++) {
    if (a[j] < a[pos])
      sum[j] = sum[j - 1] - 1;
    else if (a[j] == a[pos])
      sum[j] = sum[j - 1];
    else
      sum[j] = sum[j - 1] + 1;
    if (j < pos)
      num[sum[j] + 200000]++;
    else {
      ans += num[sum[j] + 200000] + num[sum[j] + 1 + 200000];
    }
  }
  cout << ans << endl;
  return 0;
}
