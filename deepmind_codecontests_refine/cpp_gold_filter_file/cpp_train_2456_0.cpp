#include <bits/stdc++.h>
using namespace std;
int main() {
  long long loop, minus, a, b, counter = 0;
  cin >> loop >> minus >> a;
  for (int i = 1; i < loop; i++) {
    cin >> b;
    if (a >= b) {
      if ((a - b) % minus == 0) {
        counter += (a - b) / minus * i;
      } else {
        counter = -1;
        break;
      }
    } else {
      if ((b - a) % minus == 0) {
        counter += (b - a) / minus;
        b -= b - a;
      } else {
        counter = -1;
        break;
      }
    }
    a = b;
  }
  cout << counter << endl;
  return 0;
}
