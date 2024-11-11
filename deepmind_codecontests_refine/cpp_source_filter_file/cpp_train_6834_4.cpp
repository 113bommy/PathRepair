#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, k1;
  cin >> k;
  k1 = k / 2;
  if (k1 > 500000) {
    cout << "-1";
  } else {
    for (int i = 0; i < k1; i++) {
      cout << 8;
    }
    if (k % 2 == 1) {
      cout << 4;
    }
  }
  return 0;
}
