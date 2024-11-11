#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1000] = {0}, n = 0, h = 0, w = 0;
  cin >> n;
  cin >> h;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= h)
      w += 2;
    else
      w += 1;
  }
  cout << w;
}
