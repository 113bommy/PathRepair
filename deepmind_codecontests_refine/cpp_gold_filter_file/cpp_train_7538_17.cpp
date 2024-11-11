#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int n, m;
bool a[N][N];
bool used[N];
int label[N];
bool kuhn(int v, int bad) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (int i = 0; i < n; i++) {
    if (i == bad || !a[v][i]) {
      continue;
    }
    if (label[i] == -1 || kuhn(label[i], bad)) {
      label[i] = v;
      return true;
    }
  }
  return false;
}
int solve(int v) {
  for (int i = 0; i < n; i++) {
    label[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    memset(used, false, sizeof(used));
    if (i != v) {
      kuhn(i, v);
    }
  }
  int res = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == v || j == v) {
        continue;
      }
      if (label[j] == i) {
        res--;
        continue;
      }
      if (a[i][j]) {
        res++;
      }
    }
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u - 1][v - 1] = true;
  }
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int curr = 0;
    for (int v = 0; v < n; v++) {
      if (!a[v][i]) {
        curr++;
      }
      if (i != v && !a[i][v]) {
        curr++;
      }
    }
    ans = min(ans, curr + solve(i));
  }
  printf("%d", ans);
  return 0;
}
