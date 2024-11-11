#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int a[n], ans = 0;
  bool out = false;
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i - 1] == 1 && a[i] == 2) {
      if (i >= 2)
        ans += 3;
      else if (a[i - 2] != 3)
        ans += 3;
      else
        ans += 2;
    }
    if (a[i - 1] == 1 && a[i] == 3) ans += 4;
    if (a[i - 1] == 2 && a[i] == 1) ans += 3;
    if (a[i - 1] == 3 && a[i] == 1) ans += 4;
    if (a[i - 1] == 2 && a[i] == 3) {
      out = true;
      break;
    }
    if (a[i - 1] == 3 && a[i] == 2) {
      out = true;
      break;
    }
  }
  if (out)
    cout << "Infinite" << endl;
  else {
    cout << "Finite" << endl;
    cout << ans << endl;
  }
}
