#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int z[maxn], j[maxn];
int ztot = -2e6, jtot = 2e6;
int a[maxn];
int res[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] <= ztot && a[i] >= jtot) {
      cout << "NO" << endl;
      exit(0);
    }
    if (a[i] <= ztot)
      jtot = a[i], res[i] = 1;
    else if (a[i] >= jtot)
      ztot = a[i];
    else if (i == n - 1 || a[i] <= a[i - 1]) {
      ztot = a[i];
    } else {
      jtot = a[i];
      res[i] = 1;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
