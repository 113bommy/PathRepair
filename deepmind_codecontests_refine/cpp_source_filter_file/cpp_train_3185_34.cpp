#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  int b;
  int counter = 0;
  cin >> a;
  cin >> b;
  while (a < b) {
    a += 2 * a;
    b += b;
    counter++;
  }
  cout << counter;
  return 0;
}
