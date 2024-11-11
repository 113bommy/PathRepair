#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, rem = 0;
  cin >> a >> b;
  c = a;
  while (a != 0) {
    rem += a % b;
    a = a / b;
    if (rem >= 5) {
      rem -= 5;
      c++;
    }
    c += a;
  }
  cout << c;
  return 0;
}
