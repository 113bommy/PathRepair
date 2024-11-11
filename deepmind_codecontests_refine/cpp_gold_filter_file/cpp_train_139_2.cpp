#include <bits/stdc++.h>
using namespace std;
void qs(int arr[], int x, int y) {
  int i, j, p;
  i = x;
  j = y;
  while (i < j) {
    if (arr[i] < arr[j]) {
      i++;
    } else {
      p = arr[j];
      arr[j] = arr[i];
      j--;
      arr[i] = arr[j];
      arr[j] = p;
    }
  }
  if (x < j - 1) {
    qs(arr, x, j - 1);
  }
  if (j + 1 < y) {
    qs(arr, j + 1, y);
  }
}
int main() {
  int n, i, j, p, q, x, c;
  cin >> n;
  x = 0;
  int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  qs(a, 0, n - 1);
  qs(b, 0, n - 1);
  i = 0;
  j = 0;
  p = 0;
  q = 0;
  while (i < n and j < n) {
    if (a[i] < b[j]) {
      i++;
    } else if (a[i] > b[j]) {
      j++;
    } else {
      for (c = i; c < n; c++) {
        if (a[i] == a[c]) {
          p++;
        } else {
          break;
        }
      }
      i = c;
      for (c = j; c < n; c++) {
        if (b[j] == b[c]) {
          q++;
        } else {
          break;
        }
      }
      j = c;
      x += p * q;
      p = 0;
      q = 0;
    }
  }
  cout << x;
  return 0;
}
