#include <bits/stdc++.h>
using namespace std;
char c[100010];
int n, q, l, r, k, a[100010], t, b[100010];
int main() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (int i = 1; i <= n; i++) a[i] = c[i] - 'a';
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &l, &r, &k);
    for (int i = 0; i < r - l; i++) b[(i + k) % (r - l + 1) + l] = a[i + l];
    for (int i = l; i <= r; i++) a[i] = b[i];
  }
  for (int i = 1; i <= n; i++) printf("%c", a[i] + 'a');
  return 0;
}
