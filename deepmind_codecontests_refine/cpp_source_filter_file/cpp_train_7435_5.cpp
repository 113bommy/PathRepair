#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, ans = 0, temp = 1;
  cin >> n;
  long long a[n], b[n];
  for (long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long i = 0; i < n; i++) {
    cin >> b[i];
    if (2 * a[i] >= b[i]) {
      if (b[i] % 2 == 0) {
        temp = (b[i] / 2 * b[i] / 2);
      } else {
        if (b[i] != 1)
          temp = (b[i] / 2 * ((b[i] / 2) + 1));
        else
          temp = -1;
      }
    } else
      temp = -1;
    ans += temp;
  }
  cout << ans << "\n";
  return 0;
}
