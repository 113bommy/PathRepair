#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (a == 1 || b == 1)
      cout << "YES"
           << "\n";
    else if (a == 2 && b == 2)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
