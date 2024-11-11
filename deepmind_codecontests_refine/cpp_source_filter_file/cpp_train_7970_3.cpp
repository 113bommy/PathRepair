#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, sum = 0, i = 0;
  cin >> n >> k;
  if (240 - k >= 0) {
    for (i = 0;; i += 5) {
      sum += i + 5;
      if (sum > 240 - k) {
        i--;
        break;
      }
    }
  } else {
    cout << "0";
    return 0;
  }
  if (i / 5 + 1 > n)
    cout << n;
  else
    cout << i / 5 + 1;
}
