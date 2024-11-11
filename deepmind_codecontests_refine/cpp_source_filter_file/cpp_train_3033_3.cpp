#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 5e5 + 5;
int a[maxn];
int q;
long long pos[21];
int ans[maxn];
long long d[21];
struct node {
  long long l, r;
  int id;
} s[maxn];
bool cmp(node x, node y) { return x.r < y.r; }
void add(long long a, long long id) {
  for (int i = 20; i >= 0; i--) {
    if ((a >> i) & 1) {
      if (d[i] == 0) {
        d[i] = a;
        pos[i] = id;
        break;
      }
      if (pos[i] < id) swap(d[i], a), swap(pos[i], id);
      a ^= d[i];
    }
  }
}
long long query(int id) {
  long long tot = 0;
  for (int i = 20; i >= 0; i--) {
    if ((tot ^ d[i]) > tot && pos[i] >= id) tot ^= d[i];
  }
  return tot;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("&d%d", &s[i].l, s[i].r);
    s[i].id = i;
  }
  sort(s + 1, s + 1 + q, cmp);
  int l = 1;
  for (int i = 1; i <= q; i++) {
    while (l <= s[i].r && l <= n) add(a[l], l), ++l;
    ans[s[i].id] = query(s[i].l);
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
