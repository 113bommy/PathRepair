#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  map<string, int> m;
  m["Tetrahedron"] = 4;
  m["Cube"] = 6;
  m["Octahedron"] = 8;
  m["Dodecahedron"] = 12;
  m["Icosahedron"] = 20;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    sum += m[s];
  }
  cout << sum;
  return 0;
}
