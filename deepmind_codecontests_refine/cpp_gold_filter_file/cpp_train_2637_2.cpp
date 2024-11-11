#include <bits/stdc++.h>
using namespace std;
long long int a, b, c, d, e[4];
int main() {
  cin >> a;
  b = 0;
  e[1] = 0;
  e[2] = 0;
  e[3] = 0;
  while (a > 0) {
    a--;
    cin >> c;
    switch (c) {
      case 4:
        b++;
        break;
      case 3:
        if (e[1] > 0) {
          e[1]--;
          b++;
        } else
          e[3]++;
        break;
      case 2:
        if (e[2] > 1) {
          e[2]--;
          b++;
        } else
          e[2]++;
        break;
      case 1:
        e[1]++;
        break;
    }
  }
  while (e[3] > 0) {
    e[3]--;
    b++;
    if (e[1] > 0) e[1]--;
  }
  while (e[2] > 0) {
    e[2]--;
    b++;
    if (e[2] > 0)
      e[2]--;
    else if (e[1] > 0)
      e[1] -= 2;
  }
  while (e[1] > 0) {
    e[1] -= 4;
    b++;
  }
  cout << b << '\n';
}
