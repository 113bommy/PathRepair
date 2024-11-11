#include <bits/stdc++.h>
using namespace std;
int num[100];
int flg[100];
int main() {
  for (int n, k; ~scanf("%d%d", &n, &k);) {
    int t = 1;
    memset(flg, 0, sizeof(flg));
    for (int i = 0; i < k; ++i) scanf("%d", num + i), flg[num[i]] = 1;
    for (int i = 0; i < k; ++i) {
      printf("%d", num[i]);
      for (int j = 1; j < n; ++j) {
        while (flg[t]) ++t;
        printf(" %d", t);
        flg[t] = 1;
      }
      puts("");
    }
  }
  return 0;
}
