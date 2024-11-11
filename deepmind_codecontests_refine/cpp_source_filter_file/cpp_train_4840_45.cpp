#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N], n, i, j, x, fl;
vector<int> ans;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    fl = 0;
    for (j = 1; j <= n; j++) {
      scanf("%d", &x);
      if ((x == 1) || (x == 3)) {
        fl = 1;
      }
    }
    if (!fl) {
      ans.push_back(x);
    }
  }
  printf("%d\n", (int(ans.size())));
  for (i = 0; i < (int(ans.size())); i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
