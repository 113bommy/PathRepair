#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  while (cin >> n >> m >> k) {
    int a[m + 5];
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++) {
      int p, q;
      cin >> p >> q;
      if (a[p] == -1) {
        a[p] = q;
      } else {
        int x = min(a[p], q);
        a[p] = x;
      }
    }
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
      sum += a[i];
    }
    if (sum <= k)
      cout << sum << endl;
    else
      cout << k << endl;
  }
  return 0;
}
