#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int in[1000009], out[1000009], TIM, id[1000009], par[1000009];
pair<int, int> adj[1000009][2];
vector<pair<int, long long> > add[1000009], rem[1000009];
long long cost[1000009], ans[1000009];
void dfs(int nd) {
  in[nd] = ++TIM;
  id[TIM] = nd;
  for (int i = 0; i < 2; i++)
    if (adj[nd][i].first) {
      cost[adj[nd][i].first] = cost[nd] + adj[nd][i].second;
      dfs(adj[nd][i].first);
    }
  out[nd] = TIM;
}
pair<int, int> F[1000009];
void query(int ind, int l, int r, long long val) {
  if (l > r) return;
  add[l].push_back(make_pair(ind, val));
  rem[r].push_back(make_pair(ind, val));
}
void upd(int x, long long val) {
  for (; x < 1000009; x += x & (-x))
    F[x] = make_pair(F[x].first + 1, F[x].second + val);
}
pair<int, long long> get(int x) {
  pair<int, long long> res = make_pair(0, 0);
  for (; x; x -= x & (-x))
    res = make_pair(res.first + F[x].first, res.second + F[x].second);
  return res;
}
vector<long long> vec;
int jumbo(long long x) {
  return upper_bound(vec.begin(), vec.end(), x) - vec.begin();
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    int l;
    scanf("%d", &l);
    if (adj[(i + 1) / 2][0].first)
      adj[(i + 1) / 2][1] = make_pair(i + 1, l);
    else
      adj[(i + 1) / 2][0] = make_pair(i + 1, l);
    par[i + 1] = (i + 1) / 2;
  }
  dfs(1);
  for (int i = 1; i <= q; i++) {
    int a, h;
    scanf("%d%d", &a, &h);
    int st = a;
    query(i, in[a], out[a], h + cost[a]);
    while (a != 1) {
      int tmp = a;
      a = par[a];
      query(i, in[a], in[tmp] - 1, h + cost[a] * 2 - cost[st]);
      query(i, out[tmp] + 1, out[a], h + cost[a] * 2 - cost[st]);
    }
  }
  for (int i = 1; i <= n; i++) vec.push_back(cost[i]);
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for (int i = 1; i <= n; i++) {
    for (__typeof((add[i]).begin()) it = (add[i]).begin(); it != (add[i]).end();
         it++) {
      pair<int, long long> res = get(jumbo(it->second));
      ans[it->first] -= res.first * (it->second) - res.second;
    }
    upd(jumbo(cost[id[i]]), cost[id[i]]);
    for (__typeof((rem[i]).begin()) it = (rem[i]).begin(); it != (rem[i]).end();
         it++) {
      pair<int, long long> res = get(jumbo(it->second));
      ans[it->first] += res.first * (it->second) - res.second;
    }
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
