#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p;
  cin >> n;
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (a[0] > a[1]) b[0] = 5;
  if (a[0] < a[1]) b[0] = 1;
  if (a[0] == a[1]) b[0] = 3;
  for (long long i = 0; i < n - 1; i++) {
    if ((a[i + 1] > a[i]) && (b[i] == 5)) {
      cout << -1 << endl;
      return 0;
    } else if ((a[i + 1] < a[i]) && (b[i] == 1)) {
      cout << -1 << endl;
      return 0;
    } else if (a[i + 1] > a[i]) {
      p = b[i] + 1;
      if ((i + 2) < n) {
        if (a[i + 2] < a[i + 1]) p = 5;
      }
    } else if (a[i + 1] < a[i]) {
      p = b[i] - 1;
      if ((i + 2) < n) {
        if (a[i + 2] > a[i + 1]) p = 1;
      }
    } else if (a[i + 1] == a[i]) {
      p = (b[i] == 3) ? 2 : 3;
      if ((i + 2) < n) {
        if (a[i + 2] > a[i + 1])
          p = (b[i] == 1) ? 2 : 1;
        else if (a[i + 2] < a[i + 1])
          p = (b[i] == 5) ? 4 : 5;
      }
    }
    b[i + 1] = p;
  }
  for (long long i = 0; i < n; i++) cout << b[i] << " ";
  return 0;
}
