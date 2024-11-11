#include <bits/stdc++.h>
using namespace std;
int n, d, h;
int main() {
  cin >> n >> d >> h;
  if (h < (d + 1) / 2 || (n > 2 and d == h and d == 1))
    cout << -1 << endl;
  else {
    for (int i = 1; i <= d; i++) {
      if (i == h + 1)
        cout << 1 << " " << i + 1 << endl;
      else
        cout << i << " " << i + 1 << endl;
    }
    for (int i = d + 1; i <= n - 1; i++) {
      if (h != d)
        cout << 1 << " " << i + 1 << endl;
      else
        cout << 2 << " " << i + 1 << endl;
    }
  }
  return 0;
}
