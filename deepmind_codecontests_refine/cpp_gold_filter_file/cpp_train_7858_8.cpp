#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l = 1, lm = 1;
  scanf("%d", &n);
  int a[n];
  scanf("%d", &a[0]);
  for (int i = 1; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] >= a[i - 1])
      l++;
    else
      l = 1;
    if (l > lm) lm = l;
  }
  printf("%d\n", lm);
  return 0;
}
