#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, x = 0, c, d = pow(10, 9) + 7, e = 2;
  cin >> a >> b;
  a = a - b;
  if (c == 0) {
    cout << "infinity";
  } else {
    for (int i = 1; i * i <= a; i++) {
      if (a % i == 0) {
        if (i > b) x++;
        if (c / i > b and c / i != i) x++;
      }
    }
    cout << x;
  }
  return 0;
}
