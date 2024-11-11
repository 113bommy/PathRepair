#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, w = 0;
  cin >> n >> h;
  int a[2 * h];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int j = 0; j < n; j++) {
    if (a[j] > h)
      w += 2;
    else if (a[j] < h)
      w += 1;
    else
      w += 1;
  }
  cout << w;
  return 0;
}
