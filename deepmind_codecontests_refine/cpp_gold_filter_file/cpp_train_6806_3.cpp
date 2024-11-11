#include <bits/stdc++.h>
using namespace std;
const int maxn = 111111;
int bit[maxn][40];
int num[maxn];
int l[maxn], r[maxn], p[maxn], tot;
int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    if (num[i] > mx) mx = num[i];
  }
  tot = 30;
  while (!((1 << tot) & mx)) tot--;
  for (int i = 1; i <= n; i++)
    for (int j = tot; j >= 0; j--)
      if ((1 << j) & num[i]) bit[i][j] = 1;
  int tt = 0;
  while (1) {
    int flag = 0;
    for (int i = 1; i < n; i++)
      if (bit[i][tot] != bit[i + 1][tot]) {
        flag = 1;
        break;
      }
    if (flag) break;
    tot--;
  }
  for (int i = 1, j = 1; i <= n; i = j) {
    while (bit[i][tot] == 1 && i <= n) i++;
    if (i > n) break;
    l[++tt] = i;
    j = i;
    while (bit[j][tot] == 0 && j <= n) j++;
    r[tt] = j - 1;
  }
  int ans = 0;
  for (int i = 1; i <= tt; i++) {
    if (l[i] - 1 > 0) {
      int k = num[l[i] - 1];
      int f = l[i];
      int mm = num[l[i]];
      for (int j = l[i] + 1; j <= r[i]; j++) {
        if (num[j] < mm) continue;
        mm = num[j];
        if ((k ^ num[j]) > (k ^ num[f])) f = j;
      }
      if ((k ^ num[f]) > ans) ans = k ^ num[f];
    }
    if (r[i] + 1 <= n) {
      int k = num[r[i] + 1];
      int f = r[i];
      int mm = num[r[i]];
      for (int j = r[i] - 1; j >= l[i]; j--) {
        if (num[j] < mm) continue;
        mm = num[j];
        if ((k ^ num[j]) > (k ^ num[f])) f = j;
      }
      if ((k ^ num[f]) > ans) ans = k ^ num[f];
    }
  }
  printf("%d\n", ans);
}
