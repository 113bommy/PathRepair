#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100], left, right;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    if (a[0] == 1)
      cout << 1;
    else
      cout << 0;
  } else {
    left = right = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == 1) {
        left = i;
        break;
      }
    for (int i = n - 1; i >= 0; i--)
      if (a[i] == 1) {
        right = i;
        break;
      }
    if (left == 0 && right == 0 && a[0] == 0) {
      cout << 0;
    } else {
      int dem = 0;
      for (int i = left; i <= right; i++) {
        if (a[i] == 0 && a[i + 1] == 0) {
          int j = i;
          while (a[j] != 1) {
            dem++;
            j++;
          }
          i = i + j - 1;
        }
      }
      dem = dem + left + (n - 1 - right);
      cout << n - dem;
    }
  }
}
