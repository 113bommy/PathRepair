#include <bits/stdc++.h>
int i, j, k;
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[100005], b[100005];
  int ans = 0;
  int sum = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ans += a[i] / 10;
    sum += a[i];
    b[i] = a[i] % 10;
  }
  if (k > 100 * n - sum) {
    cout << 10 * n << endl;
    return 0;
  }
  int c[100005];
  for (i = 0; i < n; i++) c[i] = 10 - b[i];
  sort(c, c + n);
  for (i = 0; i < n; i++) {
    if (k - c[i] < 0 || c[i] == 10) break;
    if (k - c[i] >= 0) {
      k = k - c[i];
      ans++;
    }
  }
  ans += k / 10;
  cout << ans << endl;
  return 0;
}
