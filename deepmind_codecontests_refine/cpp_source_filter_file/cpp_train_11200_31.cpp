#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, face = 0, i;
  char a[20];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (strcmp(a, "tetrahedron") == 0) {
      face = face + 4;
    } else if (strcmp(a, "cube") == 0) {
      face = face + 6;
    } else if (strcmp(a, "octahedron") == 0) {
      face = face + 8;
    } else if (strcmp(a, "dodecahedron") == 0) {
      face = face + 12;
    } else if (strcmp(a, "icosahedron") == 0) {
      face = face + 20;
    }
  }
  cout << face;
  return 0;
}
