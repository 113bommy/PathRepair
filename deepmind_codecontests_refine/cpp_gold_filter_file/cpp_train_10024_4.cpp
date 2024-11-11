#include <bits/stdc++.h>
using namespace std;
int main() {
  int max1 = -1, min1 = 105, i, indexmax, indexmin, n, input;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> input;
    if (input > max1) {
      max1 = input;
      indexmax = i;
    }
    if (input <= min1) {
      min1 = input;
      indexmin = i;
    }
  }
  if (indexmax < indexmin)
    cout << indexmax + n - 1 - indexmin;
  else
    cout << n - indexmin - 2 + indexmax;
  return 0;
}
