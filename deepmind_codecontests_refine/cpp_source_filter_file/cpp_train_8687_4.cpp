#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a[1001];
  cin >> n >> m >> k;
  for (int i = 0; i < m + 1; i++) cin >> a[i];
  int f = 0, fri = 0;
  for (int i = 0; i < m; i++) {
    f = 0;
    for (int j = 0; j < n; j++) {
      if (((a[i] >> j) & 1) != (a[m] >> j) & 1) f++;
    }
    if (f <= k) fri++;
  }
  cout << fri << endl;
}
