#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f = 0;
  cin >> n;
  string poly[5] = {"Tetrahedron", "Cube", "Octahedron", "Dodecahedron",
                    "Icosahedron"};
  string inp[n];
  for (int i = 0; i < n; i++) {
    cin >> inp[i];
    if (inp[i] == poly[0])
      f += 4;
    else if (inp[i] == poly[1])
      f += 6;
    else if (inp[i] == poly[2])
      f += 8;
    else if (inp[i] == poly[3])
      f += 12;
    else if (inp[i] == poly[4])
      f += 20;
  }
  cout << f / 5;
  return 0;
}
