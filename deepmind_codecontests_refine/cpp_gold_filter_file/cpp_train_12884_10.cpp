#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k, l;
  cin >> n;
  l = n;
  int arrap[200000], arran[200000];
  for (i = 0; i < n; i++) {
    cin >> k;
    if (k < 0) {
      k = -1 * k;
      if (arran[k] != 1)
        arran[k] = 1;
      else
        l--;
    } else if (k > 0) {
      if (arrap[k] != 1)
        arrap[k] = 1;
      else
        l--;
    } else
      l--;
  }
  cout << l;
  return 0;
}
