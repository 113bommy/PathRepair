#include <bits/stdc++.h>
using namespace std;
int n, a[200002], b[200002], pos[200002], i, j, ans;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    cin >> b[i];
    pos[b[i]] = i;
  }
  if (pos[1] != 0) {
    for (i = 1; pos[i] == pos[1] + i - 1; i++) {
      if (pos[i] == n) {
        j = i + 1;
        while (pos[j] <= j - (i + 1) && j <= n) j++;
        if (j > n) {
          cout << n - i << endl;
          return 0;
        }
      }
    }
  }
  for (i = 1; i <= n; i++) ans = max(ans, pos[i] - i + 1);
  cout << ans + n << endl;
  return 0;
}
