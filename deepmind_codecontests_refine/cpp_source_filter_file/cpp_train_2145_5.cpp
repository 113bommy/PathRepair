#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, k = 0, max = 0, min = 0;
  cin >> n;
  cin >> k;
  int *a = new int[n];
  int *b = new int[k];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < k; i++) {
    if (i == 0) min = b[i];
    if (b[i] < min) min = b[i];
  }
  for (int i = 0; i < k; i++) {
    if (i == 0) max = b[i];
    if (b[i] > max) max = b[i];
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    s = s + a[i];
  }
  int f = 0, kk = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] == 0) {
      for (int j = i; j < n - 1; j++) {
        if (a[j] != 0) {
          kk = j;
          break;
        }
      }
    } else
      kk = i + 1;
    if (a[i] > a[kk] && a[kk] != 0) f = 3;
  }
  if (f == 3) {
    cout << "Yes";
    return 0;
  }
  if (s == 0) {
    cout << "Yes";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (i + 1 < n && a[i + 1] < max) {
        cout << "Yes";
        f = 1;
        break;
      }
      if (i - 1 > 0 && a[i - 1] > min) {
        cout << "Yes";
        f = 1;
        break;
      }
    }
  }
  if (f == 0) cout << "No";
  return 0;
}
