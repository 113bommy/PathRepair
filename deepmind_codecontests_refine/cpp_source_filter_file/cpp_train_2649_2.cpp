#include <bits/stdc++.h>
using namespace std;
int massiv[999999];
int main() {
  int a, b, sum = 0;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> massiv[i];
  }
  sort(massiv, massiv + a);
  for (int i = 0; i < a; i++) {
    sum = sum + massiv[i] * b;
    if (b > 1) {
      b--;
    }
  }
  cout << sum;
}
