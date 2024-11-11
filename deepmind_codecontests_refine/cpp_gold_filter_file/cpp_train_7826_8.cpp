#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long x, y;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    if (abs(x - y) == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
