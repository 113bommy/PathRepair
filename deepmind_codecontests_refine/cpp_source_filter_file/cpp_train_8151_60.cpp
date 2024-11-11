#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int x, i, j;
  x = p / n * np;
  int arr[x + 1];
  int amit = 0;
  if (x > 0) {
    for (i = 0; i <= x; i++) {
      arr[i] = 0;
    }
    for (i = 0; i <= x; i++) {
      if (n * (i * nl) <= k * l && n * i <= d * c) {
        arr[amit++] = i;
      }
    }
    sort(arr, arr + amit);
    cout << arr[amit - 1];
  } else {
    cout << "0";
  }
}
