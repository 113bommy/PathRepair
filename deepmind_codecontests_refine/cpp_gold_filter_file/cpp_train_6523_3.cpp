#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  long long ara[200005];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &ara[i]);
  ara[n] = 1000000001;
  sort(ara, ara + n);
  if (k == 0) {
    if (ara[0] == 1)
      printf("-1\n");
    else
      printf("1\n");
    return 0;
  }
  k--;
  if (ara[k] != ara[k + 1])
    printf("%lld\n", ara[k]);
  else
    printf("-1\n");
  return 0;
}
