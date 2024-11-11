#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, ara[76554], test;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &k, &ara[i]);
  }
  scanf("%d", &test);
  int cnt = n;
  for (i = 0; i < cnt; i++) {
    if (ara[i] < test) n--;
  }
  printf("%d\n", n);
  return 0;
}
