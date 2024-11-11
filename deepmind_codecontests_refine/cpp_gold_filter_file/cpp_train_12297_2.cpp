#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  long long l, r, sum = 0, x, y, z, g;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    x = (r - l);
    y = (l * pow(-1, l)) + ((l + 1) * pow(-1, (l + 1)));
    z = y + ((l + 2) * pow(-1, (l + 2)));
    if (x == 1) {
      sum = y;
      arr[i] = sum;
      continue;
    } else if (x == 2) {
      sum = z;
      arr[i] = sum;
      continue;
    }
    if (l == r) {
      sum = (l * pow(-1, l));
      arr[i] = sum;
      continue;
    }
    if (x % 2 == 1) {
      if (y > 0)
        g = 2;
      else
        g = 1;
      sum = y + (((x - 1) / 2) * pow(-1, g));
      arr[i] = sum;
      continue;
    } else if (x % 2 == 0) {
      if (z > 0)
        g = 2;
      else
        g = 1;
      sum = z + (((x / 2) - 1) * pow(-1, g));
      arr[i] = sum;
      continue;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}
