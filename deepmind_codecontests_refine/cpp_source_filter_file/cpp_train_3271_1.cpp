#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  if (k == 0) {
    printf("%d\n", m * (m - 1) / 2);
    for (int i = 1; i <= m; i++)
      for (int j = i + 1; j <= m; j++) printf("%d %d\n", i, j);
  } else {
    printf("%d", m * (m - 1) / 2);
    for (int i = 1; i <= m; i++)
      for (int j = i + 1; j <= m; j++) printf("%d %d\n", j, i);
  }
  return 0;
}
