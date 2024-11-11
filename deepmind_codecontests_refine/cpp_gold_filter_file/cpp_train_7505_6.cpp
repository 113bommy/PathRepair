#include <bits/stdc++.h>
using namespace std;
map<int, int> ap[200000 + 1];
vector<int> g[200000 + 1];
struct aint {
  int mn, ap;
  int upd;
};
aint arb[(200000 << 2) + 1];
int ord[(200000 << 1) + 1];
int rmq[(200000 << 1) + 1][18 + 1];
int idx[(200000 << 1) + 1][18 + 1];
int first[200000 + 1];
int k;
int n, q;
int X;
int DFS[200000 + 1];
int firstDFS[200000 + 1];
int lastDFS[200000 + 1];
int p2[(200000 << 1) + 1];
void add(int a, int b) { g[a].push_back(b); }
void readFile() {
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
}
int depth;
void dfs(int a, int tata) {
  ++X;
  DFS[X] = a;
  firstDFS[a] = lastDFS[a] = X;
  ++depth;
  ord[++k] = a;
  first[a] = k;
  rmq[k][0] = depth;
  idx[k][0] = a;
  for (auto u : g[a]) {
    if (u != tata) {
      dfs(u, a);
      ord[++k] = a;
      rmq[k][0] = depth;
      idx[k][0] = a;
      lastDFS[a] = max(lastDFS[a], lastDFS[u]);
    }
  }
  --depth;
}
void getRmq() {
  int i, j;
  for (j = 1; (1 << j) <= k; j++) {
    int p = (1 << j);
    int p2 = p >> 1;
    for (i = 1; i + p - 1 <= k; i++) {
      if (rmq[i][j - 1] < rmq[i + p2][j - 1]) {
        rmq[i][j] = rmq[i][j - 1];
        idx[i][j] = idx[i][j - 1];
      } else {
        rmq[i][j] = rmq[i + p2][j - 1];
        idx[i][j] = idx[i + p2][j - 1];
      }
    }
  }
}
void getP2() {
  p2[1] = 0;
  for (int i = 2; i <= k; i++) p2[i] = p2[i >> 1] + 1;
}
int getLCA(int a, int b) {
  if (first[a] > first[b]) swap(a, b);
  int dist = first[b] - first[a] + 1;
  int p = p2[dist];
  int diff = dist - (1 << p);
  if (rmq[first[a]][p] < rmq[first[a] + diff][p]) return idx[first[a]][p];
  return idx[first[a] + diff][p];
}
void preCalc() {
  dfs(1, -1);
  getRmq();
  getP2();
}
void upd(int poz, int st, int dr, int a, int b, int nr) {
  if (st == dr) {
    arb[poz].mn += nr;
    arb[poz].upd = 0;
    arb[poz].ap = 1;
    return;
  }
  if (st == a && dr == b) {
    arb[poz].mn += nr;
    arb[poz].upd += nr;
    return;
  }
  int mid = (st + dr) >> 1;
  upd(poz << 1, st, mid, st, mid, arb[poz].upd);
  upd((poz << 1) + 1, mid + 1, dr, mid + 1, dr, arb[poz].upd);
  arb[poz].upd = 0;
  if (b <= mid) upd(poz << 1, st, mid, a, b, nr);
  if (a > mid) upd((poz << 1) + 1, mid + 1, dr, a, b, nr);
  if (a <= mid && b > mid) {
    upd(poz << 1, st, mid, a, mid, nr);
    upd((poz << 1) + 1, mid + 1, dr, mid + 1, b, nr);
  }
  if (arb[poz << 1].mn == arb[(poz << 1) + 1].mn) {
    arb[poz].mn = arb[poz << 1].mn;
    arb[poz].ap = arb[poz << 1].ap + arb[(poz << 1) + 1].ap;
  } else {
    int p = (arb[poz << 1].mn < arb[(poz << 1) + 1].mn ? (poz << 1)
                                                       : (poz << 1) + 1);
    arb[poz].mn = arb[p].mn;
    arb[poz].ap = arb[p].ap;
  }
}
void build(int poz, int st, int dr) {
  arb[poz].mn = 0;
  arb[poz].upd = 0;
  arb[poz].ap = dr - st + 1;
  if (st == dr) return;
  int mid = (st + dr) >> 1;
  build(poz << 1, st, mid);
  build((poz << 1) + 1, mid + 1, dr);
}
int getMin(int st, int dr) {
  int len = dr - st + 1;
  int p = p2[len];
  int diff = len - (1 << p);
  return min(rmq[st][p], rmq[st + diff][p]);
}
int cautBin(int a, int b) {
  int i = 0;
  int pas = 1 << 18;
  while (pas != 0) {
    if (first[b] - (i + pas) >= 1 &&
        getMin(first[b] - (i + pas), first[b]) > rmq[first[a]][0])
      i += pas;
    pas >>= 1;
  }
  return ord[first[b] - i];
}
void ansQues() {
  build(1, 1, n);
  int a, b;
  for (int i = 1; i <= q; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    int str = getLCA(a, b);
    ap[a][b]++;
    int ca = 1;
    int cb = -1;
    if ((ap[a][b] & 1) == 0) {
      ca = -ca;
      cb = -cb;
    }
    if (str != a && str != b) {
      upd(1, 1, n, 1, n, ca);
      upd(1, 1, n, firstDFS[a], lastDFS[a], cb);
      upd(1, 1, n, firstDFS[b], lastDFS[b], cb);
    } else {
      if (str == b) swap(a, b);
      int care = cautBin(a, b);
      upd(1, 1, n, firstDFS[care], lastDFS[care], ca);
      upd(1, 1, n, firstDFS[b], lastDFS[b], cb);
    }
    if (arb[1].mn != 0)
      cout << "0\n";
    else
      cout << arb[1].ap << "\n";
  }
}
int main() {
  readFile();
  preCalc();
  ansQues();
  return 0;
}
