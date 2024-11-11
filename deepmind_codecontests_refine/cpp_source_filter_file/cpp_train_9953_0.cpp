#include <bits/stdc++.h>
using namespace std;
struct yts {
  int x, id;
} a[100100];
int c[100100], b[100100];
long long ans;
int n;
bool cmp(yts x, yts y) { return x.x < y.x || (x.x == y.x && x.id < y.id); }
void add(int x, int d) {
  for (int i = x; i <= n; i += (i & (-i))) c[i] += d;
}
int query(int x) {
  int ans = 0;
  for (int i = x; i; i -= (i & (-i))) ans += c[i];
  return ans;
}
int check(int l, int r, int x) {
  int ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid].id > x)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].x);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) add(i, 1);
  for (int i = 1; i <= n; i++) {
    int l = i, r = i;
    while (r < n && a[r + 1].x == a[l].x) r++;
    int pos = check(l, r, b[i - 1]);
    for (int j = pos; j <= r; j++) b[l + j - pos] = a[j].id;
    for (int j = l; j < pos; j++) b[l + r - pos + j - l + 1] = a[j].id;
    i = r;
  }
  int lst = 0;
  for (int i = 1; i <= n; i++) {
    if (lst < b[i])
      ans += query(b[i]) - query(lst);
    else
      ans += (n - i + 1) - (query(lst) - query(b[i]));
    add(b[i], -1);
    lst = b[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
