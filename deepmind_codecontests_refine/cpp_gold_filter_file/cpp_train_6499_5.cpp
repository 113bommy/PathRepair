#include <bits/stdc++.h>
using namespace std;
stringstream ss;
long long mod = 1000000007LL;
char ans[1 << 20];
int a[1024][1024], row[1024];
int main() {
  int n, m, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  memset(row, 0, sizeof row);
  int k = 0, all = 0, t;
  for (int i = 0; i < n; i++)
    if (a[i][i]) row[i] = 1, all++;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &t);
    if (t < 3) {
      scanf("%d", &x);
      row[x] ^= 1;
      all += (row[x] ? 1 : -1);
    } else
      ans[k++] = ('0' + all % 2);
  }
  ans[k++] = 0;
  puts(ans);
  return 0;
}
