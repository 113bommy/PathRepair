#include <bits/stdc++.h>
using namespace std;
void count(void) {
  int n, d, x;
  cin >> n >> d;
  x = sqrt(d);
  if (x + (d / x) - (d % x == 0) <= n) {
    cout << "yes\n";
  } else {
    x++;
    if (x + (d / x) - (d % x == 0) <= n) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
int main() {
  int T;
  cin >> T;
  for (; T > 0; T--) {
    count();
  }
  return 0;
}
