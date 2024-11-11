#include <bits/stdc++.h>
using namespace std;
int head[200005], ver[200005], nxt[200005], cnt;
void add(int a, int b) { ver[++cnt] = b, nxt[cnt] = head[a], head[a] = cnt; }
vector<int> e[200005], has[200005];
int n, m, cd[200005];
long long a[200005], sg[200005];
int pos[200005], mex[200005], mx;
bool vis[200005];
queue<int> q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1, a, b; i <= m; i++) {
    scanf("%d%d", &a, &b);
    add(a, b), e[b].push_back(a), cd[a]++;
  }
  for (int i = 1; i <= n; i++)
    if (!cd[i]) q.push(i);
  while (!q.empty()) {
    int now = q.front();
    q.pop(), cnt = 0;
    for (int i = head[now]; i; i = nxt[i]) mex[++cnt] = pos[ver[i]];
    pos[now] = 1;
    sort(mex + 1, mex + 1 + cnt);
    for (int i = 1; i <= cnt; i++)
      if (mex[i] == pos[now]) pos[now]++;
    sg[pos[now]] ^= a[now];
    has[pos[now]].push_back(now);
    mx = max(mx, pos[now]);
    for (int i = 0; i < e[now].size(); i++) {
      cd[e[now][i]]--;
      if (!cd[e[now][i]]) q.push(e[now][i]);
    }
  }
  for (int o = mx; o >= 1; o--) {
    if (sg[o] != 0) {
      int now;
      for (int i = 0; i < has[o].size(); i++)
        if ((a[has[o][i]] ^ sg[o]) <= a[has[o][i]]) {
          now = has[o][i];
          break;
        }
      a[now] ^= sg[o];
      for (int i = head[now]; i; i = nxt[i]) {
        int to = ver[i];
        if (vis[pos[to]]) continue;
        vis[pos[to]] = 1;
        a[to] = sg[pos[to]] ^ a[to];
      }
      printf("WIN\n");
      for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
      return 0;
    }
  }
  printf("LOSE");
}
