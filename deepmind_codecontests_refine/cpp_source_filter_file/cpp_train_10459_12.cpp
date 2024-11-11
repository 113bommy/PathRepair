#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, count = 0, base, i;
  cin >> a >> b;
  base = a - b;
  if (b >= a && (a != 0 || (a == 0 && b == 0)))
    cout << "infinity";
  else {
    for (i = 1; i * i <= base; i++) {
      if (a % i == b) count++;
      if (a % (base / i) == b && i != (base / i)) count++;
    }
    cout << count;
  }
  return 0;
}
