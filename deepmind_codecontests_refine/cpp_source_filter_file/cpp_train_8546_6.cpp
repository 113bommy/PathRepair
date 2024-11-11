#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long en, cap, flow, next;
} edge[1000000];
long long head[50005], tot, now[50005];
long long source, sink, tot_num;
long long pre[50005], dis[50005], gap[50005];
void add_edge(long long st, long long en, long long cap) {
  edge[tot].en = en;
  edge[tot].cap = cap;
  edge[tot].flow = 0;
  edge[tot].next = head[st];
  head[st] = tot++;
  edge[tot].en = st;
  edge[tot].cap = 0;
  edge[tot].flow = 0;
  edge[tot].next = head[en];
  head[en] = tot++;
}
void augment(long long flow) {
  for (long long i = source; i != sink; i = edge[now[i]].en) {
    edge[now[i]].flow += flow;
    edge[now[i] ^ 1].flow -= flow;
  }
}
long long sap() {
  memset(dis, 0, sizeof(dis));
  memset(gap, 0, sizeof(gap));
  memset(pre, -1, sizeof(pre));
  for (long long i = 0; i < tot_num; i++) now[i] = head[i];
  gap[0] = tot_num;
  long long poLL = source, flow = 0, min_flow = 0x3fffffff;
  while (dis[source] < tot_num) {
    bool fg = false;
    for (long long i = now[poLL]; i != -1; i = edge[i].next)
      if (edge[i].cap - edge[i].flow > 0 && dis[poLL] == dis[edge[i].en] + 1) {
        min_flow = min(min_flow, edge[i].cap - edge[i].flow);
        now[poLL] = i;
        pre[edge[i].en] = poLL;
        poLL = edge[i].en;
        if (poLL == sink) {
          flow += min_flow;
          augment(min_flow);
          poLL = source;
          min_flow = 0x3fffffff;
        }
        fg = true;
        break;
      }
    if (fg) continue;
    if (--gap[dis[poLL]] == 0) break;
    long long Min = tot_num;
    for (long long i = head[poLL]; i != -1; i = edge[i].next)
      if (edge[i].cap - edge[i].flow > 0 && Min > dis[edge[i].en]) {
        Min = dis[edge[i].en];
        now[poLL] = i;
      }
    gap[dis[poLL] = Min + 1]++;
    if (poLL != source) poLL = pre[poLL];
  }
  return flow;
}
long long sum;
void build(long long n) {
  memset(head, -1, sizeof(head));
  tot = 0;
  source = 0;
  sink = n * 2 + 1;
  tot_num = n * 2 + 2;
  long long a, b, c;
  long long m;
  long long j;
  for (long long i = 1; i <= n; i++)
    for (j = 1, cin >> m; j <= m; j++) {
      cin >> a;
      add_edge(i, n + a, 5 * 0x3fffffff);
    }
  sum = 0;
  for (long long i = 1; i <= n; i++) {
    add_edge(n + i, sink, 0x3fffffff);
    cin >> a;
    sum += a;
    add_edge(source, i, 0x3fffffff - a);
  }
}
int main() {
  long long n, m;
  while (cin >> n) {
    build(n);
    long long ans = sap();
    cout << sum + ans - n * 0x3fffffff << endl;
  }
  return 0;
}
