#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, g = 0;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "Tetrahedron") {
      g += 4;
    }
    if (s == "Cube") {
      g += 6;
    }
    if (s == "Octahedron") {
      g += 8;
    }
    if (s == "Dodecahedron") {
      g += 12;
    }
    if (s == "Icosahedron") {
      g += 20;
    }
  }
  cout << g;
  return 0;
}
