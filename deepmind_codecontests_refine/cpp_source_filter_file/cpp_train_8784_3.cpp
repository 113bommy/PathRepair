#include <bits/stdc++.h>
inline long long Get() {
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  long long Num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    Num = (Num << 3) + (Num << 1) + ch - '0';
  return Num;
}
const int N = 4e5 + 5;
const long long inf = 1e18 + 1;
int n, m, nK, val[N], tot, first[N], next[N], end[N];
long long H, pos[N], dist[N], cap[N];
std ::priority_queue<std ::pair<int, int> > Q, Del;
std ::priority_queue<std ::pair<long long, int>,
                     std ::vector<std ::pair<long long, int> >,
                     std ::greater<std ::pair<long long, int> > >
    que;
void addEdge(int x, int y, long long w) {
  next[++tot] = first[x], first[x] = tot, end[tot] = y, cap[tot] = w;
}
void Dijkstra() {
  while (!que.empty()) {
    std ::pair<long long, int> now = que.top();
    que.pop();
    int x = now.second;
    long long res = now.first;
    if (dist[x] != res) continue;
    for (int k = first[x], y; y = end[k], k; k = next[k])
      if (dist[y] > dist[x] + cap[k])
        que.push(std ::make_pair(dist[y] = dist[x] + cap[k], y));
  }
}
int main() {
  H = Get(), n = Get(), m = Get(), nK = Get();
  for (int i = 1; i <= n; ++i) pos[i] = Get(), val[i] = Get();
  for (int i = 0; i < nK; ++i) dist[i] = inf;
  dist[1 % nK] = 1;
  for (int i = 1; i <= n; ++i)
    if (dist[pos[i] % nK] <= pos[i]) Q.push(std ::make_pair(val[i], i));
  while (m--) {
    int type = Get();
    if (type == 1) {
      long long x = Get();
      for (int i = 0; i < nK; ++i) addEdge(i, (x + i) % nK, x);
      for (int i = 0; i < nK; ++i) que.push(std ::make_pair(dist[i], i));
      Dijkstra();
      while (!Q.empty()) Q.pop();
      while (!Del.empty()) Del.pop();
      for (int i = 1; i <= n; ++i)
        if (dist[pos[i] % nK] <= pos[i]) Q.push(std ::make_pair(val[i], i));
      continue;
    }
    if (type == 2) {
      int x = Get(), y = Get();
      if (dist[pos[x] % nK] <= pos[x])
        Del.push(std ::make_pair(val[x], x)),
            Q.push(std ::make_pair(val[x] - y, x));
      val[x] -= y;
      continue;
    }
    while (!Del.empty() && Q.top() == Del.top()) Q.pop(), Del.pop();
    if (Q.empty()) {
      puts("0");
      continue;
    }
    std ::pair<int, int> now = Q.top();
    Q.pop();
    printf("%d\n", now.first);
    val[now.second] = 0;
  }
}
