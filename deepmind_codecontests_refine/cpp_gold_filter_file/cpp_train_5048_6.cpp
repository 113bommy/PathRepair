#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, x[10010], y[10010], temp1, temp2, temp3, temp4;
  long long int ans = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      for (k = j + 1; k < n; k++) {
        temp1 = (x[j] - x[i]);
        temp2 = (y[j] - y[i]);
        temp3 = (x[k] - x[j]);
        temp4 = (y[k] - y[j]);
        if (temp1 * temp4 != temp3 * temp2) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
