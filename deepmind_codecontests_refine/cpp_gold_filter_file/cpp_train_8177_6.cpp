#include <bits/stdc++.h>
using namespace std;
bitset<4010> b[2010];
int n, m, x[500010], y[500010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) b[i][i + n] = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    b[x[i]][y[i]] = 1;
  }
  bool flag = 0;
  for (int i = 1; i <= n; i++) {
    int pos = -1;
    for (int j = i; j <= n; j++) {
      if (b[j][i]) {
        pos = j;
        swap(b[i], b[j]);
        break;
      }
    }
    if (pos == -1) {
      flag = 1;
      break;
    }
    for (int j = 1; j <= n; j++) {
      if (b[j][i] && j != i) b[j] ^= b[i];
    }
  }
  for (int i = 1; i <= m; i++) {
    if (flag || b[y[i]][x[i] + n])
      puts("NO");
    else
      puts("YES");
  }
}
