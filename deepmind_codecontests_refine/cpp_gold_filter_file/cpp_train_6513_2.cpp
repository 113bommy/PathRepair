#include <bits/stdc++.h>
using namespace std;
const int N = 200008;
char str[N];
int n, sn, sm, m, a[N], b[N];
int main(void) {
  int i, j;
  scanf("%d%d%d%d%s", &n, &sn, &sm, &m, str + 1);
  sn--;
  b[++b[0]] = 0;
  for (i = 1; i <= n; i++)
    if (str[i] == '1') b[++b[0]] = i;
  b[++b[0]] = n + 1;
  for (i = 1; i < b[0]; i++)
    if (b[i + 1] - b[i] >= sm) {
      for (j = b[i] + sm; j < b[i + 1]; j += sm)
        if (sn)
          sn--;
        else
          a[++a[0]] = j;
    }
  printf("%d\n", a[0]);
  if (a[0]) printf("%d", a[1]);
  for (i = 2; i <= a[0]; i++) printf(" %d", a[i]);
  return 0;
}
