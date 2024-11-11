#include <bits/stdc++.h>
using namespace std;
struct node {
  int s;
  float x;
  int pos;
} p[5010];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d%f", &p[i].s, &p[i].x);
  sort(p, p + n, cmp);
  for (int i = 0; i < n; i++) p[i].pos = i;
  int f[5010];
  for (int i = 0; i < n; i++) f[i] = 1;
  int ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (p[i].s >= p[j].s) {
        f[i] = ((f[i]) > (f[j] + 1) ? (f[i]) : (f[j] + 1));
        if (f[i] > ans) ans = f[i];
      }
  printf("%d\n", n - ans);
  return 0;
}
