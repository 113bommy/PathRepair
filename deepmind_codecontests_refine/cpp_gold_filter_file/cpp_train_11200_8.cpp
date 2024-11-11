#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  int face = 0;
  for (int i = 0; i <= num; i++) {
    string name;
    getline(cin, name);
    if (name == "Tetrahedron") {
      face += 4;
    }
    if (name == "Cube") {
      face += 6;
    }
    if (name == "Octahedron") {
      face += 8;
    }
    if (name == "Dodecahedron") {
      face += 12;
    }
    if (name == "Icosahedron") {
      face += 20;
    }
  }
  cout << face;
  return 0;
}
