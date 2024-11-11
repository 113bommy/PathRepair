#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    int t = a[i];
    if (i != 0 && i != n - 1)
      while (t--) printf("PLR");
    if (i == 0)
      while (t--) printf("PRL");
    if (i == n - 1)
      while (t--) printf("PLR");
    if (i != n) printf("R");
  }
  return 0;
}
