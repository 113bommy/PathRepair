#include <bits/stdc++.h>
using namespace std;
int max(int x, int y) {
  if (x >= y)
    return x;
  else
    return y;
}
int main() {
  long long int a, b, i, l;
  cin >> a >> b;
  l = max(a, b);
  for (i = 1; i <= l; i++) {
    if (i % 2 != 0)
      a = a - i;
    else if (i % 2 == 0)
      b = b - i;
    if (a < 0) {
      cout << "Vladik";
      break;
    } else if (b < 0) {
      cout << "Valera";
      break;
    }
  }
}
