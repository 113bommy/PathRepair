#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, fcount;
  cin >> n;
  map<string, int> polyhedron;
  polyhedron.insert(pair<string, int>("Tetrahedron", 4));
  polyhedron.insert(pair<string, int>("Cube", 6));
  polyhedron.insert(pair<string, int>("Octahedron", 8));
  polyhedron.insert(pair<string, int>("Dodecahedron", 12));
  polyhedron.insert(pair<string, int>("Icosahedron", 20));
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    fcount += polyhedron[a];
  }
  cout << fcount;
}
