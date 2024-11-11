#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  long long int n, x, c1 = 0, i, p;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> c >> p;
    if (c == '+') {
      x = x + p;
    } else {
      if (c == '-' && x >= p) {
        x = x - p;
      } else {
        c1++;
      }
    }
  }
  cout << x << " " << c1;
  return 0;
}
