#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  string s;
  cin >> a;
  for (int o = 0; o < a; o++) {
    cin >> s;
    if (s == "Icosahedron") b = 20;
    if (s == "Cube") b = b + 6;
    if (s == "Dodecahedron") b = b + 12;
    if (s == "Tetrahedron") b = b + 4;
    if (s == "Octahedron") b = b + 8;
  }
  cout << b << endl;
}
