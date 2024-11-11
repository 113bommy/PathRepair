#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, count = 0;
  cin >> n;
  vector<string> v;
  for (i = 0; i < n; i++) {
    string str;
    cin >> str;
    v.push_back(str);
  }
  for (i = 0; i < v.size(); i++) {
    if (v[i] == "Tetrahedron")
      count += 4;
    else if (v[i] == "Cube")
      count += 6;
    else if (v[i] == "Octahedron")
      count += 12;
    else if (v[i] == "Dodecahedron")
      count += 12;
    else
      count += 20;
  }
  cout << count;
}
