#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << a;
    return 0;
  } else {
    int iter;
    if (a < b) {
      iter = b - a;
      cout << a << " ";
    } else {
      iter = a - b;
      cout << b << " ";
    }
    int k = 0;
    while (iter >= 2) {
      k++;
      iter -= 2;
    }
    cout << k;
  }
}
