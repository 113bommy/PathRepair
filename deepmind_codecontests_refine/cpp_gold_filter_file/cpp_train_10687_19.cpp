#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int a, b;
  cin >> a >> b;
  while (b > 0 && a > 0) {
    int c = a / 10;
    int d = a % 10;
    if (d > b) {
      a -= b;
      b = 0;
    } else if (d == b) {
      a -= d;
      b = 0;
    } else {
      a = c;
      b -= (d + 1);
    }
  }
  cout << a << endl;
  return 0;
}
