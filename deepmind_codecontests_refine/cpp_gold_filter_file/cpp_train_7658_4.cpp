#include <bits/stdc++.h>
const int kMaxN = 200100;
const int kMaxM = kMaxN - 1;
int cnt, begin[kMaxN], end[kMaxM], next[kMaxM], we[kMaxM], st[kMaxM],
    rec[kMaxM], rwe[kMaxM], rst[kMaxM];
int n;
long long sum_we[kMaxN];
void addEdge(int u, int v, int w, int s) {
  next[cnt] = begin[u];
  begin[u] = cnt;
  end[cnt] = v;
  we[cnt] = w;
  st[cnt] = s;
  rec[cnt] = u;
  rwe[cnt] = w;
  rst[cnt] = s;
  ++cnt;
}
void dfs(int u) {
  for (int now = begin[u]; now != -1; now = next[now]) {
    int v = end[now];
    dfs(v);
    if (st[now] < sum_we[v]) {
      puts("-1");
      exit(0);
    }
    long long tmp = std::min((long long)we[now] - 1, st[now] - sum_we[v]);
    we[now] -= tmp;
    st[now] -= tmp;
    sum_we[u] += we[now] + sum_we[v];
  }
}
long long fix(int u, long long possible = 0x3f3f3f3f3f3f3f3fLL) {
  long long tot = 0;
  for (int now = begin[u]; now != -1; now = next[now]) {
    long long tmp = std::min(possible - tot, (long long)rwe[now] - we[now]);
    we[now] += tmp;
    st[now] += tmp;
    tot += tmp;
  }
  for (int now = begin[u]; now != -1; now = next[now]) {
    int v = end[now];
    tot += fix(v, std::min(possible - tot, st[now] - sum_we[v]));
  }
  return tot;
}
int main() {
  memset(begin, -1, sizeof(begin));
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w, s;
    scanf("%d%d%d%d", &u, &v, &w, &s);
    --u, --v;
    addEdge(u, v, w, s);
  }
  dfs(0);
  fix(0);
  printf("%d\n", n);
  for (int i = 0; i < cnt; ++i) {
    printf("%d %d %d %d\n", rec[i] + 1, end[i] + 1, we[i], st[i]);
  }
  return 0;
}
