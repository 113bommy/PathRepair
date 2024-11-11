#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[14], count, b[14], max = 0, d = 0, r = 0;
  for (int i = 0; i < 14; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  for (int i = 0; i < 14; i++) {
    count = 0;
    if (a[i] == 0) continue;
    b[i] = 0;
    d = a[i] / 14;
    for (int l = 0; l < 14; l++) b[l] += d;
    r = a[i] % 14;
    for (int j = 1; j <= r; j++) {
      b[(i + j) % 14]++;
    }
    for (int p = 0; p < 14; p++) {
      if (b[p] % 2 == 0) count += b[p];
    }
    if (max < count) max = count;
    for (int l = 0; l < 14; l++) b[l] = a[l];
  }
  cout << max;
  return 0;
}
