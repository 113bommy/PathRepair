#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100005];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 0) {
      cout << ans << endl;
      continue;
    } else {
      ans += a[i];
      cout << ans << endl;
      int j = 0, t = 0;
      for (;;) {
        if (i + pow(2, j) < n) {
          t = j;
          j++;
        } else {
          break;
        }
      }
      a[i + (int)pow(2, t)] += a[i];
      a[i] = 0;
    }
  }
  return 0;
}
