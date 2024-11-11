#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int INF = 2000000000;
struct Tpair {
  int rad, c;
  int l() { return c - rad; }
  int r() { return c + rad; }
} P[maxn];
int n;
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &P[i].c, &P[i].rad);
}
int ord[maxn];
int a[maxn];
vector<int> ans[maxn];
bool cmp1(int a, int b) { return P[a].rad < P[b].rad; }
bool cmp2(int a, int b) {
  return P[a].r() < P[b].r() || (P[a].r() == P[b].r() && P[a].l() > P[b].l());
}
int cur[maxn];
int f[maxn], lat[maxn], best[maxn];
void work() {
  P[0].c = 0, P[0].rad = INF;
  for (int i = 0; i <= n; i++) ord[i] = a[i] = i;
  sort(ord, ord + n + 1, cmp1);
  sort(a, a + n + 1, cmp2);
  for (int i = 0; i <= n; i++) {
    int u = ord[i], cs = 0;
    for (int j = 0; j <= n; j++)
      if (a[j] != u && P[a[j]].l() >= P[u].l() && P[a[j]].r() <= P[u].r())
        cur[cs++] = a[j];
    ans[u].push_back(u);
    if (cs) {
      for (int j = 0; j < cs; j++) {
        int v = cur[j];
        if (!j || P[cur[0]].r() > P[v].l()) {
          f[j] = ans[v].size();
          lat[j] = -1;
        } else {
          int L = 0, R = j - 1;
          while (L < R) {
            int mid = (L + R + 1) >> 1;
            if (P[cur[mid]].r() <= P[v].l())
              L = mid;
            else
              R = mid - 1;
          }
          lat[j] = L;
          f[j] = ans[v].size() + f[best[lat[j]]];
        }
        if (j && f[best[j - 1]] > f[j])
          best[j] = best[j - 1];
        else
          best[j] = j;
      }
      for (int t = cs - 1; t != -1; t = lat[t]) {
        t = best[t];
        int v = cur[t];
        for (int i = 0; i < ans[v].size(); i++) ans[u].push_back(ans[v][i]);
      }
    }
  }
}
void print() {
  printf("%d\n", ans[0].size() - 1);
  for (int i = 1; i < ans[0].size(); i++) printf("%d ", ans[0][i]);
  printf("\n");
}
int main() {
  init();
  work();
  print();
  return 0;
}
