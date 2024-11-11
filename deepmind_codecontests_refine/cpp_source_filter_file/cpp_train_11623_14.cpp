#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, sg, i, j, k;
  cin >> v1 >> v2 >> v3 >> sg;
  for (i = 2 * v1; i; i--)
    for (j = min(2 * v2, i - 1); j; j--)
      for (k = i - 1; k; k--)
        if (max(max(sg, v1), 2 * sg - 1) <= i &&
            max(max(sg, v2), 2 * sg - 1) <= j && max(sg, v3) <= k &&
            k <= min(2 * sg, 2 * v3)) {
          cout << i << endl << j << endl << k << endl;
          return 0;
        }
  cout << -1 << endl;
  return 0;
}
