#include <bits/stdc++.h>
using namespace std;
long long head[400005], ver[400005], nxt[400005], cnt;
void add(long long a, long long b) {
  ver[++cnt] = b, nxt[cnt] = head[a], head[a] = cnt;
}
vector<long long> e[400005], has[400005];
long long n, m, cd[400005];
long long a[400005], sg[400005];
long long pos[400005], mex[400005], mx;
bool vis[400005];
queue<long long> q, ans;
int main() {
  scanf("%d%d", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1, a, b; i <= m; i++) {
    scanf("%d%d", &a, &b);
    add(a, b), e[b].push_back(a), cd[a]++;
  }
  for (long long i = 1; i <= n; i++)
    if (!cd[i]) q.push(i);
  while (!q.empty()) {
    long long now = q.front();
    q.pop(), cnt = 0;
    for (long long i = head[now]; i; i = nxt[i]) mex[++cnt] = pos[ver[i]];
    pos[now] = 1;
    sort(mex + 1, mex + 1 + cnt);
    for (long long i = 1; i <= cnt; i++)
      if (mex[i] == pos[now]) pos[now]++;
    sg[pos[now]] ^= a[now];
    has[pos[now]].push_back(now);
    mx = max(mx, pos[now]);
    for (long long i = 0; i < e[now].size(); i++) {
      cd[e[now][i]]--;
      if (!cd[e[now][i]]) q.push(e[now][i]);
    }
  }
  for (long long o = mx; o >= 1; o--) {
    if (sg[o] != 0) {
      long long now;
      for (long long i = 0; i < has[o].size(); i++)
        if ((a[has[o][i]] ^ sg[o]) <= a[has[o][i]]) {
          now = has[o][i];
          break;
        }
      a[now] ^= sg[o];
      for (long long i = head[now]; i; i = nxt[i]) {
        long long to = ver[i];
        if (vis[pos[to]]) continue;
        vis[pos[to]] = 1;
        a[to] = sg[pos[to]] ^ a[to];
      }
      printf("WIN\n");
      for (long long i = 1; i <= n; i++) printf("%lld ", a[i]);
      return 0;
    }
  }
  printf("LOSE");
}
