#include <bits/stdc++.h>
using namespace std;
int prefix_sum[100010];
int n, m;
int busca(int i) {
  int ini = i;
  int fim = n;
  int j = 0;
  while (ini <= fim) {
    int meio = (ini + fim) / 2;
    if (prefix_sum[meio] - prefix_sum[i - 1] <= m) {
      j = meio - (i - 1);
      ini = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return j;
}
int main() {
  memset(prefix_sum, 0, sizeof(prefix_sum));
  cin >> n >> m;
  int davez;
  for (int i = 1; i <= n; i++) {
    cin >> davez;
    if (i == 0)
      prefix_sum[i] = davez;
    else {
      prefix_sum[i] = davez + prefix_sum[i - 1];
    }
  }
  int ans = 0;
  int lul;
  for (int i = 1; i <= n; i++) {
    lul = busca(i);
    ans = max(ans, lul);
  }
  cout << ans << endl;
  return 0;
}
