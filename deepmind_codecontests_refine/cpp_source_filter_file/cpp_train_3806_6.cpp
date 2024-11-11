#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
struct edge {
  int s, t, i;
  long long w;
  edge(int s, int t, int w, int i) : s(s), t(t), w(w), i(i) {}
};
vector<edge> g[1000];
vector<edge> eg;
long long dist[1000];
set<int> de[1000];
int n, s, t, L;
long long dijk(long long tw) {
  for (int i = 0; i < n; i++) {
    dist[i] = inf;
    de[i].clear();
  }
  dist[s] = 0;
  priority_queue<pair<long long, pair<int, int>>> pq;
  for (edge e : g[s]) {
    if (e.w) {
      dist[e.t] = e.w;
      pq.push({-e.w, {e.t, s}});
    } else {
      dist[e.t] = tw;
      de[e.t].insert(e.i);
      pq.push({-tw, {e.t, s}});
    }
  }
  while (!pq.empty()) {
    long long w = -pq.top().first;
    int cur = pq.top().second.first;
    int par = pq.top().second.second;
    pq.pop();
    if (w != dist[cur]) continue;
    if (w > dist[t]) return dist[t];
    for (edge e : g[cur]) {
      long long w2 = e.w + w;
      if (!e.w) w2 += tw;
      if ((e.t != t && w2 >= dist[e.t]) || (e.t == t && w2 > dist[e.t]))
        continue;
      if (e.t == t) {
        if (w2 < L)
          return w2;
        else if (w2 > L && !(de[cur].size() + !e.w))
          continue;
      }
      de[e.t].clear();
      de[e.t].insert(de[cur].begin(), de[cur].end());
      if (!e.w) {
        de[e.t].insert(e.i);
      }
      dist[e.t] = w2;
      pq.push({-w2, {e.t, cur}});
    }
  }
  return dist[t];
}
int main() {
  int m;
  scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    int idx = eg.size();
    eg.push_back(edge(a, b, w, idx));
    g[a].push_back(edge(a, b, w, idx));
    g[b].push_back(edge(b, a, w, idx));
  }
  long long l = 1, r = 1e9;
  while (r >= l) {
    long long c = (l + r) >> 1;
    long long sp = dijk(c);
    if (sp == L) {
      puts("YES");
      for (edge e : eg) {
        printf("%d %d %lld\n", e.s, e.t, e.w ? e.w : c);
      }
      return 0;
    }
    if (sp > L) {
      if (sp - de[t].size() * (c - 1) < L) {
        long long diff = sp - L;
        puts("YES");
        for (edge e : eg) {
          if (e.w) {
            printf("%d %d %lld\n", e.s, e.t, e.w);
          } else if (de[t].find(e.i) == de[t].end()) {
            printf("%d %d %lld\n", e.s, e.t, c);
          } else if (diff) {
            if (c < diff) {
              printf("%d %d 1\n", e.s, e.t);
              diff -= c - 1;
            } else {
              printf("%d %d %lld\n", e.s, e.t, c - diff);
              diff = 0;
            }
          } else {
            printf("%d %d %lld\n", e.s, e.t, c);
          }
        }
        return 0;
      } else
        r = c - 1;
    } else {
      l = c + 1;
    }
  }
  puts("NO");
}
