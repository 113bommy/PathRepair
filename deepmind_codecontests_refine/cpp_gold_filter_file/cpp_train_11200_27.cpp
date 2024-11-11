#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == "Cube") {
      x = x + 6;
    } else if (s[i] == "Tetrahedron") {
      x = x + 4;
    } else if (s[i] == "Octahedron") {
      x = x + 8;
    } else if (s[i] == "Dodecahedron") {
      x = x + 12;
    } else if (s[i] == "Icosahedron") {
      x = x + 20;
    }
  }
  cout << x << endl;
  return 0;
}
