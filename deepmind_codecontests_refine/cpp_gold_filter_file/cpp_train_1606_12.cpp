#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 200040;
map<int, int> v;
int a[MAXN], b[MAXN], r[MAXN];
int res[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d%d", a + i, b + i);
  for (int i = (1); i <= (n); ++i) r[i] = a[i];
  for (int i = (1); i <= (n); ++i) r[n + i] = b[i];
  sort(r + 1, r + 1 + 2 * n);
  for (int i = (1); i <= (2 * n); ++i) v[r[i]] = i;
  for (int i = (1); i <= (n); ++i) {
    a[i] = v[a[i]];
    if (a[i] <= n || i <= n / 2)
      putchar('1');
    else
      putchar('0');
  }
  printf("\n");
  for (int i = (1); i <= (n); ++i) {
    b[i] = v[b[i]];
    if (b[i] <= n || i <= n / 2)
      putchar('1');
    else
      putchar('0');
  }
  printf("\n");
  return 0;
}
