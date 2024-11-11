#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int a, b;
  char a2, b2;
  string cadena;
  scanf("%i %i", &n, &m);
  cin >> cadena;
  for (int i = 0; i < m; i++) {
    scanf("%i %i %c %c", &a, &b, &a2, &b2);
    if (a == b && cadena[a - 1] == a2) {
      cadena[a - 1] = b2;
    } else {
      for (int j = a - 1; j < b; j++) {
        if (cadena[j] == a2) {
          cadena[j] = b2;
        }
      }
    }
  }
  cout << cadena << "\n";
  return 0;
}
