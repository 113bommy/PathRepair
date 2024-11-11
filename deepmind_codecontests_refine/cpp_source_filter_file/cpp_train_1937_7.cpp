#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  if (a[0] == a[2]) {
    int ccount = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[0]) ccount++;
    }
    printf("%I64d", (long long)ccount * (ccount - 1) * (ccount - 2) / 6);
    return 0;
  }
  if (a[0] == a[1]) {
    int ccount = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == a[2]) ccount++;
    printf("%d", ccount);
    return 0;
  }
  if (a[0] < a[1]) {
    int ccount1 = 0, ccount2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[1]) ccount1++;
      if (a[i] == a[3]) ccount2++;
    }
    if (a[1] == a[2])
      printf("%I64d", (long long)ccount1 * (ccount1 - 1) / 2);
    else
      printf("%d", ccount2);
    return 0;
  }
  return 0;
}
