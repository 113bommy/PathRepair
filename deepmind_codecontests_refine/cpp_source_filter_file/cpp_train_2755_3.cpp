#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1000];
  cin >> n;
  cin >> a[1] >> a[2] >> a[3];
  int max = 0;
  if (n == 3) {
    max = a[3] - a[1];
    cout << max;
    return 0;
  }
  for (int i = 4; i < n + 1; i++) {
    cin >> a[i];
    if (a[i - 1] - a[i - 2] > max) max = a[i - 1] - a[i - 2];
  }
  if (a[n] - a[n - 1] > max) max = a[n] - a[n - 1];
  int ans = a[3] - a[1];
  for (int i = 3; i < n + 1; i++) {
    if (a[i] - a[i - 2] < max && a[i] - a[i - 2] <= ans)
      ans = max;
    else if (a[i] - a[i - 2] > max && a[i] - a[i - 2] > ans)
      continue;
    else if (a[i] - a[i - 2] > max && a[i] - a[i - 2] < ans)
      ans = a[i] - a[i - 2];
  }
  cout << ans;
  return 0;
}
