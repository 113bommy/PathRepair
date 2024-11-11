#include <bits/stdc++.h>
using namespace std;
int n, b[5005];
char a[5005][5005];
int main() {
  if (0) {
    freopen("a.inp", "r", stdin);
  };
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) scanf("%s", &a[i]);
  for (int i = 1; i < n; i++) {
    int j = 0;
    while (j < i && a[i][b[j]] == '1') j++;
    for (int x = i - 1; x > j; x--) {
      if (a[i][b[x]] == '1') {
        printf("%d %d %d\n", i + 1, b[x] + 1, b[j] + 1);
        return 0;
      } else
        b[x + 1] = b[x];
    }
    b[j + 1] = b[j];
    b[j] = i;
  }
  printf("-1\n");
}
