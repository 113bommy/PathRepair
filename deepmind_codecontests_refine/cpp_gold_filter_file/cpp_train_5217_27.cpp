#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  if (n <= 10)
    cout << 0 << endl;
  else {
    m = n - 10;
    if (m == 10)
      cout << 15 << endl;
    else if (m >= 1 && m <= 11) {
      cout << 4 << endl;
    } else
      cout << 0 << endl;
  }
}
