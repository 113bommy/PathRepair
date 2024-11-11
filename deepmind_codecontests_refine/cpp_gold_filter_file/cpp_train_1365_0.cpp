#include <bits/stdc++.h>
using namespace std;
int a[200007];
int b[200007];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  sort(b, b + n);
  int maxnum = a[d - 1] + b[n - 1];
  int pai = d;
  int dex = 0;
  for (int i = 0; i < d - 1; i++) {
    if (a[i] + b[dex] <= maxnum) {
      dex++;
      pai--;
    }
  }
  printf("%d\n", pai);
  return 0;
}
