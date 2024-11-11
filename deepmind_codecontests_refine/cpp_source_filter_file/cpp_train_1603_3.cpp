#include <bits/stdc++.h>
using namespace std;
const int N = 200009;
struct nod {
  int l, r, v;
  void get() {
    scanf("%d%d", &l, &r);
    r = l + r - 1;
  }
  bool operator<(const nod t) const { return l < t.l || (l == t.l && r > t.r); }
} re[N];
int use[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) re[i].get(), re[i].v = i + 1;
  sort(re, re + m);
  int ans = 0, p = 0, l = 0;
  use[re[0].v] = 1;
  for (int i = 1; i < m; i++) {
    if (re[i].l < re[p].r) {
      if (re[i].r > re[l].r) l = i;
    } else {
      use[re[l].v] = 1;
      p = l;
      if (re[i].r > re[l].r) l = i;
    }
  }
  use[re[l].v] = 1;
  for (int i = 1; i <= m; i++)
    if (!use[i]) ans++;
  printf("%d\n", ans);
  for (int i = 1, ou = 0; i <= m; i++)
    if (!use[i]) {
      if (ou)
        printf(" ");
      else
        ou = 1;
      printf("%d", i);
    }
  puts("");
  return 0;
}
