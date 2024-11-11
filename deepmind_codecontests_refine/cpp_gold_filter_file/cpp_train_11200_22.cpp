#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int ans = 0;
  map<string, long long int> faces;
  faces["Tetrahedron"] = 4, faces["Cube"] = 6;
  faces["Octahedron"] = 8, faces["Dodecahedron"] = 12;
  faces["Icosahedron"] = 20;
  for (long long int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ans += faces[s];
  }
  cout << ans << '\n';
}
