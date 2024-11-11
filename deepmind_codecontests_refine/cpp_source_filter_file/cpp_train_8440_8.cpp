#include <bits/stdc++.h>
using namespace std;
vector<long long> graph[300000];
vector<bool> used(300000, 0);
vector<long long> to(300000);
vector<long long> fup(300000);
vector<long long> dsu(300000);
vector<long long> rnk(300000, 1);
long long ans = 0;
long long N = 1e9;
long long node = 0;
long long getdsu(long long v) {
  if (dsu[v] == v) return v;
  return dsu[v] = getdsu(dsu[v]);
}
void merge(long long vl, long long vr) {
  vl = getdsu(vl);
  vr = getdsu(vr);
  if (vl == vr) return;
  if (rnk[vl] < rnk[vr]) {
    rnk[vr] += rnk[vl];
    dsu[vl] = vr;
  } else {
    rnk[vl] += rnk[vr];
    dsu[vr] = vl;
  }
}
long long t = 0;
vector<pair<long long, long long> > bridge;
vector<long long> degraph[300000];
void dfs(long long v, long long p) {
  used[v] = 1;
  t++;
  to[v] = t;
  fup[v] = t;
  for (int i = 0; i < graph[v].size(); i++) {
    long long too = graph[v][i];
    if (too == p) continue;
    if (used[too]) {
      fup[v] = min(fup[v], to[too]);
    } else {
      dfs(too, v);
      fup[v] = min(fup[v], fup[too]);
      if (fup[v] < fup[too]) {
        bridge.push_back({v, too});
      } else {
        merge(v, too);
      }
    }
  }
}
void bfs(long long v) {
  queue<long long> q;
  q.push(v);
  vector<long long> len(300000, N);
  vector<bool> used1(300000, 0);
  len[v] = 0;
  while (!q.empty()) {
    long long r = q.front();
    q.pop();
    used1[r] = 1;
    for (int i = 0; i < degraph[r].size(); i++) {
      long long too = degraph[r][i];
      if (!used1[too]) {
        if (len[too] > len[r] + 1) {
          len[too] = len[r] + 1;
          q.push(too);
        }
      }
    }
  }
  for (int i = 0; i < 300000; i++)
    if (len[i] != N) {
      if (ans < len[i]) {
        ans = len[i];
        node = i;
      }
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long b, c, d, i, l, r, k;
  cin >> b >> c;
  for (i = 0; i < b; i++) {
    dsu[i] = i;
  }
  for (i = 0; i < c; i++) {
    cin >> l >> r;
    l--;
    r--;
    graph[l].push_back(r);
    graph[r].push_back(l);
  }
  dfs(0, -1);
  long long start;
  if (bridge.empty()) {
    cout << 0;
    return 0;
  }
  for (i = 0; i < bridge.size(); i++) {
    pair<long long, long long> pn = bridge[i];
    l = pn.first;
    r = pn.second;
    l = getdsu(l);
    r = getdsu(r);
    if (l != r) {
      start = l;
      degraph[l].push_back(r);
      degraph[r].push_back(l);
    }
  }
  bfs(start);
  bfs(node);
  cout << ans;
  return 0;
}
