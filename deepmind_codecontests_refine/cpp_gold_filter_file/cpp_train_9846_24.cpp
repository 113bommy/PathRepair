#include <bits/stdc++.h>
using namespace std;
int main() {
  short n;
  long long suma = 0;
  int maksimum = 0;
  cin >> n;
  int *dane = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> dane[i];
    maksimum = max(dane[i], maksimum);
  }
  for (int i = 0; i < n; i++) {
    if (dane[i] < maksimum) suma += (maksimum - dane[i]);
  }
  cout << suma;
  return 0;
}
