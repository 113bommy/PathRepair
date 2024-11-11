#include <bits/stdc++.h>
using namespace std;
int a[309][309];
int x[309], y[309];
int du[309];
int tot;
int ans1[309], ans2[309];
void dfs(int cur) {
  for (int i = 0; i <= 6; i++) {
    if (a[cur][i] > 0) {
      a[cur][i]--;
      a[i][cur]--;
      dfs(i);
      ans1[tot] = cur;
      ans2[tot] = i;
      tot++;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int s;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    a[x[i]][y[i]]++;
    a[y[i]][x[i]]++;
    du[x[i]]++;
    du[y[i]]++;
    s = x[i];
  }
  int num = 0;
  for (int i = 0; i <= 6; i++)
    if (du[i] % 2) {
      num++;
      s = i;
    }
  if (num != 0 && num != 2) {
    printf("No Solution");
    return 0;
  }
  dfs(s);
  if (tot != n) {
    printf("No solution");
    return 0;
  }
  for (int i = tot - 1; i >= 0; i--)
    for (int j = 1; j <= n; j++) {
      if (ans1[i] == x[j] && ans2[i] == y[j]) {
        printf("%d -\n", j);
        x[j] = -1;
        break;
      } else if (ans1[i] == y[j] && ans2[i] == x[j]) {
        printf("%d +\n", j);
        x[j] = -1;
        break;
      }
    }
}
