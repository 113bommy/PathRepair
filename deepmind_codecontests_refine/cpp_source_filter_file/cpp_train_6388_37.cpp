#include <bits/stdc++.h>
using namespace std;
int a, b, i;
int main() {
  cin >> b;
  for (i = 1; i <= b; i++) {
    cin >> a;
    if (a == 1 && a == 2)
      cout << 0 << endl;
    else
      cout << a - 2 << endl;
  }
  return 0;
}
