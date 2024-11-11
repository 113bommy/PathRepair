#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n, suma = 0, sumb = 0, sumc = 0;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    suma += a;
    sumb += b;
    sumc += c;
  }
  if (suma == 0 && sumb == 0 && sumc == 0)
    cout << "yes";
  else
    cout << "no";
  return 0;
}
