#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    string temp;
    cin >> temp;
    if (temp == "Tetrahedron") {
      s += 4;
    }
    if (temp == "Cube") {
      s += 6;
    }
    if (temp == "Octahedron") {
      s += 8;
    }
    if (temp == "Dodecahedron") {
      s += 12;
    }
    if (temp == "Icosahedron") {
      s += 20;
    }
  }
  cout << s;
  return 0;
}
