#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  if (k > 34)
    cout << -1 << endl;
  else if (k <= 17) {
    for (int i = 0; i < k; i++) cout << 6;
  } else {
    for (int i = 0; i < k / 2; i++) cout << 8;
    if (k % 2 == 1) cout << 0 << endl;
  }
  return 0;
}
