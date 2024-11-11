#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], b[N], f[N], d[N];
map<int, int> V;
int main() {
  int n, m, flag = 0, ans = 0;
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &f[i]);
    V[f[i]]++;
    a[f[i]] = i;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    if (V[b[i]] == 0) ans = 1;
    if (V[b[i]] > 1) flag = 1;
  }
  if (ans)
    printf("Impossible\n");
  else if (flag)
    printf("Ambiguity\n");
  else {
    printf("Possible\n");
    for (i = 0; i < m - 1; i++) {
      printf("%d ", a[b[i]] + 1);
    }
    printf("%d\n", a[b[i]] + 1);
  }
  return 0;
}
