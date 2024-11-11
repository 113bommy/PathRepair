#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
void mergeArr(int l[], int nl, int r[], int nr, int a[]) {
  int i = 0, j = 0, k = 0;
  while (i < nl && j < nr) {
    if (l[i] < r[j])
      a[k] = l[i++];
    else
      a[k] = r[j++];
    k++;
  }
  while (i < nl) a[k++] = l[i++];
  while (j < nr) a[k++] = r[j++];
}
void mergeSort(int a[], int n) {
  if (n == 1) return;
  int n1 = n / 2, n2 = n - n1, l[n1], r[n2];
  for (int i = 0; i < n1; i++) l[i] = a[i];
  for (int i = 0; i < n2; i++) r[i] = a[i + n1];
  mergeSort(l, n1);
  mergeSort(r, n2);
  mergeArr(l, n1, r, n2, a);
}
int main() {
  int n, a[MAX], b[MAX - 1], c[MAX - 2];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> b[i];
  for (int i = 0; i < n - 2; i++) cin >> c[i];
  mergeSort(a, n);
  mergeSort(b, n - 1);
  mergeSort(c, n - 2);
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cout << a[i] << '\n';
      break;
    }
  }
  for (int i = 0; i < n - 1; i++)
    if (b[i] != c[i]) {
      cout << b[i];
      break;
    }
  return 0;
}
