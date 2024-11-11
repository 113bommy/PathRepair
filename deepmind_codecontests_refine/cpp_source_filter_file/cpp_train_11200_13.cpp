#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int count = 0;
  while (n--) {
    string s;
    cin >> s;
    s[0] = tolower(s[0]);
    if (s == "cube") {
      count += 6;
    } else if (s == "tetrahedron") {
      count += 4;
    } else if (s == "octahedron") {
      count += 8;
    } else if (s == "dodecagedron") {
      count += 12;
    } else if (s == "icosahedron") {
      count += 20;
    }
  }
  cout << count << endl;
}
