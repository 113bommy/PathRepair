#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  if (n % 2 == 1)
    printf("%d", a[n / 2]);
  else
    printf("%d", max(a[n / 2], a[(n - 1) / 2]));
  return 0;
}
