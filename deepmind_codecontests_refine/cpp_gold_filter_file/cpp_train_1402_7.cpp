#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b;
  cin >> a >> b;
  if (b - a + 1 < 3) {
    cout << "-1";
  } else if (a % 2 == 0) {
    cout << a << " " << a + 1 << " " << a + 2;
  } else if (b - a + 1 > 3) {
    cout << a + 1 << " " << a + 2 << " " << a + 3;
  } else {
    cout << "-1";
  }
  return 0;
}
