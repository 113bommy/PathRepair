#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d[7], i, sum = 0;
  cin >> n;
  for (i = 0; i < 7; i++) cin >> d[i];
  for (i = 0;; i++) {
    sum = sum + d[i];
    if (sum >= n) {
      cout << (i + 1);
      break;
    }
    if (i > 6) i = -1;
  }
  return 0;
}
