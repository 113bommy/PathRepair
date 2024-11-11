#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, val;
  int nP = 0, nI = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    if (val % 2)
      nI++;
    else
      nP++;
  }
  if (nI % 2)
    printf("1\n");
  else
    printf("%d\n", nP);
  return 0;
}
