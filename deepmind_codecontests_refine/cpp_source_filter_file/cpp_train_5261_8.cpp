#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct data {
  int l, r, pos;
} a[MAXN];
int ans[MAXN], n, bit[MAXN], x[MAXN * 2];
map<int, int> mp;
bool cmp(data x, data y) { return x.r < y.r; }
int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}
void add(int i, int x) {
  while (i <= n * 2) {
    bit[i] += x;
    i += (i & -i);
  }
}
int main() {
  scanf("%d", &n);
  int cont = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].l, &a[i].r);
    x[++cont] = a[i].l;
    x[++cont] = a[i].r;
    a[i].pos = i;
  }
  sort(x + 1, x + cont + 1);
  for (int i = 1; i <= cont; i++) {
    mp[x[i]] = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    a[i].l = mp[a[i].l];
    a[i].r = mp[a[i].r];
  }
  for (int i = 1; i <= n; i++) {
    ans[a[i].pos] = i - 1 - sum(a[i].l);
    add(a[i].l, 1);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
}
