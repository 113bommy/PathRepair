#include <bits/stdc++.h>
int h, w, t;
double pix[605][605];
double tmp[605][605];
struct Graph {
  int vexNum;
  double dis[20][20];
};
struct Graph G, idGraph;
struct TSPsolution {
  int vexNum;
  double len;
  int path[20];
};
struct TSPsolution idTSPsolution;
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
struct Graph CreateGraph() {
  struct Graph ret = idGraph;
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
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < t; j++) {
      double sum = 0;
      int div = 10;
      for (int k = 0; k < w / div; k++) {
        double s1 = 0, s2 = 0;
        for (int u = k * div + 1; u <= (k + 1) * div; u++) {
          int x = (i + 1) * (h / t);
          int y = j * (h / t) + 1;
          s1 += tmp[x][u];
          s2 += tmp[y][u];
        }
        sum += abs(s1 - s2);
      }
      ret.dis[i][j] = sum;
    }
  }
  return ret;
}
double TSPcalclen(struct TSPsolution *x, struct Graph *G) {
  double sum = 0;
  int n = x->vexNum;
  for (int i = 1; i < n; i++) {
    int u = x->path[i];
    int v = x->path[i + 1];
    sum += G->dis[u][v];
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
    if (i > r) a[++tot] = x.path[i];
  for (int i = 1; i <= n; i++)
    if (i < l) a[++tot] = x.path[i];
  for (int i = 1; i <= n; i++) x.path[i] = a[i];
}
void TSPlsh(TSPsolution &x, int l, int r) {
  int a[20], tot = 0, n = x.vexNum;
  for (int i = l; i <= r; i++) a[++tot] = x.path[i];
  for (int i = 1; i <= n; i++)
    if (i < l || i > r) a[++tot] = x.path[i];
  for (int i = 1; i <= n; i++) x.path[i] = a[i];
}
void TSPrsh(TSPsolution &x, int l, int r) {
  int a[20], tot = 0, n = x.vexNum;
  for (int i = 1; i <= n; i++)
    if (i < l || i > r) a[++tot] = x.path[i];
  for (int i = l; i <= r; i++) a[++tot] = x.path[i];
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
  int cmd = rand() % 5;
  if (cmd == 0) {
    TSPswap(bestSol, i, j);
    bestSol.len = TSPcalclen(&bestSol, &G);
  }
  if (cmd == 1) {
    if (j == G.vexNum) {
      ret = bestSol;
      return ret;
    }
    TSProtate(bestSol, i, j);
    bestSol.len = TSPcalclen(&bestSol, &G);
  }
  if (cmd == 2) {
    TSPshift(bestSol, i, j);
    bestSol.len = TSPcalclen(&bestSol, &G);
  }
  if (cmd == 3) {
    if (i == 1) {
      ret = bestSol;
      return ret;
    }
    TSPlsh(bestSol, i, j);
    bestSol.len = TSPcalclen(&bestSol, &G);
  }
  if (cmd == 4) {
    if (i == 1) {
      ret = bestSol;
      return ret;
    }
    TSPrsh(bestSol, i, j);
    bestSol.len = TSPcalclen(&bestSol, &G);
  }
  ret = bestSol;
  return ret;
}
TSPsolution RandomSolution(int n, Graph &G) {
  int a[20], b[20];
  TSPsolution ret = idTSPsolution;
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 1; i <= n; i++) b[i] = rand();
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (b[a[i]] > b[a[j]]) {
        int tmp;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
  ret.vexNum = n;
  for (int i = 1; i <= n; i++) ret.path[i] = a[i] - 1;
  ret.len = TSPcalclen(&ret, &G);
  return ret;
}
TSPsolution SA_TSP(Graph G) {
  const double speed = 0.998;
  const double initTem = 1e9;
  const double minTem = 0.000001;
  const int T = 1;
  int n = G.vexNum;
  TSPsolution bestSol = idTSPsolution;
  TSPsolution curSol = idTSPsolution;
  bestSol = RandomSolution(n, G);
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
