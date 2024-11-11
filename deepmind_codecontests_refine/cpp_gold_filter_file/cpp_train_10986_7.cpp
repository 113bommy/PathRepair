#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], i, countmax = 1, j, k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    int count = 1;
    for (j = i - 1; j >= 0; j--) {
      if (a[i] >= a[j]) {
        count++;
        if (j - 1 < 0) break;
        if (a[j - 1] > a[j]) break;
      }
    }
    for (j = i + 1; j < n; j++) {
      if (a[i] >= a[j]) {
        count++;
        if (j + 1 >= n) break;
        if (a[j + 1] > a[j]) break;
      }
    }
    if (count > countmax) countmax = count;
  }
  cout << countmax;
  return 0;
}
