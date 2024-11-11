#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt, n, m;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    if (n == 1)
      cout << 0 << endl;
    else if (n < 3)
      cout << m << endl;
    else
      cout << m * 2 << endl;
  }
  return 0;
}
