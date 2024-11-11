#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int a[maxn][5];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t[5];
    for (int j = 0; j < 5; j++) scanf("%d", &t[j]);
    if (i <= 15) {
      for (int j = 0; j < 5; j++) a[i][j] = t[j];
    }
  }
  if (n > 15)
    puts("0");
  else {
    vector<int> ansid;
    for (int i = 1; i <= n; i++) {
      bool ok = 1;
      for (int j = 1; j <= n; j++)
        if (j != i) {
          for (int k = 1; k <= n; k++)
            if (k != i && k != j) {
              int tmp = 0;
              for (int d = 0; d < 5; d++)
                tmp += (a[j][d] - a[i][d]) * (a[k][d] - a[i][d]);
              if (tmp > 0) ok = 0;
            }
        }
      if (ok) ansid.push_back(i);
    }
    printf("%d\n", ansid.size());
    for (auto x : ansid) printf("%d ", x);
  }
  return 0;
}
