#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
char ss[N];
int aa[N];
int ans[N];
int dfs(int x, int y, int l, int r) {
  if (x == y) {
    if (l == 0 && r == 0 && aa[x] % 2 == 0) {
      ans[x] = aa[x] / 2;
      return 1;
    }
    if (l == 0 && r == 1 && aa[x] % 2 == 1) {
      ans[x] = (aa[x] - 1) / 2;
      return 1;
    }
    if (l == 1 && r == 0 && aa[x] % 2 == 0) {
      ans[x] = (10 + aa[x]) / 2;
      return 1;
    }
    if (l == 1 && r == 1 && aa[x] % 2 == 1) {
      ans[x] = (10 + aa[x] - 1) / 2;
      return 1;
    }
    return 0;
  }
  if (l == 0 && r == 0) {
    if (aa[x] == aa[y]) {
      ans[x] = aa[x];
      ans[y] = 0;
      if (x + 1 == y) return 1;
      if (dfs(x + 1, y - 1, 0, 0)) return 1;
    }
    if (aa[x] == aa[y] + 1 && (x != 0 || aa[y] != 0)) {
      ans[x] = aa[y];
      ans[y] = 0;
      if (x + 1 == y) return 0;
      if (dfs(x + 1, y - 1, 1, 0)) return 1;
    }
  }
  if (l == 0 && r == 1) {
    if (aa[x] == 9 && aa[y] == 0) {
      ans[x] = 9;
      ans[y] = 0;
      if (x + 1 == y) return 0;
      if (dfs(x + 1, y - 1, 0, 1)) return 1;
    }
    if (aa[x] + 1 == aa[y]) {
      ans[x] = aa[x];
      ans[y] = 0;
      if (x + 1 == y) return 1;
      if (dfs(x + 1, y - 1, 0, 0)) return 1;
    }
    if (aa[x] == aa[y] && aa[y] > 0) {
      ans[x] = aa[y] - 1;
      ans[y] = 0;
      if (x + 1 == y) return 0;
      if (dfs(x + 1, y - 1, 1, 0)) return 1;
    }
  }
  if (l == 1 && r == 0) {
    if (aa[x] == aa[y] && aa[x] < 9) {
      ans[x] = 9;
      ans[y] = 10 + aa[x] - 9;
      if (x + 1 == y) return 0;
      if (dfs(x + 1, y - 1, 0, 1)) return 1;
    }
    if (aa[x] == aa[y] + 1) {
      ans[x] = 9;
      ans[y] = 10 + aa[y] - 9;
      if (x + 1 == y) return 1;
      if (dfs(x + 1, y - 1, 1, 1)) return 1;
    }
    if (aa[x] == 0 && aa[y] == 9) {
      ans[x] = 9;
      ans[y] = 0;
      if (x + 1 == y) return 0;
      if (dfs(x + 1, y - 1, 1, 0)) return 0;
    }
  }
  if (l == 1 && r == 1) {
    if (aa[x] == aa[y] && aa[y] > 0) {
      ans[x] = 9;
      ans[y] = 10 + aa[y] - 1 - 9;
      if (x + 1 == y) return 1;
      if (dfs(x + 1, y - 1, 1, 1)) return 1;
    }
    if (aa[x] == aa[y] && aa[y] == 0) {
      ans[x] = 9;
      ans[y] = 0;
      if (x + 1 == y) return 1;
      if (dfs(x + 1, y - 1, 1, 1)) return 1;
    }
    if (aa[x] + 1 == aa[y] && aa[x] < 9) {
      ans[x] = 9;
      ans[y] = 10 + aa[x] - 9;
      if (x + 1 == y) return 0;
      if (dfs(x + 1, y - 1, 0, 1)) return 1;
    }
  }
  return 0;
}
int main() {
  while (scanf("%s", ss) != EOF) {
    int n = strlen(ss);
    int m = 0;
    while (m < n - 1 && ss[m] == '0') m++;
    int nn = 0;
    for (int i = m; i < n; i++) {
      aa[nn++] = ss[i] - '0';
    }
    if (dfs(0, nn - 1, 0, 0)) {
      for (int i = 0; i < nn; i++) {
        printf("%d", ans[i]);
      }
      printf("\n");
    } else if (ss[0] == '1' && nn > 1 && dfs(1, nn - 1, 1, 0)) {
      for (int i = 1; i < nn; i++) {
        printf("%d", ans[i]);
      }
      printf("\n");
    } else
      printf("0\n");
  }
  return 0;
}
