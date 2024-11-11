#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char c;
  bool aparece = false;
  int x, y, longitud = 0;
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(m); j++) {
      cin >> c;
      if (c == 'B' && !aparece) {
        x = i + 1;
        y = j + 1;
        aparece = !aparece;
      }
      if (c == 'B') longitud++;
    }
  }
  longitud = sqrt(longitud) / 2;
  cerr << longitud << '\n';
  cout << x + longitud << " " << y + longitud;
  return 0;
}
