#include <bits/stdc++.h>
using namespace std;
int cond = 1;
int main() {
  int n, s = 0, a[201013];
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) scanf("%d", &a[i]), s += a[i];
  int ret = 0;
  for (int i = 0; i < (n); i++)
    if (a[i] * (n - 1) == (s - a[i])) ret++;
  printf("%d\n", ret);
  for (int i = 0; i < (n); i++)
    if (a[i] * (n - 1) == (s - a[i])) printf("%d ", i + 1);
  puts("");
  return 0;
}
