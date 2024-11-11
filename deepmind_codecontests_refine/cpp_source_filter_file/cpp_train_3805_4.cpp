#include <bits/stdc++.h>
int h, w, t;
double pix[605][605];
double tmp[605][605];
struct Graph {
  int vexNum;
  double dis[20][20];
  void reset() {
    for (int i = 1; i <= vexNum; i++)
      for (int j = 1; j <= vexNum; j++) dis[i][j] = 0;
    vexNum = 0;
    return;
  }
} G, idGraph;
struct TSPsolution {
  int vexNum;
  double len;
  int path[20];
  void reset() {
    for (int i = 1; i <= vexNum; i++) path[i] = 0;
    len = 0;
    vexNum = 0;
    return;
  }
} idTSPsolution;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }
void init() {
  memset(pix, 0, sizeof(pix));
  memset(tmp, 0, sizeof(tmp));
  scanf("%d%d%d", &h, &w, &t);
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++) scanf("%lf", &pix[i][j]);
  return;
}
Graph CreateGraph() {
  Graph ret = idGraph;
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++) {
      int cnt = 0;
      int num = (i - 1) / (h / t);
      int up = max(num * h / t + 1, i - 1);
      int down = min((num + 1) * h / t, i + 1);
      int left = max(1, j - 1);
      int right = min(w, j + 1);
      for (int p = up; p <= down; p++)
        for (int q = left; q <= right; q++) {
          tmp[i][j] += pix[p][q];
          ++cnt;
        }
      tmp[i][j] /= cnt;
    }
  ret.vexNum = t;
  for (int i = 0; i < t; i++)
    for (int j = 0; j < t; j++) {
      double cur = 0;
      int a = (i + 1) * h / t;
      int b = j * h / t + 1;
      for (int k = 1; k <= w; k++) cur += fabs(tmp[a][k] - tmp[b][k]);
      ret.dis[i][j] = cur;
    }
  return ret;
}
double TSPcalclen(TSPsolution &x, Graph &G) {
  double sum = 0;
  for (int i = 1; i < x.vexNum; i++) {
    int u = x.path[i];
    int v = x.path[i + 1];
    sum += G.dis[u][v];
  }
  return sum;
}
void TSPswap(TSPsolution &x, int i, int j) {
  int t;
  t = x.path[i];
  x.path[i] = x.path[j];
  x.path[j] = t;
  return;
}
void TSPreverse(TSPsolution &x) {
  int n = x.vexNum;
  for (int i = 1; i <= n / 2; i++) {
    int t;
    t = x.path[i];
    x.path[i] = x.path[n - i + 1];
    x.path[n - i + 1] = t;
  }
  return;
}
void TSProtate(TSPsolution &x, int l, int r) {
  if (l > r) {
    int t;
    t = l;
    l = r;
    r = t;
  }
  int tmp = x.path[r];
  for (int i = r; i > l; i--) x.path[i] = x.path[i - 1];
  x.path[l] = tmp;
  return;
}
void TSPshift(TSPsolution &x, int l, int r) {
  int a[20], tot = 0, n = x.vexNum;
  for (int i = l; i <= r; i++) a[++tot] = x.path[i];
  for (int i = 1; i <= n; i++)
    if (i < l || i > r) a[++tot] = x.path[i];
  for (int i = 1; i <= n; i++) x.path[i] = a[i];
}
TSPsolution NewSolution(Graph &G, TSPsolution bestSol) {
  TSPsolution ret = idTSPsolution;
  int i = rand() % G.vexNum + 1;
  int j = rand() % G.vexNum + 1;
  if (i > j) {
    int t;
    t = i;
    i = j;
    j = t;
  }
  if (i == j) {
    ret = bestSol;
    return ret;
  }
  int cmd = rand() % 3;
  if (cmd == 0) {
    TSPswap(bestSol, i, j);
    bestSol.len = TSPcalclen(bestSol, G);
  }
  if (cmd == 1) {
    if (j == G.vexNum) {
      ret = bestSol;
      return ret;
    }
    TSProtate(bestSol, i, j);
    bestSol.len = TSPcalclen(bestSol, G);
  }
  if (cmd == 2) {
    TSPshift(bestSol, i, j);
    bestSol.len = TSPcalclen(bestSol, G);
  }
  ret = bestSol;
  return ret;
}
TSPsolution SA_TSP(Graph G) {
  const double inf = 1e9;
  const double speed = 0.998;
  const double initTem = 1e10;
  const double minTem = 0.000001;
  const int T = 1;
  int n = G.vexNum;
  TSPsolution bestSol = idTSPsolution;
  TSPsolution curSol = idTSPsolution;
  bestSol.len = inf;
  bestSol.vexNum = n;
  for (int i = 1; i <= n; i++) bestSol.path[i] = i - 1;
  double curTem = initTem;
  int cnt = 0;
  while (curTem > minTem) {
    ++cnt;
    for (int i = 1; i <= T; i++) {
      curSol = NewSolution(G, bestSol);
      if (curSol.len <= bestSol.len) {
        bestSol = curSol;
      } else {
        double diff = bestSol.len - curSol.len;
        int t1 = rand() % RAND_MAX;
        int t2 = RAND_MAX;
        double r = (double)t1 / (double)t2;
        double x = exp(diff / curTem);
        if (x > r) {
          bestSol = curSol;
        }
      }
    }
    curTem = curTem * speed;
  }
  return bestSol;
}
void print(TSPsolution ans) {
  int res[605];
  for (int i = 1; i <= ans.vexNum; i++) res[ans.path[i] + 1] = i;
  for (int i = 1; i <= ans.vexNum; i++)
    printf("%d%c", res[i], i == ans.vexNum ? '\n' : ' ');
  return;
}
void solve() {
  Graph G;
  TSPsolution ans;
  init();
  G = CreateGraph();
  ans = SA_TSP(G);
  print(ans);
  return;
}
int main() {
  srand(time(0));
  int T = 0;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
