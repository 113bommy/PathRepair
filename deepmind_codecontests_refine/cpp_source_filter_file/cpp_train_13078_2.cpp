#include <bits/stdc++.h>
using namespace std;
int a[855];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i + n] = a[i];
  }
  int ans = 360;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = i; j <= 2 * n; j++) {
      sum += a[i];
      int dx = 2 * abs(sum - 180);
      ans = min(ans, dx);
    }
  }
  cout << ans << endl;
  return 0;
}
