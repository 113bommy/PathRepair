#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0;
  int n;
  cin >> n;
  string s;
  for (int i = 1; i < n; i++) {
    cin >> s;
    if (s == "Cube")
      c += 6;
    else if (s == "Tetrahedron")
      c += 4;
    else if (s == "Octahedron")
      c += 8;
    else if (s == "Icosahedron")
      c += 20;
    else
      c += 12;
  }
  cout << c << endl;
  return 0;
}
