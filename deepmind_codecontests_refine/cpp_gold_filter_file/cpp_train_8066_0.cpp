#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long ans = 0;
  int x[105][2];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i][0] >> x[i][1];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 1; j++)
      if (x[j][0] > x[j + 1][0]) {
        swap(x[j][0], x[j + 1][0]);
        swap(x[j][1], x[j + 1][1]);
      }
  int plus = 0;
  int min = 0;
  for (int i = 0; i < n; i++) {
    if (x[i][0] > 0)
      plus++;
    else
      min++;
  }
  if (plus > 0 && min > 0) {
    if ((min - plus) > 1)
      for (int i = min - plus - 1; i < n; i++) ans += x[i][1];
    if ((plus - min) > 1)
      for (int i = n - (plus - min); i >= 0; i--) ans += x[i][1];
    if (plus == min || (plus - min) == 1 || (min - plus) == 1)
      for (int i = 0; i < n; i++) ans += x[i][1];
  }
  if (min == 0) ans = x[0][1];
  if (plus == 0) ans = x[n - 1][1];
  cout << ans;
  return 0;
}
