#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
int a, s, d, f, g, q, w, e, r, h, j;
int ar[100000];
int arz[400000];
int arx[100000];
int main() {
  cin >> a >> f;
  for (s = 0; s < a; ++s) {
    cin >> ar[s];
  }
  g = h = 0;
  for (s = 0; s < a; ++s) {
    if (ar[s] == -1) {
      ++g;
    } else {
      ++h;
    }
  }
  for (s = 0; s < f; ++s) {
    cin >> q >> w;
    e = w - q + 1;
    if (e % 2 != 0) {
      cout << 0 << endl;
    } else {
      if ((e / 2 <= q) && (e / 2 <= w)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
}
