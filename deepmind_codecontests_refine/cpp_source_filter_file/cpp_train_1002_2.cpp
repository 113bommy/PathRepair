#include <bits/stdc++.h>
using namespace std;
int m, n;
char a[302][302];
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) scanf("%s", &a[i]);
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      bool khac_nhau = false, khac_rong = false;
      for (int k = 0; k < n; k++) {
        if (a[i][k] != a[j][k]) khac_nhau = true;
        if (a[i][k] == '#' && a[j][k] == '#') khac_rong = true;
      }
      if (khac_nhau & khac_rong) {
        printf("No\n");
        return 0;
      }
    }
  printf("Yes\n");
  return 0;
}
