#include <bits/stdc++.h>
using namespace std;
const int SIZ = 10000;
int N;
char buf[SIZ];
int val[SIZ];
int cnt[26];
int gpos, letter[26], _pair[SIZ];
struct tgno {
  int u, v, c, w, f;
  tgno* n;
  tgno* r;
} POOL[SIZ << 1], *Head[SIZ];
int ppos;
void addEdge(int u, int v, int c, int w) {
  int a = ppos, b = ppos + 1;
  ppos += 2;
  POOL[a] = tgno{u, v, c, w, 0, NULL, NULL};
  POOL[b] = tgno{v, u, 0, -w, 0, NULL, NULL};
  POOL[a].n = Head[u];
  Head[u] = &POOL[a];
  POOL[b].n = Head[v];
  Head[v] = &POOL[b];
  POOL[a].r = &POOL[b];
  POOL[b].r = &POOL[a];
}
const int _inf = 0x3f3f3f3f;
int Flow, Cost;
int vis[SIZ], dis[SIZ], adv[SIZ];
tgno* pre[SIZ];
bool SPFA(int s, int t) {
  fill(dis, dis + SIZ, _inf);
  fill(pre, pre + SIZ, (tgno*)NULL);
  fill(vis, vis + SIZ, 0x00);
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  vis[s] = true;
  adv[s] = _inf;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (tgno* i = Head[u]; i; i = i->n) {
      if (i->c > i->f && dis[i->v] > dis[u] + i->w) {
        dis[i->v] = dis[u] + i->w;
        adv[i->v] = min(adv[u], i->c - i->f);
        pre[i->v] = i;
        if (!vis[i->v]) {
          q.push(i->v);
          vis[i->v] = true;
        }
      }
    }
  }
  if (dis[t] == _inf)
    return false;
  else {
    Flow += adv[t];
    Cost += dis[t] * adv[t];
    int u = t;
    while (u != s) {
      pre[u]->f += adv[t];
      pre[u]->r->f -= adv[t];
      u = pre[u]->u;
    }
    return true;
  }
}
void MaxFlow(int s, int t) {
  Flow = Cost = 0;
  while (SPFA(s, t))
    ;
}
int main() {
  scanf("%d", &N);
  scanf("%s", buf);
  for (int i = 0; i < N; i++) scanf("%d", &val[i]);
  for (int i = 0; i < N; i++) cnt[buf[i] - 'a']++;
  int S = ++gpos;
  int T = ++gpos;
  for (int i = 0; i < 26; i++) letter[i] = ++gpos;
  for (int i = 0; i < 26; i++) {
    addEdge(S, letter[i], cnt[i], 0);
  }
  int _ = N >> 1;
  for (int i = 0; i < _; i++) {
    _pair[i] = ++gpos;
    int c1 = buf[i] - 'a';
    int c2 = buf[N - i - 1] - 'a';
    int v1 = val[i];
    int v2 = val[N - i - 1];
    for (int j = 0; j < 26; j++) {
      int vv = 0;
      if (j == c1) vv = -v1;
      if (j == c2) vv = min(vv, -v2);
      addEdge(letter[j], _pair[i], 1, vv);
    }
    addEdge(_pair[i], T, 2, 0);
  }
  MaxFlow(S, T);
  printf("%d\n", -Cost);
}
