#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, counter = 0;
  cin >> n;
  string temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == "Tetrahedron") counter = counter + 4;
    if (temp == "Cube") counter = counter + 6;
    if (temp == "Octahedron") counter = counter + 8;
    if (temp == "Dodecahedron") counter = counter + 12;
    if (temp == "Icosahedron") counter = counter + 20;
  }
  cout << counter << endl;
}
