#include <bits/stdc++.h>
using namespace std;
int a[110000], b[110000];
int main() {
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[j]);
      if (j) {
        b[a[j]] = a[j - 1];
      }
    }
  }
  int ans = n - k, id = 1;
  for (int i = 2; i <= n; i++) {
    if (b[i] != i - 1) {
      id = i - 1;
      break;
    }
    if (i == n) id = n;
  }
  ans -= (id - 1);
  ans += (n - id);
  cout << ans << endl;
  return 0;
}
