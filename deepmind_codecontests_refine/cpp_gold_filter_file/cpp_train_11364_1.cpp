#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int k = min(a[1], a[n]) / (n - 1);
  for (int i = 2; i < n; i++) {
    k = min(min(a[i], a[1]) / (i - 1), k);
    k = min(min(a[i], a[n]) / (n - i), k);
  }
  printf("%d\n", k);
  return 0;
}
