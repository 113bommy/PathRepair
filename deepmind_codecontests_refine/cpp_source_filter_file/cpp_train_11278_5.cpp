#include <bits/stdc++.h>
using namespace std;
int a, b, m, r0, r, i = 0, j, nr, viz[10000], v[10000];
int main() {
  int o = 1;
  cin >> a >> b >> m >> r0;
  r = r0;
  while (o++) {
    r = (a * r + b) % m;
    v[i] = r;
    viz[r]++;
    if (viz[r] == 2) {
      for (j = i - 1; j >= 0; j--) {
        nr++;
        if (viz[v[j]] == 2) {
          break;
        }
      }
      break;
    }
    i++;
  }
  cout << nr;
  return 0;
}
