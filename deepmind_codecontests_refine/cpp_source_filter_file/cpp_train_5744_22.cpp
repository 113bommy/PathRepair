#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0;
  cin >> n;
  bool done = false;
  do {
    int a = n;
    while (a > 10) {
      s += a % 10;
      a = a / 10;
    }
    if (s % 4 == 0) {
      done = true;
    } else {
      n++;
    }
    s = 0;
  } while (!done);
  cout << n << endl;
  return 0;
}
