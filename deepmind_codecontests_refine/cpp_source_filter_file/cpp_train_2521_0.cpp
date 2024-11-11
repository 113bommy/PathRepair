#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int n, m, k;
long long res = 1;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n < m) swap(n, m);
  memset(a, 1, sizeof(a));
  for (int i = 0; i < n; i++) {
    a[i][0] = 1;
    a[i][i] = 1;
    for (int j = 1; j < i; j++) {
      a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % 1000000007;
    }
  }
  res = (long long)a[n - 1][2 * k] * a[m - 1][2 * k];
  printf("%d", (int)(res % 1000000007));
  return 0;
}
