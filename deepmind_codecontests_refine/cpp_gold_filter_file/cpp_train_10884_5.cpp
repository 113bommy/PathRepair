#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n, m;
long long rr, bb;
pair<long long, long long> point[N];
map<long long, long long> num;
vector<pair<long long, long long>> x[N], y[N];
long long NUM, gdz[N];
pair<long long, pair<long long, long long>> glupstwo[N];
pair<long long, long long> male_x[N], male_y[N];
long long kolor[N];
vector<long long> kraw[N];
void dfs(long long v, long long ko) {
  kolor[v] = ko;
  for (auto u : kraw[v])
    if (kolor[u] == 0) dfs(u, -ko);
}
vector<pair<long long, pair<long long, long long>>> adj[N];
long long dist[N], beg[N];
bool bfs(long long s, long long t) {
  for (long long i = 0; i <= 2 * NUM + 1; ++i) dist[i] = 1e18;
  dist[s] = 0;
  queue<long long> Q;
  Q.push(s);
  while (!Q.empty()) {
    long long u = Q.front();
    Q.pop();
    for (auto v : adj[u])
      if (v.second.first > 0 && dist[v.first] == 1e18) {
        dist[v.first] = dist[u] + 1;
        Q.push(v.first);
      }
  }
  return dist[t] != 1e18;
}
long long dfs(long long v, long long t, long long max_cap) {
  if (v == t || max_cap == 0) return max_cap;
  long long res = 0;
  for (long long &i = beg[v]; i < (long long)adj[v].size(); ++i) {
    long long u = adj[v][i].first, cap = adj[v][i].second.first,
              odwr = adj[v][i].second.second;
    if (cap > 0 && dist[u] == dist[v] + 1) {
      long long xx = dfs(u, t, min(max_cap, cap));
      adj[v][i].second.first -= xx;
      adj[u][odwr].second.first += xx;
      res += xx;
      max_cap -= xx;
    }
  }
  return res;
}
long long maxflow(long long s, long long t) {
  long long res = 0;
  while (bfs(s, t)) {
    for (long long i = 0; i <= 2 * NUM + 1; ++i) beg[i] = 0;
    res += dfs(s, t, 1e18);
  }
  return res;
}
void addedge(long long u, long long v, long long c1, long long c2) {
  adj[u].push_back(make_pair(v, make_pair(c1, -1)));
  adj[v].push_back(make_pair(u, make_pair(c2, -1)));
  adj[u].back().second.second = adj[v].size() - 1;
  adj[v].back().second.second = adj[u].size() - 1;
}
int32_t main() {
  scanf("%lld%lld%lld%lld", &n, &m, &rr, &bb);
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld%lld", &point[i].first, &point[i].second);
    num[point[i].first] = -1;
    num[point[i].second] = -1;
  }
  for (auto s : num) num[s.first] = ++NUM;
  for (long long i = 1; i <= n; ++i) {
    x[num[point[i].first]].push_back(make_pair(num[point[i].second], i));
    y[num[point[i].second]].push_back(make_pair(num[point[i].first], i));
  }
  for (long long i = 1; i <= NUM; ++i) {
    for (long long j = 0; j < (long long)x[i].size() - 1; j += 2) {
      long long a = x[i][j].second, b = x[i][j + 1].second;
      kraw[a].push_back(b);
      kraw[b].push_back(a);
    }
    for (long long j = 0; j < (long long)y[i].size() - 1; j += 2) {
      long long a = y[i][j].second, b = y[i][j + 1].second;
      kraw[a].push_back(b);
      kraw[b].push_back(a);
    }
  }
  for (long long i = 1; i <= n; ++i)
    if (!kolor[i]) dfs(i, 1);
  for (long long i = 1; i <= NUM; ++i) male_x[i] = male_y[i] = {1e18, 1e18};
  for (long long i = 1; i <= m; ++i) {
    long long t, l, d;
    scanf("%lld%lld%lld", &t, &l, &d);
    glupstwo[i].first = t;
    glupstwo[i].second.first = l;
    glupstwo[i].second.second = d;
    if (t == 1) male_x[num[l]] = min(male_x[num[l]], make_pair(d, i));
    if (t == 2) male_y[num[l]] = min(male_y[num[l]], make_pair(d, i));
  }
  for (long long i = 1; i <= m; ++i) {
    long long t = glupstwo[i].first;
    long long l = glupstwo[i].second.first;
    long long d = glupstwo[i].second.second;
    if (t == 1 && male_x[num[l]].second == i) {
      long long ile_wybralem = 0;
      for (auto s : x[num[l]])
        if (kolor[s.second] == 1) ++ile_wybralem;
      long long xx = x[num[l]].size();
      if (xx % 2 != 0 && d == 0) {
        printf("-1\n");
        return 0;
      }
      long long L = ((xx - d) / 2 + (xx - d) % 2), R = (d + xx) / 2;
      addedge(0, num[l], R - ile_wybralem, ile_wybralem - L);
    }
    if (t == 2 && male_y[num[l]].second == i) {
      long long ile_wybralem = 0;
      for (auto s : y[num[l]])
        if (kolor[s.second] == 1) ++ile_wybralem;
      long long xx = y[num[l]].size();
      if (xx % 2 != 0 && d == 0) {
        printf("-1\n");
        return 0;
      }
      long long L = ((xx - d) / 2 + (xx - d) % 2), R = (d + xx) / 2;
      addedge(num[l] + NUM, 2 * NUM + 1, R - ile_wybralem, ile_wybralem - L);
    }
  }
  for (long long i = 1; i <= NUM; ++i) {
    if (male_x[i].first == 1e18) {
      addedge(0, i, 1e18, 1e18);
    }
    if (male_y[i].first == 1e18) {
      addedge(i + NUM, 2 * NUM + 1, 1e18, 1e18);
    }
  }
  for (long long i = 1; i <= NUM; ++i) gdz[i] = adj[i].size();
  for (long long i = 1; i <= n; ++i) {
    if (kolor[i] == -1) {
      addedge(num[point[i].first], num[point[i].second] + NUM, 1, 0);
    } else {
      addedge(num[point[i].first], num[point[i].second] + NUM, 0, 1);
    }
  }
  maxflow(0, 2 * NUM + 1);
  long long wyb = 0;
  for (long long i = 1; i <= n; ++i) {
    if (kolor[i] == -1) {
      if (adj[num[point[i].first]][gdz[num[point[i].first]]++].second.first ==
          1)
        kolor[i] *= -1;
    } else {
      if (adj[num[point[i].first]][gdz[num[point[i].first]]++].second.first ==
          0)
        kolor[i] *= -1;
    }
    if (kolor[i] == 1) ++wyb;
  }
  if (wyb * 2 > n) {
    for (long long i = 1; i <= n; ++i) kolor[i] *= -1;
    wyb = n - wyb;
  }
  printf("%lld\n",
         min(rr, bb) * max(wyb, n - wyb) + max(rr, bb) * min(wyb, n - wyb));
  if (rr < bb) {
    for (long long i = 1; i <= n; ++i) putchar(kolor[i] == 1 ? 'b' : 'r');
  } else {
    for (long long i = 1; i <= n; ++i) putchar(kolor[i] == 1 ? 'r' : 'b');
  }
  printf("\n");
  return 0;
}
