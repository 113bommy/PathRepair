#include <bits/stdc++.h>
using namespace std;
int c[100009], a[100009], b[100009];
void Qsort(int l, int r) {
  int i = l, j = r, x = a[(l + r) / 2];
  while (i < j) {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      swap(b[i], b[j]);
      i++;
      j--;
    }
  }
  if (i < r) Qsort(i, r);
  if (j > l) Qsort(l, j);
}
int main() {
  int n, sum = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = i;
  }
  Qsort(0, n - 1);
  for (int i = 0; i < n - 1; i++) {
    if (b[i] < b[i + 1])
      sum++;
    else
      sum = 1;
    if (ans < sum) ans = sum;
  }
  cout << n - ans - 1;
}
