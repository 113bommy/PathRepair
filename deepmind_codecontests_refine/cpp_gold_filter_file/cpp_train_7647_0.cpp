#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > pairs;
long long arr[102];
int is[100002];
vector<long long> pr;
vector<long long> facts[102];
vector<long long> ids[102];
vector<long long> adj[100002];
int vis[100002];
int p[100002];
void sieve() {
  for (long long i = 2; i * i <= 1000000000; i++) {
    if (!is[i]) {
      pr.push_back(i);
      for (long long j = 2 * i; j * j <= 1000000000; j += i) {
        is[j]++;
      }
    }
  }
}
int match(int u) {
  if (vis[u]) return 0;
  vis[u] = 1;
  for (int(i) = (0); (i) < (adj[u].size()); (i)++) {
    int v = adj[u][i];
    if (p[v] == -1 || match(p[v])) {
      p[v] = u;
      return 1;
    }
  }
  return 0;
}
void add(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  sieve();
  int n, m;
  cin >> n >> m;
  for (int(i) = (1); (i) < (n + 1); (i)++) cin >> arr[i];
  for (int(i) = (0); (i) < (m); (i)++) {
    int x, y;
    cin >> x >> y;
    pairs.push_back(make_pair(x, y));
  }
  for (int(i) = (1); (i) < (n + 1); (i)++) {
    long long u = arr[i];
    for (int(j) = (0); (j) < (((int)pr.size())); (j)++) {
      while (u % pr[j] == 0) {
        facts[i].push_back(pr[j]);
        u /= pr[j];
      }
      if (u == 1) break;
    }
    if (u != 1) facts[i].push_back(u);
  }
  int even = 1, odd = 10001;
  for (int(i) = (1); (i) < (n + 1); (i)++) {
    if (i % 2 == 0) {
      for (int(j) = (0); (j) < (((int)facts[i].size())); (j)++) {
        ids[i].push_back(even++);
      }
    } else {
      for (int(j) = (0); (j) < (((int)facts[i].size())); (j)++) {
        ids[i].push_back(odd++);
      }
    }
  }
  for (int(q) = (0); (q) < (((int)pairs.size())); (q)++) {
    int x = pairs[q].first, y = pairs[q].second;
    if (x % 2 == 0) swap(x, y);
    for (int(i) = (0); (i) < (((int)facts[x].size())); (i)++) {
      for (int(j) = (0); (j) < (((int)facts[y].size())); (j)++) {
        if (facts[x][i] == facts[y][j]) {
          add(ids[x][i], ids[y][j]);
        }
      }
    }
  }
  int ans = 0;
  memset(p, -1, sizeof(p));
  for (int(u) = (10001); (u) < (odd); (u)++) {
    memset(vis, 0, sizeof(vis));
    ans += match(u);
  }
  cout << ans << endl;
  return 0;
}
