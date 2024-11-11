#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, k;
  cin >> n >> m >> k;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  long long dis = INT_MAX;
  for (i = m - 1; i >= 0; i--) {
    if (a[i] == 0) continue;
    if (a[i] <= k) {
      dis = m - 1 - i;
      break;
    }
  }
  for (i = m - 1; i < n; i++) {
    if (a[i] == 0) continue;
    if (a[i] <= k) {
      if (dis > i - m - 1) {
        dis = i - m + 1;
      }
      break;
    }
  }
  cout << dis * 10 << endl;
  return 0;
}
