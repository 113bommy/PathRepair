#include <bits/stdc++.h>
using namespace std;
int ara[100005];
int main() {
  int n, m, i, j, p, q, men;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &ara[i]);
  sort(ara, ara + n);
  men = 1;
  for (i = 1; i < n; i++) {
    if (ara[i] > men) men++;
  }
  printf("%d\n", men + 1);
  return 0;
}
