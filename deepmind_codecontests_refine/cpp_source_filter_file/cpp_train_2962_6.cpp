#include <bits/stdc++.h>
using namespace std;
int V, E;
int w[503];
int main() {
  scanf("%d", &V);
  scanf("%d", &E);
  for (int i = 1; i <= V; i++) scanf("%d", &w[i]);
  double ans = 0;
  for (int zz = 0; zz < (E); zz++) {
    int v1;
    scanf("%d", &v1);
    int v2;
    scanf("%d", &v2);
    int e;
    scanf("%d", &e);
    ans = max(ans, (double)(w[v1] + w[v2]) / e);
  }
  printf("%.10d\n", ans);
  return 0;
}
