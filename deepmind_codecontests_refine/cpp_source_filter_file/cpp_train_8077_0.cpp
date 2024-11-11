#include <bits/stdc++.h>
using namespace std;
int min(int x, int y) {
  if (x <= y)
    return x;
  else
    return y;
}
int main() {
  long long int a, b, i, l;
  cin >> a >> b;
  l = min(a, b);
  for (i = 1; i <= l + 1; i++) {
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
