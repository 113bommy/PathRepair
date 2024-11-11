#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<string, int> cr;
  cr["Tetrahedron"] = 4;
  cr["Cube"] = 6;
  cr["Octahedron"] = 8;
  cr["Dodecahedron"] = 12;
  cr["Icosahedron"] = 20;
  int sum = 0;
  while (n--) {
    string s;
    cin >> s;
    sum += cr[s];
  }
  cout << sum << "\n";
  return 0;
}
