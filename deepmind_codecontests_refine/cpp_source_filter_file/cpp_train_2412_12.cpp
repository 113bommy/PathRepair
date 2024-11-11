#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int r, i, j, k;
  cin >> r;
  r--;
  if (r % 2 != 0)
    cout << "NO";
  else if (r <= 0)
    cout << "NO";
  else {
    for (i = 1;; i++) {
      k = (r - i - (i * i));
      if (k >= 0) {
        j = k / (2 * i);
        if (j % (2 * i) == 0) {
          cout << i << " " << j;
          break;
        }
      } else
        continue;
    }
  }
}
