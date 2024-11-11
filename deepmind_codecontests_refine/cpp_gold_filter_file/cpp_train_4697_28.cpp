#include <bits/stdc++.h>
using namespace std;
int a, b, c, i;
int main() {
  cin >> a >> b >> c;
  while (a >= b + c) {
    b++;
    i++;
  }
  while (b >= a + c) {
    a++;
    i++;
  }
  while (c >= a + b) {
    a++;
    i++;
  }
  cout << i;
  return 0;
}
