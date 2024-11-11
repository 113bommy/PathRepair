#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, counter = 0;
  cin >> n >> a >> b;
  if (b < 0) {
    while (counter < abs(b)) {
      if (a == 1) {
        a = n;
        counter++;
      } else {
        a--;
        counter++;
      }
    }
  } else if (b > 0) {
    while (counter < b) {
      if (a == n) {
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
