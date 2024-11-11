#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[402], brr[402], a[100], b[100];
  memset(arr, 0, sizeof(arr));
  memset(brr, 0, sizeof(brr));
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    arr[a[i]]++;
  }
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    brr[b[i]]++;
  }
  int mx = max(n, m);
  int mn = min(n, m);
  bool flag = false;
  if (mx == m) {
    for (int i = 0; i < mn; ++i) {
      for (int j = 0; j < mx; ++j) {
        if (!arr[a[i] + b[j]] && !brr[a[i] + b[j]]) {
          cout << a[i] << ' ' << b[j] << '\n';
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
  } else {
    for (int i = 0; i < mn; ++i) {
      for (int j = 0; j < mx; ++j) {
        if (!arr[a[j] + b[i]] && !brr[a[j] + b[i]]) {
          cout << a[j] << ' ' << b[i] << '\n';
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
  }
  return 0;
}
