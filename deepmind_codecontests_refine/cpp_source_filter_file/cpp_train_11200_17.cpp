#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, s;
  string a;
  s = 0;
  unordered_map<string, int> mp;
  cin >> n;
  mp["Tetrahedron"] == 4;
  mp["Cube"] == 6;
  mp["Octahedron"] == 8;
  mp["Dodecahedron"] == 12;
  mp["Icosahedron"] == 20;
  for (i = 0; i < n; i++) {
    cin >> a;
    s = s + mp[a];
  }
  cout << s;
}
