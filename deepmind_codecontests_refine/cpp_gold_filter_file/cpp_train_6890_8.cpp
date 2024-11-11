#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 20;
const double eps = 1e-5;
const int inf = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int n, m, ans, tot;
int b[maxn], rt[maxn];
struct number {
  int val, id;
} a[maxn];
struct node {
  int ls, rs, sum;
} tree[maxn * 20];
bool cmp(number a, number b) {
  if (a.val != b.val)
    return a.val > b.val;
  else
    return a.id < b.id;
}
void insert(int num, int& x, int l, int r) {
  tree[++tot] = tree[x];
  x = tot;
  ++tree[x].sum;
  if (l == r) return;
  int mid = (l + r) / 2;
  if (num <= mid)
    insert(num, tree[x].ls, l, mid);
  else
    insert(num, tree[x].rs, mid + 1, r);
}
int query(int i, int j, int k, int l, int r) {
  if (l == r) return l;
  int tp = tree[tree[j].ls].sum - tree[tree[i].ls].sum;
  int mid = (l + r) / 2;
  if (k <= tp)
    return query(tree[i].ls, tree[j].ls, k, l, mid);
  else
    return query(tree[i].rs, tree[j].rs, k - tp, mid + 1, r);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].val);
    a[i].id = i;
    b[i] = a[i].val;
  }
  sort(a + 1, a + n + 1, cmp);
  tot = 0;
  for (int i = 1; i <= n; i++) {
    rt[i] = rt[i - 1];
    insert(a[i].id, rt[i], 1, n);
  }
  scanf("%d", &m);
  int k, pos;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &k, &pos);
    ans = query(rt[0], rt[k], pos, 1, n);
    printf("%d\n", b[ans]);
  }
  return 0;
}
