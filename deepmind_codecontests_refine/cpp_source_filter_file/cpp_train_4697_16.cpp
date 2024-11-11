#include <bits/stdc++.h>
using namespace std;
int main() {
  int ar[3], sm = 0, i, d;
  for (i = 0; i < 3; i++) scanf("%d", &ar[i]);
  i = 0;
  sort(ar, ar + 3);
  sm = ar[0] + ar[1];
  if (ar[2] >= sm) {
    d = ar[2] - sm;
    d++;
  }
  printf("%d\n", d);
  return 0;
}
