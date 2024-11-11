#include <bits/stdc++.h>
using namespace std;
inline int lowbit(int a) { return a & (-a); }
int update(int tree[], int a, int b, int n) {
  while (a <= n) {
    tree[a] += b;
    a += lowbit(a);
  }
  return 0;
}
int ask(int tree[], int a) {
  int resu = 0;
  while (a > 0) {
    resu += tree[a];
    a -= lowbit(a);
  }
  return resu;
}
void modify(int tree[], int s, int t, int b, int n) {
  update(tree, s, b, n);
  update(tree, t + 1, -b, n);
}
struct node {
  int l, r;
  bool operator<(const struct node &a) const {
    if (a.r == r) return a.l > l;
    return a.r > r;
  }
} seg[300010];
int tree[1000010];
vector<int> query[300010];
vector<int> off[1000010];
map<pair<int, int>, int> offans;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &seg[i].l, &seg[i].r);
  sort(seg + 1, seg + 1 + n);
  for (int i = 1; i <= m; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      int u, v;
      scanf("%d", &v);
      if (query[i].size() > 0)
        u = query[i][query[i].size() - 1];
      else
        u = 0;
      query[i].push_back(v);
      off[v].push_back(u);
    }
  }
  for (int i = 1; i <= n; i++) modify(tree, seg[i].l, seg[i].r, 1, 300010);
  for (int i = 1, j = 1; i <= 1000000; i++) {
    for (int k = 0; k < (int)off[i].size(); k++) {
      int temp = ask(tree, off[i][k]);
      offans[make_pair(off[i][k], i)] = temp;
    }
    while (seg[j].r == i) {
      modify(tree, seg[j].l, seg[j].r, -1, 300010);
      j++;
    }
  }
  for (int i = 1; i <= n; i++) modify(tree, seg[i].l, seg[i].r, 1, 300010);
  for (int i = 1; i <= m; i++) {
    int resu = 0, u = 0, v;
    for (int j = 0; j < (int)query[i].size(); j++) {
      v = query[i][j];
      int temp = ask(tree, v);
      resu += temp;
      temp = offans[make_pair(u, v)];
      resu -= temp;
      u = v;
    }
    printf("%d\n", resu);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
