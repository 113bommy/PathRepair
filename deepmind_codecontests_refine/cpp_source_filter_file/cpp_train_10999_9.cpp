#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r;
  int id;
} v[303303];
int n;
int cmp(const Node &a, const Node &b) {
  if (a.l != b.l) return a.l < b.l;
  return a.r < b.r;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &v[i].l, &v[i].r);
    v[i].id = i + 1;
  }
  sort(v, v + n, cmp);
  for (int i = 1; i < n; i++)
    if (v[i].r <= v[i - 1].r) {
      printf("%d %d\n", v[i].id, v[i - 1].id);
      return 0;
    }
  puts("-1 -1");
  return 0;
}
