#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int k;
int n;
int a[maxn];
int main() {
  scanf("%d", &k);
  a[0] = -1;
  a[1] = 2;
  n = 2000;
  for (int i = 2; i < 2000; i++) {
    a[i] = 1;
    a[i] += min(999999, k);
    k -= min(99999, k);
  }
  printf("%d\n", n);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}
