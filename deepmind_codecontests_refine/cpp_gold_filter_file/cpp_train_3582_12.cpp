#include <bits/stdc++.h>
using namespace std;
int n, a[222], d[111], c1, c2;
bool u1[111], u2[111];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%d", &a[i]);
    d[a[i]]++;
  }
  for (int i = 10; i <= 99; i++)
    if (d[i] > 1) c1++, c2++, u1[i] = u2[i] = true;
  for (int i = 10; i <= 99; i++)
    if (d[i] == 1) {
      if (c1 < c2)
        c1++, u1[i] = true;
      else
        c2++, u2[i] = true;
    }
  printf("%d\n", c1 * c2);
  for (int i = 1; i <= 2 * n; i++) {
    if (u1[a[i]])
      printf("1 "), u1[a[i]] = false;
    else if (u2[a[i]])
      printf("2 "), u2[a[i]] = false;
    else {
      if (c1 < n)
        printf("1 "), c1++;
      else
        printf("2 ");
    }
  }
  return 0;
}
