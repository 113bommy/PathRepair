#include <bits/stdc++.h>
using namespace std;
long long x, y, l, t, i;
long long a[100001], b[100001];
int main() {
  cin >> t;
  for (i = 1; i <= t; i++) cin >> a[i] >> b[i];
  for (i = 1; i <= t; i++) {
    if (a[i] == b[i])
      cout << 0 << endl;
    else if (a[i] < b[i] && a[i] % 2 == 1 && b[i] % 2 == 0 ||
             a[i] < b[i] && a[i] % 2 == 0 && b[i] % 2 == 1)
      cout << 1 << endl;
    else if (a[i] > b[i] && a[i] % 2 == 1 && b[i] % 2 == 0 ||
             a[i] > b[i] && a[i] % 2 == 0 && b[i] % 2 == 1)
      cout << 2 << endl;
    else if (a[i] > b[i] && a[i] % 2 == 0 && b[i] % 2 == 0)
      cout << 1 << endl;
    else if (a[i] < b[i] && a[i] % 2 == 0 && b[i] % 2 == 0)
      cout << 2 << endl;
    else if (a[i] > b[i] && a[i] % 2 == 1 && b[i] % 2 == 1)
      cout << 1 << endl;
    else if (a[i] < b[i] && a[i] % 2 == 1 && b[i] % 2 == 1)
      cout << 2 << endl;
  }
}
