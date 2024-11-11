#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, i, tam;
  cin >> n >> k >> m;
  int a[100000 + 5];
  for (i = 1; i <= n; i++) cin >> a[i];
  int dau[10000 + 5];
  tam = -1;
  memset(dau, 0, sizeof(dau));
  for (i = 1; i <= n; i++) {
    dau[a[i] % m]++;
    if (dau[a[i] % m] == k) {
      cout << "Yes" << endl;
      tam = a[i] % m;
      for (int j = 1; j <= n; j++) {
        if (k == 0) {
          break;
        }
        if ((a[j] % m == tam) and (k != 0)) {
          cout << a[j] << " ";
          k--;
        }
      }
    }
  }
  if (tam == -1) cout << "No";
  return 0;
}
