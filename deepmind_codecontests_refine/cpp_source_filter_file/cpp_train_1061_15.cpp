#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b;
  a = n / 36;
  n = n % 36;
  if (n % 3 == 0)
    b = n / 3;
  else if (n % 3 == 1)
    b = n / 3;
  else
    b = n / 3 + 1;
  if (b >= 8) {
    b = 0;
    a++;
  }
  cout << a << " " << b << endl;
}
