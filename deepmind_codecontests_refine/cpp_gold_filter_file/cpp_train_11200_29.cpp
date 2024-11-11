#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, result = 0;
  string inp;
  map<string, int> s;
  s["Tetrahedron"] = 4;
  s["Cube"] = 6;
  s["Octahedron"] = 8;
  s["Dodecahedron"] = 12;
  s["Icosahedron"] = 20;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    result += s[inp];
  }
  cout << result;
  return 0;
}
