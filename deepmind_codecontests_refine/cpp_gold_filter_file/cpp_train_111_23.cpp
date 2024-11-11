#include <bits/stdc++.h>
using namespace std;
int n, i, a[20020], sum, k;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  sort(a + 1, a + n + 1);
  for (k = a[n]; k <= 201; k++) {
    int now = 0;
    for (i = 1; i <= n; i++) now += max(0, k - a[i]);
    if (now > sum) {
      cout << k << endl;
      return 0;
    }
  }
}
