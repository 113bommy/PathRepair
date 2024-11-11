#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, l;
  cin >> n >> d >> l;
  int d_max = (n - n / 2) * l - (n / 2);
  int d_min = (n - n / 2) - (n / 2) * l;
  if (d < d_min || d > d_max) {
    cout << "-1";
    return 0;
  } else {
    int ar[n + 1];
    if (n % 2 == 1) {
      for (int i = n; i >= 1; i--) {
        if ((n - i) % 2 == 0)
          ar[i] = l;
        else
          ar[i] = 1;
      }
      int tot_diff = d_max - d;
      int it = n;
      while (tot_diff) {
        int z = min(l - 1, tot_diff);
        if ((n - it) % 2 == 0) {
          ar[it] -= z;
          tot_diff -= z;
        } else {
          ar[it] += z;
          tot_diff -= z;
        }
        it--;
      }
    } else {
      for (int i = n; i >= 1; i--) {
        if ((n - i) % 2 == 1)
          ar[i] = l;
        else
          ar[i] = 1;
      }
      int tot_diff = d_max - d;
      int it = n;
      while (tot_diff) {
        int z = min(l - 1, tot_diff);
        if ((n - it) % 2 == 1) {
          ar[it] -= z;
          tot_diff -= z;
        } else {
          ar[it] += z;
          tot_diff -= z;
        }
        it--;
      }
    }
    for (int i = n; i >= 1; i--) cout << ar[i] << " ";
  }
  return 0;
}
