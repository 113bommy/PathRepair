#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, w;
  int k = 0;
  int j = 0;
  cin >> q >> w;
  for (int x = 0; x < q; x++) {
    int y;
    cin >> y;
    if (5 - x > 0) {
      k++;
    }
  }
  cout << k / 3;
  return 0;
}
