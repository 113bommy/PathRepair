#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > adj[200005];
int d[200005], s[200005];
long long w[200005], dep[200005], pred[200005], sufd[200005], pref[200005],
    suff[200005], sum[200005];
vector<int> cycle;
int vn, sn, cn;
stack<int> st;
int dfs(int now, int par) {
  int ret = d[now] = vn++;
  st.push(now);
  for (int i = 0; i < adj[now].size(); i++) {
    int there = adj[now][i].first;
    if (there == par) continue;
    if (d[there] == -1)
      ret = min(ret, dfs(there, now));
    else if (s[there] == -1)
      ret = min(ret, d[there]);
  }
  if (ret == d[now]) {
    vector<int> vec;
    while (true) {
      int temp = st.top();
      st.pop();
      s[temp] = sn;
      vec.push_back(temp);
      if (temp == now) break;
    }
    sn++;
    if (vec.size() > 1) cycle = vec;
  }
  return ret;
}
void dfs2(int now, int next, int idx) {
  if (d[now] != 1) return;
  d[now] = 0;
  for (int i = 0; i < adj[now].size(); i++) {
    int there = adj[now][i].first;
    int weight = adj[now][i].second;
    if (there == next) {
      w[idx] = weight;
      dfs2(there, cycle[(idx + 2) % cn], idx + 1);
    }
  }
}
int u, v;
pair<long long, int> dfs3(int now, int par) {
  pair<long long, int> ret = {0, now};
  for (int i = 0; i < adj[now].size(); i++) {
    int there = adj[now][i].first;
    int weight = adj[now][i].second;
    if (there == par || d[there] != -1) continue;
    if ((now == u && there == v) || (now == v && there == u)) continue;
    auto temp = dfs3(there, now);
    temp.first += weight;
    ret = max(ret, temp);
  }
  return ret;
}
const long long inf = 0x3f3f3f3f3f3f3f3f;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    adj[a].push_back({b, d});
    adj[b].push_back({a, d});
  }
  memset(d, -1, sizeof(d));
  memset(s, -1, sizeof(s));
  for (int i = 1; i <= n; i++)
    if (d[i] == -1) dfs(i, 0);
  cn = cycle.size();
  memset(d, -1, sizeof(d));
  for (int i = 0; i < cn; i++) d[cycle[i]] = 1;
  dfs2(cycle[0], cycle[1], 0);
  for (int i = 0; i < cn; i++) dep[i] = dfs3(cycle[i], 0).first;
  for (int i = 0; i <= cn; i++) {
    pred[i] = sufd[i] = pref[i] = suff[i] = -inf;
    if (i == 0)
      sum[i] = w[i];
    else if (i < cn)
      sum[i] = sum[i - 1] + w[i];
  }
  long long cf = -inf;
  for (int i = 0; i < cn; i++) {
    if (i == 0) {
      pred[i] = 0;
      pref[i] = dep[i];
    } else {
      cf = max(cf, dep[i - 1]) + w[i - 1];
      pred[i] = max(pred[i - 1], cf + dep[i]);
      pref[i] = max(pref[i - 1], sum[i - 1] + dep[i]);
    }
  }
  cf = 0;
  for (int i = cn - 1; i > 0; i--) {
    if (i != cn - 1) cf = max(cf, dep[i + 1]) + w[i];
    sufd[i] = max(sufd[i + 1], cf + dep[i]);
    suff[i] = max(suff[i + 1], sum[cn - 1] - sum[i - 1] + dep[i]);
  }
  long long min_value = inf;
  int min_idx = -1;
  for (int i = 0; i < cn; i++) {
    long long now = max({pref[i] + suff[i + 1], pred[i], suff[i + 1]});
    if (now < min_value) {
      min_value = now;
      min_idx = i;
    }
  }
  u = cycle[min_idx];
  v = cycle[(min_idx + 1) % cn];
  memset(d, -1, sizeof(d));
  int root = dfs3(1, 0).second;
  long long ans = dfs3(root, 0).first;
  printf("%lld\n", ans);
  return 0;
}
