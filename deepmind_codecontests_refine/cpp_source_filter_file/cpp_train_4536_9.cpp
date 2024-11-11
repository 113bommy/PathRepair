#include <bits/stdc++.h>
using namespace std;
int main() {
  int f, n, a[200010];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      f = 1;
      break;
    }
    if (a[i] % 2 == 1) {
      if (i == n - 1) {
        f = 1;
        break;
      }
      a[i + 1]--;
    }
  }
  if (f == 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
