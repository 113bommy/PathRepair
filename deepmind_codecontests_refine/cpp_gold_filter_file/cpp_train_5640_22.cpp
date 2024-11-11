#include <bits/stdc++.h>
using namespace std;
int d[100020];
int main(void) {
  int n, u, v;
  int i;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    d[u]++;
    d[v]++;
  }
  for (i = 1; i <= n; i++)
    if (d[i] == 2) {
      printf("NO\n");
      break;
    }
  if (i > n) printf("YES\n");
  return 0;
}
