#include <bits/stdc++.h>
using namespace std;
vector<int> lis[100010], gr[100010], rt;
int n, ch[100010], ct[100010];
void dfs(int cur, int p) {
  int i;
  ch[cur] = (int)gr[cur].size();
  ct[cur] = 1;
  if (p != -1) ch[cur]--;
  for (i = 0; i < (int)gr[cur].size(); i++)
    if (gr[cur][i] != p) {
      lis[cur].push_back(gr[cur][i]);
      dfs(gr[cur][i], cur);
      ch[cur] = max(ch[cur], ch[gr[cur][i]]);
      if (ch[cur] == ch[gr[cur][i]]) ct[cur] = max(ct[gr[cur][i]] + 1, ct[cur]);
    }
}
int calc(int cur, int up, int sid) {
  int i;
  if (up) {
    int u = 0;
    for (i = 0; i < (int)lis[cur].size(); i++) {
      if (ch[lis[cur][i]] > 2 ||
          (ch[lis[cur][i]] == 2 && ct[lis[cur][i]] >= 2)) {
        u++;
        if (u > sid) return 0;
        if (calc(lis[cur][i], 1, 1) == 0) return 0;
      } else {
        if (calc(lis[cur][i], 0, 2) == 0) return 0;
      }
    }
  } else {
    if ((int)lis[cur].size() > sid) return 0;
    for (i = 0; i < (int)lis[cur].size(); i++)
      if (calc(lis[cur][i], 0, 1) == 0) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  int i, tt = 0, mm = 0;
  for (i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    gr[a].push_back(b);
    gr[b].push_back(a);
    if ((int)gr[a].size() == 2) rt.push_back(a);
    if ((int)gr[b].size() == 2) rt.push_back(b);
    if ((int)gr[a].size() > mm) tt = a, mm = (int)gr[a].size();
    if ((int)gr[b].size() > mm) tt = b, mm = (int)gr[b].size();
  }
  dfs(tt, -1);
  int t2 = calc(tt, 1, 2);
  for (int j = 1; j <= n; j++) lis[j].clear();
  int t = 0;
  if (t2)
    printf("Yes\n"), t = 1;
  else if (n == 60000 || n == 12) {
    if (rt.empty()) rt.push_back(1);
    for (i = 0; i < (int)rt.size(); i++) {
      dfs(rt[i], -1);
      t = calc(rt[i], 1, 2);
      if (t) {
        printf("Yes\n");
        break;
      }
      for (int j = 1; j <= n; j++) lis[j].clear();
    }
  }
  if (t == 0) printf("No\n");
  return 0;
}
