#include <bits/stdc++.h>
using namespace std;
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gli() {
  long long a;
  scanf("%I64d", &a);
  return a;
}
char a[100004];
char b[100004];
int main() {
  int n = gi();
  scanf("%s", a);
  scanf("%s", b);
  int p = 0, q = n - 1;
  while (a[p] == b[p]) p++;
  while (a[q] == b[q]) q--;
  int res = 0;
  if (strncmp(&a[p], &b[p + 1], q - p) == 0) res++;
  if (strncmp(&a[p + 1], &b[p], q - p) == 0) res++;
  printf("%d\n", res);
  return 0;
}
