#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int totb = 0, totr = 0, totx = 0, deep;
int n;
struct data {
  int next, num;
} edgeb[400001], edger[400001];
struct data2 {
  int x;
  bool judge;
} ans[200001];
struct seg {
  int l, r, va;
} tr[2000001], tb[2000001];
int headb[200001], headr[200001];
int wb[200001], wr[200001], vr[200001], vb[200001], db[200001], dr[200001];
int fab[200001][21], far[200001][21], lb[200001], rb[200001], lr[200001],
    rr[200001];
int eb[200001], er[200001], vab[400001], var[400001], locb[400001],
    locr[400001], px;
bool visb[200001], visr[200001];
queue<data2> q;
bool cmp(data2 p, data2 q) { return p.x < q.x; }
void add1(int u, int v) {
  edgeb[++totb].next = headb[u];
  edgeb[totb].num = v;
  headb[u] = totb;
}
void add2(int u, int v) {
  edger[++totr].next = headr[u];
  edger[totr].num = v;
  headr[u] = totr;
}
void dfsb1(int x) {
  wb[x] = vb[x];
  db[x] = deep;
  lb[x] = totx + 1;
  totx += wb[x];
  for (int i = headb[x]; i != -1; i = edgeb[i].next) {
    int kx = edgeb[i].num;
    if (!db[kx]) {
      deep++;
      fab[kx][0] = x;
      dfsb1(kx);
      deep--;
      wb[x] += wb[kx];
    }
  }
  rb[x] = totx;
}
void dfsr1(int x) {
  wr[x] = vr[x];
  dr[x] = deep;
  lr[x] = totx + 1;
  totx += wr[x];
  for (int i = headr[x]; i != -1; i = edger[i].next) {
    int kx = edger[i].num;
    if (!dr[kx]) {
      deep++;
      far[kx][0] = x;
      dfsr1(kx);
      deep--;
      wr[x] += wr[kx];
    }
  }
  rr[x] = totx;
}
void build(int i, int l, int r) {
  tr[i].l = tb[i].l = l;
  tr[i].r = tb[i].r = r;
  if (l == r) {
    tb[i].va = vab[l];
    tr[i].va = var[l];
    if (locr[l] == px) tr[i].va = INF;
    return;
  }
  int mid = (l + r) / 2;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  tr[i].va = min(tr[i * 2].va, tr[i * 2 + 1].va);
  tb[i].va = min(tb[i * 2].va, tb[i * 2 + 1].va);
}
void deleb(int i, int l, int r, int va) {
  int nowl = tb[i].l, nowr = tb[i].r;
  if (nowl > r || nowr < l) return;
  if (tb[i].va > va) return;
  if (nowl == nowr) {
    tb[i].va = INF;
    if (visb[locb[nowl]]) return;
    tb[i].va = INF;
    data2 now;
    now.x = locb[nowl];
    now.judge = 1;
    q.push(now);
    visb[now.x] = 1;
    return;
  }
  deleb(i * 2, l, r, va);
  deleb(i * 2 + 1, l, r, va);
  tb[i].va = min(tb[i * 2].va, tb[i * 2 + 1].va);
}
void deler(int i, int l, int r, int va) {
  int nowl = tr[i].l, nowr = tr[i].r;
  if (nowl > r || nowr < l) return;
  if (tr[i].va > va) return;
  if (nowl == nowr) {
    tr[i].va = INF;
    if (visr[locr[nowl]]) return;
    data2 now;
    now.x = locr[nowl];
    now.judge = 0;
    q.push(now);
    visr[now.x] = 1;
    return;
  }
  deler(i * 2, l, r, va);
  deler(i * 2 + 1, l, r, va);
  tr[i].va = min(tr[i * 2].va, tr[i * 2 + 1].va);
}
void prelca() {
  fab[1][0] = far[1][0] = 1;
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) {
      far[i][j] = far[far[i][j - 1]][j - 1];
      fab[i][j] = fab[fab[i][j - 1]][j - 1];
    }
}
int lcab(int u, int v) {
  while (db[u] > db[v]) {
    int kx = log2(db[u] - db[v]);
    u = fab[u][kx];
  }
  while (db[u] < db[v]) {
    int kx = log2(db[v] - db[u]);
    v = fab[v][kx];
  }
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (fab[u][i] == fab[v][i]) continue;
    u = fab[u][i];
    v = fab[v][i];
  }
  return fab[u][0];
}
int lcar(int u, int v) {
  while (dr[u] > dr[v]) {
    int kx = log2(dr[u] - dr[v]);
    u = far[u][kx];
  }
  while (dr[u] < dr[v]) {
    int kx = log2(dr[v] - dr[u]);
    v = far[v][kx];
  }
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (far[u][i] == far[v][i]) continue;
    u = far[u][i];
    v = far[v][i];
  }
  return far[u][0];
}
void prep() {
  memset(headr, -1, sizeof(headr));
  memset(headb, -1, sizeof(headb));
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &eb[i]);
    add1(i, eb[i]);
    add1(eb[i], i);
  }
  for (int i = 2; i <= n; i++) {
    scanf("%d", &er[i]);
    add2(i, er[i]);
    add2(er[i], i);
  }
  for (int i = 2; i <= n; i++) {
    vr[i]++;
    vr[eb[i]]++;
    vb[i]++;
    vb[er[i]]++;
  }
  deep = 1;
  totx = 0;
  dfsb1(1);
  deep = 1;
  totx = 0;
  dfsr1(1);
  memset(vr, 0, sizeof(vr));
  memset(vb, 0, sizeof(vb));
  prelca();
  for (int i = 2; i <= n; i++) {
    vr[i]++;
    vr[eb[i]]++;
    var[vr[i] + lr[i] - 1] = var[vr[eb[i]] + lr[eb[i]] - 1] =
        dr[lcar(i, eb[i])];
    locr[vr[i] + lr[i] - 1] = locr[vr[eb[i]] + lr[eb[i]] - 1] = i - 1;
    vb[i]++;
    vb[er[i]]++;
    vab[vb[i] + lb[i] - 1] = vab[vb[er[i]] + lb[er[i]] - 1] =
        db[lcab(i, er[i])];
    locb[vb[i] + lb[i] - 1] = locb[vb[er[i]] + lb[er[i]] - 1] = i - 1;
  }
  scanf("%d", &px);
  build(1, 1, 2 * n - 2);
}
int getp(data2 x) {
  int i = x.x;
  if (x.judge == 0) {
    if (db[i + 1] < db[eb[i + 1]]) return eb[i + 1];
    return i + 1;
  }
  if (dr[i + 1] < dr[er[i + 1]]) return er[i + 1];
  return i + 1;
}
void work() {
  data2 gx;
  gx.judge = 0;
  gx.x = px;
  q.push(gx);
  visr[px] = 1;
  int headpx = 0;
  while (!q.empty()) {
    data2 k = q.front();
    ans[++headpx] = k;
    q.pop();
    int point = getp(k);
    if (k.judge == 0)
      deleb(1, lb[point], rb[point], db[point] - 1);
    else
      deler(1, lr[point], rr[point], dr[point] - 1);
  }
  printf("Blue\n%d", ans[1].x);
  for (int i = 2; i <= headpx; i++) {
    if (ans[i].judge != ans[i - 1].judge) {
      int nowj = i;
      while (nowj <= headpx && ans[nowj].judge == ans[i].judge) nowj++;
      sort(ans + i, ans + nowj, cmp);
      if (ans[i].judge == 0)
        printf("\nBlue\n");
      else
        printf("\nRed\n");
    }
    printf("%d ", ans[i].x);
  }
}
int main() {
  prep();
  work();
  return 0;
}
