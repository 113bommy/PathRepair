#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
int a[1100][5];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int tmp1[5];
  int tmp2[5];
  if (n >= 33) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    bool fl = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int k = j; k < n; k++) {
        if (k == j || k == i) continue;
        int flag = 0;
        for (int s = 0; s < 5; s++) {
          tmp1[s] = a[j][s] - a[i][s];
          tmp2[s] = a[k][s] - a[i][s];
          flag += tmp1[s] * tmp2[s];
        }
        if (flag > 0) {
          fl = 1;
          break;
        }
      }
    }
    if (fl == 0) ans.push_back(i + 1);
  }
  printf("%d\n", ans.size());
  for (auto nv : ans) printf("%d\n", nv);
}
