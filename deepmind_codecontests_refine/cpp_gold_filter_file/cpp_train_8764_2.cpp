#include <bits/stdc++.h>
using namespace std;
vector<int> v[(1 << 17) + 5];
int n, dep[(1 << 17) + 5], s, t, rt1, rt2, stk[(1 << 17) + 5], top,
    siz[(1 << 17) + 5];
void dfs1(int np, int fath) {
  dep[np] = dep[fath] + 1;
  for (int x : v[np])
    if (x != fath) dfs1(x, np);
}
int ans;
void dfs2(int np, int fath) {
  stk[++top] = np;
  if (np == t) {
    rt1 = stk[(top + 1) >> 1];
    if (!(top & 1)) rt2 = stk[(top >> 1) + 1];
  }
  for (int x : v[np])
    if (x != fath) dfs2(x, np);
  top--;
}
bool flag1[(1 << 17) + 5], flag2[(1 << 17) + 5];
bool dfs3(int np, int fath) {
  siz[np] = 1;
  bool flag = 0;
  for (int x : v[np]) {
    if (x == fath) continue;
    bool tmp = dfs3(x, np);
    if (tmp) {
      if (flag) {
        puts("0");
        exit(0);
      }
      flag = 1;
    }
    siz[np] += siz[x];
  }
  if (!flag1[siz[np]] && !flag2[siz[np]]) {
    puts("0");
    exit(0);
  }
  if (flag) {
    if (!flag2[siz[np]]) {
      puts("0");
      exit(0);
    }
    return 1;
  }
  if (!flag && flag2[siz[np]]) {
    ans = np;
    return 1;
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) flag1[(1 << i) - 1] = 1, flag2[(1 << i) - 2] = 1;
  n = (1 << n) - 2;
  for (int i = 1, ti, tj; i < n; i++) {
    scanf("%d%d", &ti, &tj);
    v[ti].push_back(tj);
    v[tj].push_back(ti);
  }
  dfs1(1, 0);
  for (int i = 1; i <= n; i++)
    if (dep[i] > dep[s]) s = i;
  dfs1(s, 0);
  for (int i = 1; i <= n; i++)
    if (dep[i] > dep[t]) t = i;
  dfs2(s, 0);
  if (rt1 > rt2) swap(rt1, rt2);
  dfs3(rt2, 0);
  if (rt1)
    printf("2\n%d %d", rt1, rt2);
  else
    printf("1\n%d\n", ans);
  return 0;
}
