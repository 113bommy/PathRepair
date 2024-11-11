#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c, n, k = 0;
  cin >> n;
  if (n == 1) {
    cin >> a;
    if (a == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  } else {
    for (c = 0; n > c; c++) {
      cin >> a;
      if (a == 0) k++;
    }
    if (k == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
