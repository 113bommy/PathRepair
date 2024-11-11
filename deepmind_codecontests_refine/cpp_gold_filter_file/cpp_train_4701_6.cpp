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
char a[300004];
void d() {
  printf(":(\n");
  exit(0);
}
int main() {
  int n = gi();
  if (n % 2) d();
  scanf("%s", a);
  int o = 0, c = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == '(')
      o++;
    else if (a[i] == ')')
      c++;
  if (o > n / 2 || c > n / 2) d();
  o = n / 2 - o;
  int cn = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '?') {
      if (o) {
        o--;
        a[i] = '(';
      } else
        a[i] = ')';
    }
    if (a[i] == '(')
      cn++;
    else
      cn--;
    if (i < n - 1 && cn <= 0) d();
  }
  printf("%s\n", a);
  return 0;
}
