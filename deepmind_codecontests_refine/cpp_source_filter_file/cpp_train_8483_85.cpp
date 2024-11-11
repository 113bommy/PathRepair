#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int sama, beda = 0;
  if (a > b) {
    sama = b;
    a -= b;
    b = 0;
  } else if (a == b) {
    sama = a / b;
    a = 0;
    b = 0;
  } else {
    sama = a;
    b -= a;
    a = 0;
  }
  while (a > 1) {
    a -= 2;
    beda++;
  }
  while (b > 1) {
    b -= 2;
    beda++;
  }
  cout << sama << " " << beda;
  return 0;
}
