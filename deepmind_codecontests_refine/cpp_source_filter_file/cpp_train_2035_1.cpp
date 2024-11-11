#include <bits/stdc++.h>
using namespace std;
int vert1[11234], vert2[11234];
int perm2(int n) {
  if (n == 1) {
    return 0;
  } else {
    return n * (n - 1) / 2;
  }
}
int main() {
  int noVert, aux, res = 0;
  cin >> noVert;
  for (int i = 0; i < noVert - 1; i++) {
    cin >> aux;
    vert1[aux] += 1;
    cin >> aux;
    vert2[aux] += 1;
  }
  for (int i = 0; i < noVert; i++) {
    if (vert1[i] >= 1 && vert2[i] >= 1) {
      res += vert1[i] * vert2[i];
    }
    if (vert1[i] > 1 || vert2[i] > 1) {
      res += perm2(vert1[i]) + perm2(vert2[i]);
    }
  }
  cout << res << endl;
  return 0;
}
