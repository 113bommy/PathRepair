#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int c[100000];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  i = 0, j = n - 1;
  while (i <= j) {
    b[i] = b[j] = i + 1;
    i++;
    j--;
  }
  for (i = 0; i < n; i++) {
    if (a[i] >= b[i]) c[a[i] - b[i]]++;
  }
  int kq = 0;
  for (i = 0; i < 100000; i++) kq = max(kq, c[i]);
  cout << n - kq;
  return 0;
}
