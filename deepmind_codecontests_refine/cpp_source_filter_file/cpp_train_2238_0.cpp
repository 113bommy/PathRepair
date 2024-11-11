#include <bits/stdc++.h>
using namespace std;
int n, kn;
struct Q {
  int id, l, r;
} a[1000100];
int pos[1000100];
bool cmp(Q a, Q b) {
  if (pos[a.l] == pos[b.l])
    return a.r < b.r;
  else
    return a.l < b.l;
}
int main() {
  kn = 1000;
  for (int i = 1; i <= 1000000; i++) pos[i] = i / kn;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) printf("%d ", a[i].id);
}
