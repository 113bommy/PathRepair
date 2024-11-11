#include <bits/stdc++.h>
using namespace std;
int T, n, a[100005];
int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) cin >> a[j];
    sort(a, a + n);
    int gtmin = min(a[n - 2], a[n - 1]);
    if (n - 2 < gtmin - 1)
      cout << max(n - 2, 0) << "\n";
    else
      cout << max(gtmin - 1, 0);
  }
  return 0;
}
