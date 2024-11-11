#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  if (k <= 2) {
    cout << 1 << "\n1";
  } else if (k == 3) {
    cout << 2 << "\n1 3";
  } else if (k == 4) {
    cout << 4 << "\n2 4 1 3";
  } else {
    cout << k << "\n";
    for (int i = 1; i <= k; i += 2) cout << i << " ";
    for (int i = 2; i <= k; i += 2) cout << i << " ";
  }
}
