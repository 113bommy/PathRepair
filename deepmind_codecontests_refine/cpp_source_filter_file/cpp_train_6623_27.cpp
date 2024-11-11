#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  scanf("%d%d%d", &n, &k, &x);
  int a[10000];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int sum = x * k;
  for (int i = 0; i < n - x; i++) {
    sum += a[i];
  }
  printf("%d\n", sum);
}
