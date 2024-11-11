#include <bits/stdc++.h>
using namespace std;
struct Tnode {
  int l, r, id;
};
Tnode a[101000];
int ans[101000];
int num[101000];
int n, m;
bool Cmp(Tnode A, Tnode B) { return A.r < B.r || (A.r == B.r && A.l < B.l); }
void Build(int j, int l, int r) {
  if (l == r) {
    num[j] = 1;
    return;
  }
  Build(j * 2, l, (l + r) / 2);
  Build(j * 2 + 1, (l + r) / 2 + 1, r);
  num[j] = num[j * 2] + num[j * 2 + 1];
}
void Cover(int j, int l, int r) {
  if (l == r) {
    num[j] = 0;
    return;
  }
  int mid = (l + r) / 2;
  if (num[j * 2])
    Cover(j * 2, l, mid);
  else
    Cover(j * 2 + 1, mid + 1, r);
  num[j] = num[j * 2] + num[n * 2 + 1];
}
bool Find(int j, int l, int r, int x, int y) {
  if (l == x && r == y) {
    if (!num[j]) return false;
    Cover(j, l, r);
    return true;
  }
  int mid = (l + r) / 2;
  bool flag = false;
  if (mid >= y)
    flag |= Find(j * 2, l, mid, x, y);
  else if (mid < x)
    flag |= Find(j * 2 + 1, mid + 1, r, x, y);
  else {
    if (Find(j * 2, l, mid, x, mid))
      flag = true;
    else if (Find(j * 2 + 1, mid + 1, r, mid + 1, y))
      flag = true;
  }
  num[j] = num[j * 2] + num[j * 2 + 1];
  return flag;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i].id = i;
    a[i].l = n - x + 1;
    a[i].r = y;
  }
  sort(a, a + m, Cmp);
  int tmp = m;
  m = 1;
  for (int i = 1; i < tmp; ++i)
    if (a[i].l != a[i - 1].l || a[i].r != a[i - 1].r) a[m++] = a[i];
  Build(1, 1, n);
  int res = 0;
  for (int i = 0; i < m; ++i) {
    bool flag = Find(1, 1, n, a[i].l, a[i].r);
    if (flag) ans[res++] = a[i].id;
  }
  sort(ans, ans + res);
  printf("%d\n", res);
  if (res) printf("%d", ans[0] + 1);
  for (int i = 1; i < res; ++i) printf(" %d", ans[i] + 1);
  printf("\n");
  return 0;
}
