#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, counter = 0;
  cin >> n >> a >> b;
  if (b < 0) {
    while (counter < abs(b)) {
      if (a == 1) {
        a = 6;
        counter++;
      } else {
        a--;
        counter++;
      }
    }
  } else if (b > 0) {
    while (counter < b) {
      if (a == 6) {
        a = 1;
        counter++;
      } else {
        a++;
        counter++;
      }
    }
  }
  cout << a;
  return 0;
}
