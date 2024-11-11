#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 1000010;
const int inf = 0x3f3f3f3f;
const long long oo = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 9;
int n, m;
struct Data {
  int a, b, id;
} da[N];
struct Seg {
  int l, r;
  vector<pair<int, int> > vt;
} tree[N * 4];
bool cmp(const Data &A, const Data &B) {
  if (A.b == B.b) return A.a < B.a;
  return A.b < B.b;
}
int que[N];
int a[N], b[N];
void b_tree(int l, int r, int idx) {
  tree[idx].l = l;
  tree[idx].r = r;
  tree[idx].vt.clear();
  if (l != r) {
    int mid = (l + r) >> 1;
    b_tree(l, mid, idx << 1);
    b_tree(mid + 1, r, idx << 1 | 1);
  }
  sort(da + l, da + r + 1, cmp);
  int left = 0, right = 0;
  for (int i = l; i <= r; i++) {
    while (right > left) {
      if (da[i].a >= da[que[right - 1]].a)
        right--;
      else
        break;
    }
    while (right > left + 1) {
      int ba = que[right - 1];
      int bb = que[right - 2];
      if (1ll * (da[ba].a - da[i].a) * (da[ba].b - da[bb].b) <=
          1ll * (da[bb].a - da[ba].a) * (da[i].b - da[ba].b))
        right--;
      else
        break;
    }
    que[right++] = i;
  }
  for (int i = left; i < right; i++) {
    if (i != left) {
      tree[idx].vt.push_back(make_pair((da[que[i - 1]].a - da[que[i]].a +
                                        da[que[i]].b - da[que[i - 1]].b - 1) /
                                           (da[que[i]].b - da[que[i - 1]].b),
                                       da[que[i]].id));
    } else {
      tree[idx].vt.push_back(make_pair(0, da[que[i]].id));
    }
  }
}
pair<long long, int> query(int l, int r, int t, int idx) {
  if (tree[idx].l == l && tree[idx].r == r) {
    int k = upper_bound(tree[idx].vt.begin(), tree[idx].vt.end(),
                        make_pair(t, inf)) -
            tree[idx].vt.begin() - 1;
    int id = tree[idx].vt[k].second;
    return make_pair(a[id] + 1ll * b[id] * t, id);
  }
  int mid = (tree[idx].l + tree[idx].r) >> 1;
  if (r <= mid) return query(l, r, t, idx << 1);
  if (l > mid) return query(l, r, t, idx << 1 | 1);
  return max(query(l, mid, t, idx << 1), query(mid + 1, r, t, idx << 1 | 1));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    da[i].a = a[i];
    da[i].b = b[i];
    da[i].id = i;
  }
  b_tree(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int l, r, t;
    scanf("%d%d%d", &l, &r, &t);
    printf("%d\n", query(l, r, t, 1).second);
  }
  return 0;
}
