#include <bits/stdc++.h>
using namespace std;
int a[100000];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int l = 1, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if ((long long)k > (long long)m * (m + 1) / 2)
      l = m;
    else
      r = m;
  }
  printf("%d", a[k - l * (l + 1) / 2 - 1]);
  return 0;
}
