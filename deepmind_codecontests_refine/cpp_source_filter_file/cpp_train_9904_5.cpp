#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 200;
int minn[maxn << 2], maxx[maxn << 2], dif[maxn];
int lazy[maxn << 2];
struct node {
  int le;
  int ri;
} edge[500 + 10];
int sto[maxn];
int ans1, ans2;
vector<int> q1[maxn], q2[maxn];
void up(int rt) {
  minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]);
  maxx[rt] = max(maxx[rt << 1], maxx[rt << 1 | 1]);
  dif[rt] = maxx[rt] - minn[rt];
}
void build(int l, int r, int rt) {
  if (l == r) {
    int tmp;
    scanf("%d", &tmp);
    minn[rt] = tmp;
    maxx[rt] = tmp;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  up(rt);
}
void down(int rt) {
  if (lazy[rt]) {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    minn[rt << 1] += lazy[rt];
    minn[rt << 1 | 1] += lazy[rt];
    maxx[rt << 1] += lazy[rt];
    maxx[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
}
void update(int l, int r, int rt, int L, int R, int p) {
  if (L <= l && R >= r) {
    minn[rt] += p;
    maxx[rt] += p;
    lazy[rt] += p;
    return;
  }
  down(rt);
  int m = (l + r) >> 1;
  if (L <= m) update(l, m, rt << 1, L, R, p);
  if (R > m) update(m + 1, r, rt << 1 | 1, L, R, p);
  up(rt);
}
int main() {
  int n, m, tmp, len;
  scanf("%d %d", &n, &m);
  build(1, n, 1);
  int ans = -0x3f3f3f3f, id = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &edge[i].le, &edge[i].ri);
    q1[edge[i].le].push_back(i);
    q2[edge[i].ri].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    len = q2[i - 1].size();
    for (int j = 0; j < len; j++) {
      tmp = q2[i - 1][j];
      update(1, n, 1, edge[tmp].le, edge[tmp].ri, 1);
    }
    len = q1[i].size();
    for (int j = 0; j < len; j++) {
      tmp = q1[i][j];
      update(1, n, 1, edge[tmp].le, edge[tmp].ri, -1);
    }
    if (ans < dif[1]) {
      ans = dif[1];
      id = i;
    }
  }
  int num = 0;
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++) {
    if (edge[i].le <= id && edge[i].ri >= id) {
      sto[++num] = i;
    }
  }
  printf("%d\n", num);
  for (int i = 1; i <= num; i++) {
    if (i == 1)
      printf("%d", sto[i]);
    else
      printf(" %d", sto[i]);
  }
  printf("\n");
  return 0;
}
