#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int cislo = 1000000007;
  long long int *pole = new long long int[n];
  pole[0] = 1;
  pole[1] = 2;
  long long int red = 1;
  long long int blue = 2;
  if (n == 2) {
    cout << 3 << endl;
    return 0;
  } else if (n == 1) {
    cout << 1 << endl;
    return 0;
  } else {
    for (int i = 2; i < n; i++) {
      if (i % 2 == 0) {
        pole[i] = (1 + blue) % cislo;
        red += pole[i] % cislo;
      } else if (i % 2 != 0) {
        pole[i] = (1 + red) % cislo;
        blue += pole[i] % cislo;
      }
    }
  }
  long long int vys = 0;
  for (int i = 0; i < n; i++) {
    vys += pole[i] % cislo;
  }
  cout << vys % cislo << endl;
  return 0;
}
