#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, f = 0;
  scanf("%d", &n);
  int p[n], b[n], st[n], c = 0;
  for (i = 0; i < n; ++i) scanf("%d", &p[i]);
  for (i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    st[i] = 0;
    if (b[i] == 1) c++;
  }
  if (c % 2 == 1) f = 1;
  c = 0;
  for (i = 0; i < n; ++i) {
    if (st[i] == 0) {
      j = i;
      c++;
      st[j] = 1;
      while (p[j] != i + 1) {
        st[j] = 1;
        j = p[j] - 1;
        if (p[j] == i + 1) st[j] = 1;
      }
    }
  }
  if (c == 1) c = 0;
  if (f == 1)
    printf("%d\n", c);
  else
    printf("%d\n", c + 1);
  return 0;
}
