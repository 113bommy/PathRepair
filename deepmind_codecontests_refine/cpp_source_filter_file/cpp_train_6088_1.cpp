#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n;
char s1[maxn], s2[maxn];
int dn;
map<string, int> mp;
vector<int> edge[maxn];
void standard(char s[]) {
  int len = strlen(s);
  for (int i = 0; i < len; i++)
    if (s[i] >= 'a') s[i] += 'A' - 'a';
}
int getid(string s) {
  if (mp.count(s) > 0) {
    return mp[s];
  } else {
    dn++;
    mp[s] = dn;
    return dn;
  }
}
queue<int> que;
int ans[maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    dn = 0;
    mp.clear();
    for (int i = 1; i <= n; i++) edge[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%s%s%s", s1, s2, s2);
      standard(s1);
      standard(s2);
      int u = getid(s1);
      int v = getid(s2);
      edge[v].push_back(u);
    }
    while (!que.empty()) que.pop();
    memset(ans, -1, sizeof(ans));
    int st = getid("POLYCARP");
    ans[st] = 1;
    que.push(st);
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (int i = 0; i < edge[x].size(); i++) {
        int to = edge[x][i];
        ans[to] = ans[x] + 1;
        que.push(to);
      }
    }
    int res = -1;
    for (int i = 1; i <= n; i++) res = max(res, ans[i]);
    printf("%d\n", res);
  }
  return 0;
}
