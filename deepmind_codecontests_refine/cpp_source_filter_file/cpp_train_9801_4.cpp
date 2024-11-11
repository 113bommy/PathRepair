#include <bits/stdc++.h>
using namespace std;
void QS(int a[], int left, int right) {
  int chot = a[(left + right) / 2];
  int i = left, j = right;
  while (i <= j) {
    while (a[i] > chot) i++;
    while (a[j] < chot) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  if (left < j) QS(a, left, j);
  if (i < right) QS(a, i, right);
}
int main() {
  int n;
  cin >> n;
  int a[n];
  unsigned long long tong = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tong += a[i];
  }
  QS(a, 0, n - 1);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int h;
    cin >> h;
    tong -= a[h - 1];
    cout << tong;
    tong += a[h - 1];
  }
  return 0;
}
