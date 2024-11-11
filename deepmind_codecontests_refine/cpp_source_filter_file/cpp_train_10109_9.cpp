#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
int N, M;
int inn[maxn], out[maxn], vis[maxn], src[maxn];
set<int> con[maxn], ss;
vector<int> v[maxn];
void dfs(int now, int rt) {
  if (vis[now]) return;
  vis[now] = 1;
  if (out[now] == 0) con[rt].insert(now);
  for (vector<int>::iterator it = v[now].begin(); it != v[now].end(); it++)
    if (vis[*it] == 0) dfs(*it, rt);
}
void add(int now) {
  for (set<int>::iterator si = con[now].begin(); si != con[now].end(); si++)
    ss.insert(*si);
}
int main() {
  scanf("%d%d", &N, &M);
  int a, b, sz = 0, cnt = 0;
  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    out[a]++;
    inn[b]++;
  }
  for (int i = 1; i <= N; i++)
    if (inn[i] == 0) {
      memset(vis, 0, sizeof(vis));
      dfs(i, i);
      src[sz++] = i;
    }
  int ok = 1;
  for (int i = 0; i < (1 << sz); i++) {
    ss.clear();
    cnt = 0;
    for (int j = 0; j < sz; j++)
      if (i & (j << 1)) {
        add(src[j]);
        cnt++;
      }
    if (ss.size() < cnt || (ss.size() == cnt && cnt != sz && cnt != 0)) ok = 0;
  }
  printf("%s\n", ok ? "YES" : "NO");
}
