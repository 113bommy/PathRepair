#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[100], l[1000], r[1000];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int m = 0;
  int maxi, mini;
  while (k--) {
    maxi = 0;
    mini = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[maxi]) maxi = i;
      if (a[i] < a[mini]) mini = i;
    }
    if (a[maxi] <= a[mini] + 1) break;
    a[maxi]--;
    a[mini]++;
    l[m] = maxi;
    r[m] = mini;
    m++;
  }
  maxi = 0;
  mini = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[maxi]) maxi = i;
    if (a[i] < a[mini]) mini = i;
  }
  printf("%d %d\n", m, a[maxi] - a[mini]);
  for (int i = 0; i < m; i++) printf("%d %d\n", l[i] + 1, r[i] + 1);
  return 0;
}
