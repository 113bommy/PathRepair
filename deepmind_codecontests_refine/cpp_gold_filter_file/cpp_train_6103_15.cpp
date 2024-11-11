#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, num[N][N], x, sum = 0;
int a[N], b[N], vis[N], res[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    printf("? %d %d\n", 0, i);
    fflush(stdout);
    scanf("%d", &x);
    num[0][i] = x;
  }
  for (int i = 1; i < n; i++) {
    printf("? %d %d\n", i, 0);
    fflush(stdout);
    scanf("%d", &x);
    num[i][0] = x;
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) num[i][j] = num[i][0] ^ num[0][j] ^ num[0][0];
  bool first = true;
  for (int i = 0; i < n; i++) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    a[0] = i;
    bool flag = true;
    for (int j = 0; j < n; j++) b[j] = num[0][j] ^ a[0];
    for (int j = 1; j < n; j++) a[j] = num[j][0] ^ b[0];
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < n; j++) {
      if (!vis[a[j]] && a[j] < n)
        vis[a[j]] = 1;
      else
        flag = false;
      if (b[j] < n && b[a[j]] != j) flag = false;
    }
    if (flag) {
      sum++;
      if (first)
        for (int j = 0; j < n; j++) res[j] = a[j];
      first = false;
    }
  }
  printf("!\n");
  printf("%d\n", sum);
  for (int j = 0; j < n; j++) printf("%d ", res[j]);
  fflush(stdout);
  return 0;
}
