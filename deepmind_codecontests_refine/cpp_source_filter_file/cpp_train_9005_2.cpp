#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int l[10000000];
int r[10000000];
int x[10000000];
int z[10000000];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &l[i], &r[i], &x[i]);
    l[i]--;
    r[i]--;
  }
  z[0] = -1;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] != a[i])
      z[i] = i - 1;
    else
      z[i] = z[i - 1];
  }
  for (int i = 0; i < m; i++) {
    if (a[r[i]] != x[i])
      printf("%d\n", r[i] + 1);
    else if (z[r[i]] > l[i])
      printf("%d\n", z[r[i]] + 1);
    else
      printf("%d\n", -1);
  }
  return 0;
}
