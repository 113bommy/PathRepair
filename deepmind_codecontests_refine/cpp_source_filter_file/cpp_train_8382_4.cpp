#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int v[n], v_inv[n], fp[n], a[m], b[m + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    v[i] -= 1;
    v_inv[v[i]] = i;
    fp[i] = -1;
  }
  b[m] = n;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a[i], &b[i]);
    a[i] = v_inv[a[i] - 1];
    b[i] = v_inv[b[i] - 1];
    if (a[i] > b[i]) {
      int t = a[i];
      a[i] = b[i];
      b[i] = t;
    }
    if (fp[a[i]] == -1 || b[fp[a[i]]] > b[i]) {
      fp[a[i]] = i;
    }
  }
  fp[n - 1] = m;
  long long int res = 0;
  int f = m;
  for (int i = n - 2; i >= 0; i--) {
    if (fp[i] == -1 || b[fp[i]] > b[fp[i + 1]]) {
      fp[i] = fp[i + 1];
    }
  }
  for (int i = 0; i < n; i++) {
    res += b[fp[i]] - i;
  }
  printf("%d\n", res);
}
