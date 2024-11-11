#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int ctr = a;
  int rem = 0;
  while (1) {
    if (a < b) break;
    rem = a % b;
    a = a / 2;
    ctr = ctr + a;
    a = a + rem;
  }
  cout << ctr << "\n";
}
