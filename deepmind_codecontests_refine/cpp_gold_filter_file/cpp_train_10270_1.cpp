#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e3;
const int Inf = 1 << 30;
struct node {
  char s[15];
  int num, w;
} s[MaxN + 5], ans[MaxN + 5];
char cur[15];
char t[MaxN + 2][MaxN + 2][11];
vector<int> vet[MaxN + 5];
int num[MaxN + 5], Size[MaxN + 5];
int nxt[MaxN + 2][MaxN + 2];
int cnt;
int vis[MaxN + 5];
int res[MaxN + 5];
map<string, int> mp;
map<pair<int, int>, int> mp1;
struct cmp1 {
  bool operator()(node A, node B) {
    if (A.w == B.w) return A.num < B.num;
    return A.w > B.w;
  }
};
priority_queue<node, vector<node>, cmp1> q;
bool cmp(node A, node B) { return strcmp(A.s, B.s) < 0; }
int main() {
  int n, tot = 0;
  scanf("%d", &n);
  mp.clear();
  mp1.clear();
  for (int i = 1; i <= n; i++) {
    vis[i] = 1;
    res[i] = -1;
    vet[i].clear();
    scanf(" %s %d", s[i].s, &s[i].num);
    if (mp[s[i].s] == 0) mp[s[i].s] = ++tot;
    mp1[make_pair(mp[s[i].s], s[i].num)] = i;
    scanf("%d", &Size[i]);
    for (int j = 0; j < Size[i]; j++) {
      scanf(" %s %d", t[i][j], &nxt[i][j]);
    }
  }
  cnt = -1;
  while (!q.empty()) q.pop();
  node xxx, yyy;
  xxx = s[1];
  xxx.w = 1;
  q.push(xxx);
  int now, x, y;
  pair<int, int> ppp;
  while (!q.empty()) {
    xxx = q.top();
    q.pop();
    ppp.first = mp[xxx.s];
    ppp.second = xxx.num;
    now = mp1[ppp];
    if (vis[ppp.first] == 0) continue;
    vis[ppp.first] = 0;
    ans[++cnt] = xxx;
    for (int i = 0; i < Size[now]; i++) {
      y = mp[t[now][i]];
      if (vis[y]) {
        strcpy(yyy.s, t[now][i]);
        yyy.num = nxt[now][i];
        yyy.w = xxx.w + 1;
        q.push(yyy);
      }
    }
  }
  res[1] = s[1].num;
  printf("%d\n", cnt);
  sort(ans + 1, ans + 1 + cnt, cmp);
  for (int i = 1; i <= cnt; i++) printf("%s %d\n", ans[i].s, ans[i].num);
  return 0;
}
