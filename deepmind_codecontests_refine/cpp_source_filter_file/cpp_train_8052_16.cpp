#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, a = 0, b = 0;
  cin >> n;
  cin >> x;
  for (int i = 0; i <= n; i++) {
    cin >> a >> b;
    if (x == a || x == b || x == 7 - a || x == 7 - b) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
