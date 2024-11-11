#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, p;
  cin >> n;
  cin >> b;
  cin >> p;
  int botellas = (n - 1) * ((2 * b) + 1);
  int toallas = n * p;
  cout << botellas << " " << toallas;
  return 0;
}
