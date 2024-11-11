#include <bits/stdc++.h>
using namespace std;
int c[300001];
int main() {
  int n, k, i, a = 0, b = 0, maxim = 0, j = 0, ri = -1, rj = -1, dist = 0;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> c[i];
  for (i = 0; i < n; i++) {
    if (c[i] == 0)
      a++;
    else
      b++;
    while (j <= i && !(a <= k)) {
      if (c[j] == 0)
        a--;
      else
        b--;
      j++;
    }
    if (a + b > maxim) {
      maxim = a + b;
      dist = a + b;
      ri = i;
      rj = j;
    }
  }
  for (i = rj; i <= ri; i++) c[i] = 1;
  cout << dist << "\n";
  for (i = 0; i < n; i++) cout << c[i] << " ";
  return 0;
}
