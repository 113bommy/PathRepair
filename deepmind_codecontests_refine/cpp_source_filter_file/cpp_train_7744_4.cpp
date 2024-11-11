#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[4005][4005];
int s[4005][4005];
int d[4005][805];
int get(int i, int j) {
  return s[i][i] - s[i][j - 1] - s[j - 1][i] + s[j - 1][j - 1];
}
void compute(int j, int l, int r, int l1, int r1) {
  if (l > r) return;
  int m = (l + r) / 2;
  d[m][j] = 1e9 + 7;
  int id = 0;
  for (int i = max(j, l1); i <= min(m, r1); i++) {
    if (d[m][j] > d[i - 1][j - 1] + get(m, i)) {
      d[m][j] = d[i - 1][j - 1] + get(m, i);
      id = i;
    }
  }
  if (l == r) return;
  compute(j, l, m - 1, l1, id);
  compute(j, m + 1, r, id, r1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = getchar() - '0';
      getchar();
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    d[i][1] = get(i, 1);
  }
  for (int i = 2; i <= k; i++) {
    compute(i, 1, n, 1, n);
  }
  printf("%d", d[n][k] / 2);
  return 0;
}
