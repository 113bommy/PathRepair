#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, r;
  cin >> k >> r;
  int i = 1;
  int c = 0;
  int a = 0;
  if (k % 10 == 0)
    c = k / 10;
  else if (k % 10 == r)
    c = 1;
  else {
    do {
      i++;
      a = k * i;
      if (a % 10 == 0) {
        c = a / k;
        break;
      }
      c = i;
    } while (a % 10 != r);
  }
  cout << c;
}
