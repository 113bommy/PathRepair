#include <bits/stdc++.h>
using namespace std;
int a[100008];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  a[0] == 1;
  sort(a, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1])
      continue;
    else
      a[i] = a[i - 1] + 1;
  }
  printf("%d", a[n] + 1);
  return 0;
}
