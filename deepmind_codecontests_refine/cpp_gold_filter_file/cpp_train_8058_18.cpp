#include <bits/stdc++.h>
using namespace std;
map<int, int> mapa;
int main() {
  int i, j, k;
  int res[100005];
  int a[100005];
  int soma;
  int m, n, x;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  soma = 0;
  for (i = n - 1; i >= 0; i--) {
    if (!mapa[a[i]]) soma++;
    res[i] = soma;
    mapa[a[i]] = 1;
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &x);
    printf("%d\n", res[x - 1]);
  }
  return 0;
}
