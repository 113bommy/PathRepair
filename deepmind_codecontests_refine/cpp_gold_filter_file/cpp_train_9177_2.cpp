#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100005], min1, min2, cnt0;
int main() {
  cin >> n;
  min1 = 0;
  min2 = 0;
  cnt0 = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0) min1 = max(min1, a[i]);
    if (a[i] < -1) min2 = min(min2, a[i]);
    if (a[i] != 0 && a[i] != -1) cnt0 = 1;
  }
  if (n % 2 == 0) {
    for (long long i = 1; i <= n; i++) {
      if (a[i] >= 0) {
        cout << -a[i] - 1 << " ";
      } else
        cout << a[i] << " ";
    }
  } else {
    long long mk = 0;
    if (cnt0 == 0) {
      for (long long i = 1; i <= n; i++) cout << 0 << " ";
      return 0;
    }
    if (abs(min1 * min2) > abs((-min1 - 1) * (-min2 - 1))) {
      mk = min1;
    } else
      mk = min2;
    if (min1 == 0) mk = min2;
    if (min2 == 0) mk = min1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == mk) {
        if (mk < 0)
          cout << -mk - 1 << " ";
        else
          cout << mk << " ";
        mk = 1e9;
      } else {
        if (a[i] >= 0)
          cout << -a[i] - 1 << " ";
        else
          cout << a[i] << " ";
      }
    }
  }
  return 0;
}
