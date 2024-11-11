#include <bits/stdc++.h>
const int N = 1024;
using namespace std;
int n, k, bs, L[N + 5], R[N + 5], blo[N + 5], ans, vis[N + 5];
char ch[2];
int main() {
  scanf("%d%d", &n, &k);
  bs = max(1, k / 2);
  for (int i = 1; i <= n; i++) {
    blo[i] = (i - 1) / bs + 1;
    if (!L[blo[i]]) L[blo[i]] = i;
    R[blo[i]] = i;
  }
  for (int i = 1; i <= n / bs; i++) {
    for (int st = 1; st <= i; st++) {
      if (st + i > blo[n]) break;
      for (int j = L[st]; j <= R[st]; j++) {
        printf("? %d\n", j);
        fflush(stdout);
        scanf("%s", ch + 1);
        if (ch[1] == 'Y') vis[j] = 1;
      }
      for (int x = st + i; x <= blo[n]; x += i) {
        for (int j = L[x]; j <= R[x]; j++) {
          printf("? %d\n", j);
          fflush(stdout);
          scanf("%s", ch + 1);
          if (ch[1] == 'Y') vis[j] = 1;
        }
      }
      printf("R\n");
      fflush(stdout);
    }
  }
  for (int i = 1; i <= n; i++) ans += vis[i];
  printf("! %d\n", ans);
  fflush(stdout);
  return 0;
}
