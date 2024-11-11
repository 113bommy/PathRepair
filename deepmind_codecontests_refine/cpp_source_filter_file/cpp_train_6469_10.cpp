#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const double PI = acos(-1);
const double ERR = 1e-10;
int n;
long long a[maxn], k[maxn], prefix[maxn], prefix2[maxn];
struct node {
  long long maxvalue, value, lazy;
} tree[4 * maxn];
void pushup(int id) {
  tree[id].value = tree[2 * id + 1].value + tree[2 * id + 2].value;
  tree[id].maxvalue = max(tree[2 * id + 1].maxvalue, tree[2 * id + 2].maxvalue);
}
void createtree(int id, int s, int t) {
  tree[id].lazy = -0x3f3f3f3f3f3f3f3f;
  if (s == t)
    tree[id].value = tree[id].maxvalue = a[s] - prefix[s];
  else {
    int mid = s + (t - s) / 2;
    createtree(2 * id + 1, s, mid);
    createtree(2 * id + 2, mid + 1, t);
    pushup(id);
  }
}
void pushdown(int id, int s, int t) {
  if (tree[id].lazy != -0x3f3f3f3f3f3f3f3f) {
    int mid = s + (t - s) / 2;
    tree[2 * id + 1].lazy = tree[id].lazy;
    tree[2 * id + 2].lazy = tree[id].lazy;
    tree[2 * id + 1].value = (1LL * (mid - s + 1) * tree[id].lazy);
    tree[2 * id + 2].value = (1LL * (t - (mid + 1) + 1) * tree[id].lazy);
    tree[2 * id + 1].maxvalue = tree[id].lazy;
    tree[2 * id + 2].maxvalue = tree[id].lazy;
    pushup(id);
    tree[id].lazy = -0x3f3f3f3f3f3f3f3f;
  }
}
long long querysum(int id, int ns, int nt, int qs, int qt) {
  if (qs > nt || qt < ns) return 0;
  if (qs <= ns && qt >= nt) return tree[id].value;
  pushdown(id, ns, nt);
  int mid = ns + (nt - ns) / 2;
  return querysum(2 * id + 1, ns, mid, qs, qt) +
         querysum(2 * id + 2, mid + 1, nt, qs, qt);
}
void update(int id, int ns, int nt, int us, int ut, long long value) {
  if (us > nt || ut < ns) return;
  if (us <= ns && ut >= nt) {
    tree[id].lazy = value;
    tree[id].value = (1LL * (nt - ns + 1) * value);
    tree[id].maxvalue = value;
    return;
  }
  pushdown(id, ns, nt);
  int mid = ns + (nt - ns) / 2;
  update(2 * id + 1, ns, mid, us, ut, value);
  update(2 * id + 2, mid + 1, nt, us, ut, value);
  pushup(id);
}
void singleupdate(int id, int ns, int nt, int index, long long value) {
  if (ns == nt) {
    if (index == ns) {
      tree[id].value = value;
      tree[id].maxvalue = value;
    }
    return;
  }
  int mid = ns + (nt - ns) / 2;
  if (index <= mid)
    singleupdate(2 * id + 1, ns, mid, index, value);
  else
    singleupdate(2 * id + 2, mid + 1, nt, index, value);
  pushup(id);
}
int main() {
  int q, l, r;
  char op[2];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n - 1; i++) scanf("%lld", &k[i]);
  for (int i = 2; i <= n; i++) prefix[i] = prefix[i - 1] + k[i - 1];
  for (int i = 2; i <= n; i++) prefix2[i] = prefix2[i - 1] + prefix[i];
  createtree(0, 1, n);
  scanf("%d", &q);
  while (q--) {
    scanf("%s", op);
    scanf("%d%d", &l, &r);
    if (op[0] == 's')
      printf("%lld\n", querysum(0, 1, n, l, r) + prefix2[r] - prefix2[l - 1]);
    else if (op[0] == '+') {
      long long value = querysum(0, 1, n, l, l) + 1LL * r;
      int left = l, right = n;
      while (left <= right) {
        int mid = (right + left) / 2;
        if (querysum(0, 1, n, mid, mid) > value)
          right = mid - 1;
        else
          left = mid + 1;
      }
      update(0, 1, n, l, left, value);
    }
  }
  return 0;
}
