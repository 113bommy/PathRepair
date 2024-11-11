#include <bits/stdc++.h>
using namespace std;
int ans[1000][1000] = {};
int main() {
  int k, f = 2, d = 30, l[30];
  scanf("%d", &k);
  ans[0][f] = ans[f][0] = 1;
  l[2] = f++;
  for (int i = 1; i >= 0; --i, ++f) {
    ans[f - 1][f] = ans[f][f - 1] = 1;
    l[i] = f;
  }
  for (int i = 29; i; --i)
    if (k & (1 << i)) {
      ans[l[i]][f] = ans[f][l[i]] = ans[l[i]][f + 1] = ans[f + 1][l[i]] = 1;
      for (int j = 1; j < i; ++j, f += 2)
        for (int a = 0; a < 2; ++a)
          for (int b = 2; b < 4; ++b) ans[f + a][f + b] = ans[f + b][f + a] = 1;
      ans[1][f] = ans[f][1] = ans[1][f + 1] = ans[f + 1][1] = 1;
      f += 2;
    }
  if (k % 2) ans[l[0]][1] = ans[1][l[0]] = 1;
  printf("%d\n", f);
  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < f; ++j) printf(ans[i][j] ? "Y" : "N");
    puts("");
  }
  return 0;
}
