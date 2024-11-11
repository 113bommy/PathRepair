#include <bits/stdc++.h>
using namespace std;
int f[20010][11];
int rcv[20];
int snt[20010];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &f[i][j]);
    }
  }
  fill(rcv, rcv + k, 0);
  fill(snt, snt + n, 0);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    rcv[y - 1]++;
    snt[x - 1]++;
  }
  for (int i = 0; i < n; i++) {
    int val = 0;
    for (int j = 0; j < m; j++) {
      if (f[i][j]) val += rcv[j];
    }
    val -= snt[i];
    printf("%d", val);
    if (i != n - 1) putchar(' ');
  }
  puts("");
}
