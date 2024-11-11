#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n <= 2)
      cout << 0 << endl;
    else
      cout << n - 2 << endl;
  }
  return 0;
}
