#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, f = 0, a;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a == 1) f = 1;
  }
  if (f)
    printf("%d", -1);
  else
    printf("%d", 1);
  return 0;
}
