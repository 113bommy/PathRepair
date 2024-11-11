#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 4 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
