#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, p, q;
  cin >> n;
  for (int k = 0; k < n; k++) {
    cin >> p >> q;
    if (q - p >= 2) {
      i++;
    }
  }
  cout << i;
}
