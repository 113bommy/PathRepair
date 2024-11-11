#include <bits/stdc++.h>
using namespace std;
int main() {
  int u, j, n, h, r, i, k, mm;
  cin >> n;
  h = mm = k = 0;
  while (n != 0) {
    j = h;
    cin >> k;
    if (k - j <= 15) {
      h = k;
    } else
      mm = j + 15;
    n--;
  }
  if (mm != 0) {
    cout << mm;
    return 0;
  }
  cout << min(90, h + 15);
  return 0;
}
