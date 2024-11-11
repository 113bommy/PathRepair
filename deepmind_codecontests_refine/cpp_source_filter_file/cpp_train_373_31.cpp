#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000005], cnt;
string s[1000005];
int val[1000005];
struct Tree {
  int cnt, mod[5];
} tree[4 * 1000005];
void push_up(int x) {
  for (int i = 0; i < 5; i++)
    tree[x].mod[i] = tree[x << 1].mod[i] +
                     tree[x << 1 | 1].mod[((i - tree[x << 1].cnt) % 5 + 5) % 5];
}
void build(int x, int l, int r) {
  tree[x].cnt = 0;
  if (l == r) {
    memset(tree[x].mod, 0, sizeof(tree[x].mod));
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  push_up(x);
}
void update(int l, int r, int x, int pos, int val) {
  tree[x].cnt += val;
  if (l == r) {
    if (tree[x].cnt == 0)
      tree[x].mod[1] = 0;
    else
      tree[x].mod[1] = a[pos];
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(l, mid, x << 1, pos, val);
  else
    update(mid + 1, r, x << 1 | 1, pos, val);
  push_up(x);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      if (s[i] != "sum") {
        scanf("%d", &val[i]);
        a[++cnt] = val[i];
      }
    }
    sort(a + 1, a + 1 + cnt);
    int len = unique(a + 1, a + 1 + cnt) - a - 1;
    if (len == 0) len = 1;
    build(1, 1, len);
    for (int i = 1; i <= n; i++) {
      string ty = s[i];
      if (ty == "add") {
        int pos = lower_bound(a + 1, a + 1 + len, val[i]) - a;
        update(1, len, 1, pos, 1);
      } else if (ty == "del") {
        int pos = lower_bound(a + 1, a + 1 + len, val[i]) - a;
        update(1, len, 1, pos, -1);
      } else
        cout << tree[1].mod[3] << endl;
    }
  }
}
