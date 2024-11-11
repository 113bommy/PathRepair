#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a[1000], x, y;
  cin >> n >> m >> k;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (a[x - 1] > y || a[x - 1] == 0) a[x - 1] = y;
  }
  int sum = 0;
  for (int i = 0; i < m; i++) sum += a[i];
  if (sum < k)
    cout << sum << endl;
  else
    cout << k << endl;
  return 0;
}
