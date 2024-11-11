#include <bits/stdc++.h>
using namespace std;
struct ed {
  long long from, to, cost, num, n, dep;
};
struct compare {
  bool operator()(struct ed &I, struct ed &C) { return I.n > C.n; }
};
vector<struct ed> con[300001];
vector<long long> con2[300001];
vector<struct ed> v;
long long min_cost[300001];
long long visit[300001];
long long depth[300001];
priority_queue<struct ed, vector<struct ed>, compare> pq;
void dfs(long long cur, long long parent, long long depth);
bool cmp(struct ed a, struct ed b);
int main(void) {
  long long n, m, k, x, y, w, next, tc;
  struct ed I, C;
  scanf("%lld%lld%lld", &n, &m, &k);
  for (long long i = 0; i <= 300000; i++) min_cost[i] = 4000000000000000000LL;
  for (long long i = 0; i < m; i++) {
    scanf("%lld%lld%lld", &x, &y, &w);
    I.to = y;
    I.cost = w;
    I.num = i + 1;
    con[x].push_back(I);
    I.to = x;
    I.cost = w;
    I.num = i + 1;
    con[y].push_back(I);
  }
  I.from = -1;
  I.to = 1;
  I.n = 0;
  min_cost[1] = 0;
  pq.push(I);
  while (!pq.empty()) {
    C = pq.top();
    pq.pop();
    if (visit[C.to]) continue;
    visit[C.to] = 1;
    if (C.from != -1) v.push_back(C);
    for (long long i = 0; i < con[C.to].size(); i++) {
      next = con[C.to][i].to;
      tc = C.n + con[C.to][i].cost;
      if (tc < min_cost[next]) {
        I.from = C.to;
        I.to = next;
        I.n = tc;
        I.num = con[C.to][i].num;
        min_cost[next] = tc;
        pq.push(I);
      }
    }
  }
  for (long long i = 0; i < v.size(); i++) {
    con2[v[i].from].push_back(v[i].to);
    con2[v[i].to].push_back(v[i].from);
  }
  dfs(1, -1, 0);
  if (v.size() <= k) {
    printf("%lld\n", v.size());
    for (long long i = 0; i < v.size(); i++) {
      if (i != v.size() - 1)
        printf("%lld ", v[i].num);
      else
        printf("%lld", v[i].num);
    }
  } else {
    for (long long i = 0; i < v.size(); i++)
      v[i].dep = max(depth[v[i].from], depth[v[i].to]);
    sort(v.begin(), v.end(), cmp);
    printf("%lld\n", k);
    for (long long i = 0; i < k; i++) {
      if (i != k - 1)
        printf("%lld ", v[i].num);
      else
        printf("%lld", v[i].num);
    }
  }
}
void dfs(long long cur, long long parent, long long dep) {
  depth[cur] = dep;
  for (long long i = 0; i < con2[cur].size(); i++) {
    if (con2[cur][i] == parent) continue;
    dfs(con2[cur][i], cur, dep + 1);
  }
}
bool cmp(struct ed a, struct ed b) { return a.dep < b.dep; }
