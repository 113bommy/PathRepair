#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, k = 0, nod;
  cin >> a;
  for (int i = 2; i < a; i++) {
    int b = a;
    while (b != 0) {
      k += b % i;
      b /= i;
    }
  }
  int b = a - 2;
  for (int i = k; i > 0; i--)
    if (k % i == 0 && b % i == 0) {
      nod = i;
      k /= nod;
      b /= nod;
      break;
    }
  cout << k << '/' << b;
}
