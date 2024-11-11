#include <bits/stdc++.h>
using namespace std;
struct komm {
  int type;
  int l, r;
  int d;
};
int a[5010];
int sol[5010];
vector<komm> V;
int main() {
  for (int i = 0; i < 5010; i++) a[i] = 1000000010;
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    komm k;
    scanf("%d %d %d %d", &k.type, &k.l, &k.r, &k.d);
    k.l--;
    k.r--;
    V.push_back(k);
  }
  for (int i = 0; i < V.size(); i++) {
    int p = 1;
    if (V[i].type == 1)
      for (int j = V[i].l; j <= V[i].r; j++) a[j] += V[i].d;
    else {
      for (int j = V[i].l; j <= V[i].r; j++) {
        if (a[j] >= V[i].d) {
          p = 0;
          a[j] = V[i].d;
        }
      }
      if (p == 1) {
        printf("NO\n");
        return 0;
      }
    }
  }
  for (int i = V.size() - 1; i >= 0; i--) {
    if (V[i].type == 1) {
      for (int j = V[i].l; j <= V[i].r; j++) a[j] -= V[i].d;
    }
  }
  for (int i = 0; i < n; i++)
    if (a[i] > 1000000000) a[i] = 1000000000;
  for (int i = 0; i < n; i++)
    if (a[i] < -1000000000) a[i] = -1000000000;
  for (int i = 0; i < n; i++) sol[i] = a[i];
  for (int i = 0; i < V.size(); i++) {
    int p = 0;
    if (V[i].type == 1)
      for (int j = V[i].l; j <= V[i].r; j++) a[j] += V[i].d;
    else {
      for (int j = V[i].l; j <= V[i].r; j++) {
        if (a[j] > V[i].d) {
          p = 1;
          a[j] = V[i].d;
        }
      }
      if (p == 1) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) printf("%d ", sol[i]);
  printf("\n");
  return 0;
}
