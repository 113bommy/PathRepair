#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, x[N], y[N];
bitset<N> a[N], b[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    a[x[i]][y[i]] = 1;
  }
  for (int i = 1; i <= n; i++) b[i][i] = 1;
  for (int i = 1; i <= n; i++) {
    int k = i;
    for (int j = i; j <= n; j++)
      if (a[j][i]) {
        k = j;
        break;
      }
    swap(a[k], a[i]);
    swap(b[k], b[i]);
    for (int j = i + 1; j <= n; j++)
      if (a[j][i]) a[j] ^= a[i], b[j] ^= b[i];
  }
  for (int i = n; i; i--)
    for (int j = i - 1; j; j--)
      if (a[j][i]) a[j] ^= a[i], b[j] ^= b[i];
  for (int i = 1; i <= m; i++)
    if (b[y[i]][x[i]])
      puts("NO");
    else
      puts("YES");
}
