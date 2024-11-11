#include <bits/stdc++.h>
struct Side {
  int to;
  int next;
  int length;
  Side() { to = next = length = 0; }
  Side(int a, int b, int c) {
    to = a;
    length = b;
    next = c;
  }
};
int n;
int w[200001];
int sidecnt;
int head[200001];
Side sides[200001 << 1];
bool visited[200001];
int siz[200001];
int maxpart[200001] = {0x3f3f3f3f};
double d[200001];
double v[200001];
int ans1;
double ans2 = 1e20;
void inline adde(int x, int y, int z, bool repeat = true) {
  sides[++sidecnt] = Side(y, z, head[x]);
  head[x] = sidecnt;
  if (repeat) {
    adde(y, x, z, false);
  }
}
int center(int x, int father, int sum) {
  int rt = 0;
  siz[x] = 1;
  maxpart[x] = 0;
  int next = head[x];
  while (next != 0) {
    int y = sides[next].to;
    if (y != father && !visited[y]) {
      int subc = center(y, x, sum);
      maxpart[x] = std::max(maxpart[x], siz[y]);
      siz[x] += siz[y];
      if (maxpart[subc] < maxpart[rt]) {
        rt = subc;
      }
    }
    next = sides[next].next;
  }
  maxpart[x] = std::max(maxpart[x], sum - siz[x]);
  if (maxpart[x] < maxpart[rt]) {
    rt = x;
  }
  return rt;
}
void dfs1(int x, int father, double& sum, int dis) {
  sum += std::pow(dis, 1.5) * w[x];
  int next = head[x];
  while (next != 0) {
    int y = sides[next].to;
    if (y != father) {
      dfs1(y, x, sum, dis + sides[next].length);
    }
    next = sides[next].next;
  }
}
void dfs2(int x, int father, double& sum1, int dis) {
  sum1 += std::pow(dis, 0.5) * 1.5 * w[x];
  int next = head[x];
  while (next != 0) {
    int y = sides[next].to;
    if (y != father) {
      dfs2(y, x, sum1, dis + sides[next].length);
    }
    next = sides[next].next;
  }
}
void calc(int x) {
  visited[x] = true;
  v[x] = 0;
  dfs1(x, 0, v[x], 0);
  if (v[x] < ans2) {
    ans1 = x;
    ans2 = v[x];
  }
  int next = head[x];
  double dsum = 0;
  while (next != 0) {
    int y = sides[next].to;
    if (!visited[y]) {
      d[y] = 0;
      dfs2(y, 0, d[y], sides[next].length);
      dsum += d[y];
    }
    next = sides[next].next;
  }
  next = head[x];
  while (next != 0) {
    int y = sides[next].to;
    if (!visited[y]) {
      if (dsum - d[y] * 2 < 0) {
        calc(center(y, x, siz[y]));
        break;
      }
    }
    next = sides[next].next;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    adde(x, y, z);
  }
  calc(center(1, 0, n));
  printf("%d %.10lf", ans1, ans2);
  return 0;
}
