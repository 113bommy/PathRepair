#include <bits/stdc++.h>
using namespace std;
int atk[110];
int def[110];
int a[110];
bool vis[110];
int main() {
  int x, n, m, num1 = 0, num2 = 0;
  char zs[10];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", zs);
    scanf("%d", &x);
    if (zs[0] == 'A')
      atk[num1++] = x;
    else if (zs[0] == 'D')
      def[num2++] = x;
  }
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  sort(atk, atk + num1);
  sort(def, def + num2);
  sort(a, a + m);
  memset(vis, false, sizeof(vis));
  int ans = 0;
  int sign = 0;
  for (int i = 0; i < num2; i++) {
    int j;
    for (j = 0; j < m; j++) {
      if (!vis[j] && a[j] > def[i]) {
        vis[j] = true;
        break;
      }
    }
    if (j == m) {
      sign++;
      break;
    }
  }
  if (sign == 0) {
    int sum = 0;
    int flag = 0;
    for (int i = num1 - 1; i >= 0; i--) {
      int j;
      for (j = 0; j < m; j++) {
        if (!vis[j] && a[j] >= atk[i]) {
          vis[j] = true;
          sum = sum + a[j] - atk[i];
          break;
        }
      }
      if (j == m) {
        flag++;
        break;
      }
    }
    if (flag == 0) {
      for (int i = 0; i < m; i++) {
        if (!vis[i]) sum = sum + a[i];
      }
      ans = max(ans, sum);
    }
  }
  memset(vis, 0, sizeof(vis));
  int sum = 0;
  for (int i = 0; i < num1; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (!vis[j] && a[j] >= atk[i]) {
        vis[j] = true;
        sum = sum + a[j] - atk[i];
        break;
      }
    }
  }
  ans = max(ans, sum);
  printf("%d\n", ans);
  return 0;
}
