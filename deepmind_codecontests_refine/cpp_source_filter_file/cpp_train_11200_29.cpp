#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  string x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == "Tetrahedron") {
      sum += 4;
    }
    if (x == "Cube") {
      sum += 6;
    }
    if (x == "Octahedron ") {
      sum += 8;
    }
    if (x == "Dodecahedron") {
      sum += 12;
    }
    if (x == "Icosahedron") {
      sum += 20;
    }
  }
  cout << sum << endl;
}
