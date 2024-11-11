#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, i, j, k, l;
  cin >> a;
  while (a--) {
    cin >> b;
    if (b == 1)
      cout << -1 << endl;
    else if ((b - 1) % 3 == 0) {
      for (i = 0; i < b - 1; i++) cout << 2;
      cout << 7;
      cout << endl;
    } else {
      for (i = 0; i < b - 1; i++) cout << 2;
      cout << 3;
      cout << endl;
    }
  }
}
