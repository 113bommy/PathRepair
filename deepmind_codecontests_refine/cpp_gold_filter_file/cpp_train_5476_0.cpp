#include <bits/stdc++.h>
using namespace std;
int a[105], v[105];
bool used[105];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%d", &v[1]);
  for (int i = 2; i <= m; i++) {
    scanf("%d", &v[i]);
    int dif = v[i] - v[i - 1];
    if (dif <= 0) dif += n;
    if (used[dif] && a[v[i - 1]] != dif) {
      printf("-1");
      return 0;
    }
    used[dif] = true;
    a[v[i - 1]] = dif;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      for (int j = 1; j <= n; j++) {
        if (!used[j]) {
          a[i] = j;
          used[j] = true;
          break;
        }
      }
      if (a[i] == 0) {
        printf("-1");
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
