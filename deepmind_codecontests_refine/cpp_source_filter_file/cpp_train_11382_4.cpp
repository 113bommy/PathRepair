#include <bits/stdc++.h>
using namespace std;
int main() {
  string m, d;
  cin >> m;
  cin >> d;
  const char *mo = m.c_str();
  int ml = m.length();
  const char *dr = d.c_str();
  int dl = d.length();
  int min = dl;
  int match = 0;
  for (int off = 0; off < ml + dl - 1; off++) {
    match = 0;
    for (int j = 0; j < dl; j++) {
      if (j - dl + off >= 0 && j - dl + off < ml) {
        if (dr[j] == mo[j - dl + off]) {
          match++;
        }
      }
    }
    if (dl - match < min) min = dl - match;
  }
  cout << min << endl;
  return 0;
}
