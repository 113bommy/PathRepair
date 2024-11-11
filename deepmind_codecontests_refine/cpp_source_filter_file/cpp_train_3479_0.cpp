#include <bits/stdc++.h>
using namespace std;
int q[100008], w[100004], a[1000002], k, mx, i, n;
int main() {
  cin >> n;
  for (k = 1; k <= n; k++) {
    cin >> a[k];
    if (mx < a[k]) mx = a[k];
    q[a[k]]++;
  }
  for (k = 1; k <= mx; k++) {
    if (q[k] != 0) {
      i++;
      w[i] = k;
      q[k]--;
    }
  }
  for (k = mx; k >= 1; k--)
    if (q[k] != 0) {
      i++;
      w[i] = k;
      q[k]--;
    }
  cout << i << " ";
  for (k = 1; k <= i; k++) cout << w[k] << " ";
}
