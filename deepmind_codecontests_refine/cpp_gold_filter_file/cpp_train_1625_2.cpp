#include <bits/stdc++.h>
using namespace std;
vector<int> con[200000];
int gender[200000];
int n;
bool cyc[200000];
long long val[200000][2];
long long doit(int x, int taken, int p) {
  long long& res = val[x][taken];
  if (res != -1) return res;
  int i, a;
  vector<long long> c;
  for (i = 0; i < con[x].size(); i++) {
    a = con[x][i];
    if (cyc[a]) continue;
    if (a == p) continue;
    c.push_back(a);
  }
  if (c.empty()) return res = 0;
  long long none = 0;
  for (i = 0; i < c.size(); i++) none += doit(c[i], 0, x);
  res = none;
  long long tx;
  if (!taken) {
    for (i = 0; i < c.size(); i++) {
      tx = none - doit(c[i], 0, x);
      tx += 1000000;
      if (gender[x] != gender[c[i]]) tx++;
      tx += doit(c[i], 1, x);
      if (tx > res) res = tx;
    }
  }
  return res;
}
int q[200000];
int nq;
bool qd[200000];
int sisa[200000];
void init() {
  memset(qd, 0, sizeof(qd));
  nq = 0;
  int i, j, a;
  for (i = 0; i < n; i++) sisa[i] = con[i].size();
  for (i = 0; i < n; i++)
    if (sisa[i] == 1) {
      q[nq++] = i;
      qd[i] = true;
    }
  int it;
  for (it = 0; it < nq; it++) {
    int cur = q[it];
    for (i = 0; i < con[cur].size(); i++) {
      a = con[cur][i];
      if (qd[a]) continue;
      sisa[a]--;
      if (sisa[a] == 1) {
        q[nq++] = a;
        qd[a] = true;
      }
    }
  }
  memset(cyc, 0, sizeof(cyc));
  for (i = 0; i < n; i++)
    if (!qd[i]) cyc[i] = true;
}
bool used[200000];
vector<int> nodes;
long long dp[200000][2];
void dfs(int x) {
  nodes.push_back(x);
  used[x] = true;
  int i, a;
  for (i = 0; i < con[x].size(); i++) {
    a = con[x][i];
    if (!used[a] && cyc[a]) dfs(a);
  }
}
long long doit2(int id, int ctail) {
  if (id >= nodes.size() - ctail) return 0;
  long long& res = dp[nodes[id]][ctail];
  if (res != -1) return res;
  res = doit2(id + 1, ctail) + val[nodes[id]][0];
  if (id < nodes.size() - ctail - 1) {
    long long tmp = 1000000 + doit2(id + 2, ctail);
    tmp += val[nodes[id]][1];
    tmp += val[nodes[id + 1]][1];
    if (gender[nodes[id]] != gender[nodes[id + 1]]) tmp++;
    if (tmp > res) res = tmp;
  }
  return res;
}
vector<pair<int, int> > the_pairs;
void trace(int x, int taken, int p) {
  long long res = val[x][taken];
  int i, a;
  vector<long long> c;
  for (i = 0; i < con[x].size(); i++) {
    a = con[x][i];
    if (cyc[a]) continue;
    if (a == p) continue;
    c.push_back(a);
  }
  if (c.empty()) return;
  long long none = 0;
  for (i = 0; i < c.size(); i++) none += doit(c[i], 0, x);
  if (res == none) {
    for (i = 0; i < c.size(); i++) trace(c[i], 0, x);
    return;
  }
  long long tx;
  for (i = 0; i < c.size(); i++) {
    tx = none - doit(c[i], 0, x);
    tx += 1000000;
    if (gender[x] != gender[c[i]]) tx++;
    tx += doit(c[i], 1, x);
    if (tx == res) break;
  }
  int cc = i;
  the_pairs.push_back(pair<int, int>(x, c[cc]));
  trace(c[cc], 1, x);
  for (i = 0; i < c.size(); i++)
    if (i != cc) trace(c[i], 0, x);
}
void trace2(int id, int ctail) {
  if (id >= nodes.size() - ctail) return;
  long long res = dp[nodes[id]][ctail];
  if (res == doit2(id + 1, ctail) + val[nodes[id]][0]) {
    trace2(id + 1, ctail);
    trace(nodes[id], 0, -1);
  } else {
    trace2(id + 2, ctail);
    trace(nodes[id], 1, -1);
    trace(nodes[id + 1], 1, -1);
    the_pairs.push_back(pair<int, int>(nodes[id], nodes[id + 1]));
  }
}
long long solve_cyc() {
  memset(used, 0, sizeof(used));
  memset(dp, -1, sizeof(dp));
  int i;
  long long res = 0;
  for (i = 0; i < n; i++)
    if (cyc[i] && !used[i]) {
      nodes.clear();
      dfs(i);
      long long v1 = doit2(0, 0);
      long long v2 = 1000000 + doit2(1, 1);
      if (gender[i] != gender[nodes.back()]) v2++;
      v2 += val[i][1] + val[nodes.back()][1];
      if (v1 >= v2) {
        res += v1;
        trace2(0, 0);
      } else {
        res += v2;
        the_pairs.push_back(pair<int, int>(i, nodes.back()));
        trace2(1, 1);
        trace(i, 1, -1);
        trace(nodes.back(), 1, -1);
      }
    }
  return res;
}
int main() {
  scanf("%d", &n);
  int i;
  int a, b;
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &gender[i]);
    a--;
    con[i].push_back(a);
    con[a].push_back(i);
  }
  init();
  memset(val, -1, sizeof(val));
  for (i = 0; i < n; i++)
    if (cyc[i]) {
      val[i][0] = doit(i, 0, -1);
      val[i][1] = doit(i, 1, -1);
    }
  the_pairs.clear();
  long long res = solve_cyc();
  printf("%lld %lld\n", res / 1000000, res % 1000000);
  for (i = 0; i < the_pairs.size(); i++) {
    printf("%d %d\n", the_pairs[i].first + 1, the_pairs[i].second + 1);
  }
}
