#include <bits/stdc++.h>
using namespace std;
int main() {
  int nn, q, w, e, r, z, x;
  cin >> q >> w >> e >> r >> z >> x;
  nn = min(q, min(w, min(e, r)));
  printf("%d\n", max(0, min(nn - z, x - z + 1)));
  return 0;
}
