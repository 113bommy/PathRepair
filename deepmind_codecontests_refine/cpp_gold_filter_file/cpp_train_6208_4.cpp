#include <bits/stdc++.h>
using namespace std;
int a[7], vis[7], s, flag;
void dfs(int p, int cnt, int sum) {
  if (cnt == 3) {
    if (sum == s) {
      flag = true;
    }
    return;
  }
  for (int i = p + 1; i <= 6; i++) {
    if (flag) return;
    if (!vis[i] && sum + a[i] <= s) {
      vis[i] = 1;
      dfs(i, cnt + 1, sum + a[i]);
      vis[i] = 0;
    }
  }
}
int main() {
  for (int i = 1; i <= 6; i++) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  if (s % 2) {
    printf("NO\n");
    return 0;
  }
  s /= 2;
  dfs(0, 0, 0);
  if (flag) {
    printf("YES\n");
  } else
    printf("NO\n");
  return 0;
}
