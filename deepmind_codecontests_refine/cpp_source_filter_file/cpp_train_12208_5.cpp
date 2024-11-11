#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long sum = 0, n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  bool y = 0;
  for (int i = 1; i < n; i++) {
    if ((a[i] - a[i - 1]) >= 2) {
      y = 1;
      break;
    }
  }
  if (!y) {
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
  }
  long long tp = (2 * sum / n - n + 1) / 2;
  long long x = sum - (tp + tp + n - 1) * n / 2;
  long long ans = tp;
  for (int i = 0; i < n; i++) {
    if (x > 0) {
      x = 0;
      cout << ans + 1 << ' ';
    } else {
      cout << ans << ' ';
    }
    ans += 1;
  }
  cout << endl;
  return 0;
}
