#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, s = 0, y = 0;
  cin >> a >> b;
  for (int i = 1; i <= b; i++) {
    s = s + i * 5;
    if (s + b > 240) {
      y - 1;
      cout << i - 1;
      break;
    }
  }
  if (y == 0) {
    cout << a;
  }
}
