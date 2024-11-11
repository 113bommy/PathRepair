#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  int b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int min = INT_MAX;
  int r[n];
  for (int i = 0; i < n; i++) {
    r[i] = (int)(b[i] / a[i]);
    if (r[i] < min) min = r[i];
  }
  for (int i = 0; i < n; i++) b[i] = b[i] - min * a[i];
  int count = min;
  while (1) {
    int i;
    for (i = 0; i < n; i++) {
      if (b[i] >= a[i])
        b[i] = b[i] - a[i];
      else if (a[i] - b[i] <= k) {
        k = k - (a[i] - b[i]);
        b[i] = a[i];
      } else
        break;
    }
    if (i == n)
      count++;
    else
      break;
  }
  cout << count;
  return 0;
}
