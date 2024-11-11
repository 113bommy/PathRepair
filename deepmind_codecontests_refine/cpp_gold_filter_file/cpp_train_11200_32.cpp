#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, face = 0, i;
  char a[20];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (strcmp(a, "Tetrahedron") == 0) {
      face = face + 4;
    } else if (strcmp(a, "Cube") == 0) {
      face = face + 6;
    } else if (strcmp(a, "Octahedron") == 0) {
      face = face + 8;
    } else if (strcmp(a, "Dodecahedron") == 0) {
      face = face + 12;
    } else if (strcmp(a, "Icosahedron") == 0) {
      face = face + 20;
    }
  }
  cout << face;
  return 0;
}
