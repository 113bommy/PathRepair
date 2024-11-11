#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, b1, b2, b3, n;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  int sumb = b1 + b2 + b3;
  int suma = a1 + a2 + a3;
  n -= sumb / 10;
  if (sumb % 10 != 0) {
    n--;
  }
  n -= suma / 5;
  if (suma % 5 != 0) {
    n--;
  }
  if (n < 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
