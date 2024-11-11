#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int min1, n, c;
  bool f = false;
  cin >> n;
  min1 = n + 1;
  while (1) {
    long long int q = min1;
    while (q > 0) {
      if (q % 10 == 8) {
        f = true;
        break;
      }
      q = q / 10;
      if (q == 0) break;
    }
    if (f)
      break;
    else
      min1++;
  }
  cout << min1 - n;
  return 0;
}
