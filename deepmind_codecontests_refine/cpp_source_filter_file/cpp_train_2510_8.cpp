#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, i, counter = 0, x = 0;
  cin >> b;
  for (i = 1; i <= sqrt(b); i++) {
    if (b % i == 0) counter++;
  }
  x = sqrt(b);
  if (x == sqrt(b))
    cout << counter * 2 - 1 << endl;
  else
    cout << counter * 2 << endl;
}
