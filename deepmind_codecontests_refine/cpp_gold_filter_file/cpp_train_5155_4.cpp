#include <bits/stdc++.h>
using namespace std;
int n;
long long m, dem, max1, doi, vtm, min1, dau, max2;
int a[200005];
long long chuan;
void sol() {
  int i, j, z, t1;
  max1 = 0;
  if (max2 == min1) {
    chuan = min1 * n;
    cout << chuan << endl;
    return;
  }
  z = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] == min1) z++;
  }
  if (z < 2) {
    chuan = min1 * n;
    cout << chuan + n - 1 << endl;
    return;
  }
  i = vtm;
  while (1) {
    if (a[i] != min1) {
      dau = i;
      break;
    }
    i++;
    if (i == n + 1) i = 1;
  }
  i = dau;
  z = 0;
  while (1) {
    if (a[i] == min1) {
      if (z > max1) max1 = z;
      z = -1;
    }
    i++;
    z++;
    if (i == vtm) {
      if (z > max1) max1 = z;
      break;
    }
    if (i == n + 1) i = 1;
  }
  chuan = (long long)n * min1 + max1;
  cout << chuan << endl;
}
int main() {
  int i, j;
  while (scanf("%d", &n) > 0) {
    min1 = 2147483647;
    max2 = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] <= min1) {
        min1 = a[i];
        vtm = i;
      }
      if (a[i] > max2) max2 = a[i];
    }
    sol();
  }
  return 0;
}
