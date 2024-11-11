#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 5];
int t[1000000 + 5];
int cnt = 0;
void merge_sort(int a[], int x, int y, int t[]) {
  if (y - x > 1) {
    int m = x + (y - x) / 2;
    int p = x, q = m, i = x;
    merge_sort(a, x, m, t);
    merge_sort(a, m, y, t);
    while (p < m || q < y) {
      if (q >= y || (p < m && a[p] <= a[q]))
        t[i++] = a[p++];
      else {
        t[i++] = a[q++];
        cnt += m - p;
      }
    }
    for (int i = x; i < y; i++) a[i] = t[i];
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  merge_sort(a, 0, n, t);
  if (n % 2 == 1) {
    if (cnt % 2 == 1)
      cout << "Petr" << endl;
    else
      cout << "Um_nik" << endl;
  } else {
    if (cnt % 2 == 1)
      cout << "Um_nik" << endl;
    else
      cout << "Petr" << endl;
  }
  return 0;
}
