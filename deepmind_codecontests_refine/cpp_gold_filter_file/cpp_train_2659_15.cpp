#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, w = 0, t;
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t <= h)
      w++;
    else
      w += 2;
  }
  cout << w;
}
