#include <bits/stdc++.h>
using namespace std;
int go(long long int k, long long int a) {
  int i;
  for (i = 0; (1LL << (2 * i)) < a; i++)
    ;
  return k + i;
}
int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  for (int i = 0, k, a; i < n; i++) {
    scanf("%d%d", &k, &a);
    mx = max(mx, go(k, a));
  }
  printf("%d\n", mx);
  return 0;
}
