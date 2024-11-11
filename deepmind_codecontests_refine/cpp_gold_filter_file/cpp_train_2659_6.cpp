#include <bits/stdc++.h>
using namespace std;
int main() {
  const int siz = 1000;
  int n, w = 0, h;
  cin >> n;
  cin >> h;
  int a[siz];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (h <= 1000 && a[i] >= 1 && a[i] <= 2 * h) {
      if (a[i] <= h) w += 1;
      if (a[i] > h) w += 2;
    }
  }
  cout << w;
  return 0;
}
