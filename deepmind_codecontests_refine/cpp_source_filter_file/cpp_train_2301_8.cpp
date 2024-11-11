#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  constexpr int n_types = 100;
  int a[n_types + 1] = {0};
  int value;
  for (int i = 0; i < n; i++) {
    scanf("%d", &value);
    a[value]++;
  }
  int n_dishes = 0;
  for (int i = 1; i <= n_types; i++)
    n_dishes = max(n_dishes, int(ceil(a[i] / float(k))));
  int n_p = n_dishes * k;
  int res = 0;
  for (int i = 1; i < n_types; i++) res += (a[i] != 0) ? n_p - a[i] : 0;
  printf("%d", res);
  return 0;
}
