#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int f[maxn];
int bc[maxn], ac[maxn];
int a[maxn], b[maxn];
int n, m;
void Insert() {
  memset(bc, 0, sizeof(bc));
  memset(ac, 0, sizeof(ac));
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(f, 0, sizeof(f));
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    int i;
    Insert();
    int flag = 0, x = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &f[i]);
      if (!ac[f[i]]) bc[f[i]] = i;
      ac[f[i]]++;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
      if (ac[b[i]]) {
        if (ac[b[i]] > 1)
          flag = 2;
        else
          a[i] = bc[b[i]] + 1;
        x++;
      }
    }
    if (x < m)
      printf("Impossible\n");
    else if (flag == 2 && x == m)
      printf("Ambiguity\n");
    else if (x == m && flag == 0) {
      printf("Possible\n");
      for (int i = 0; i < m; i++) {
        if (i == 0)
          printf("%d", a[i]);
        else
          printf(" %d", a[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
