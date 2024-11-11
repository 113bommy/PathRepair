#include <bits/stdc++.h>
using namespace std;
vector<int> L[100100];
int sub[100100];
int h[100100];
int anc[100100];
int sz[100100];
int foi[100100];
int pre[100100];
int cnt = 0;
void dfs(int x, int p = 0) {
  sub[x] = 1;
  for (int i : L[x])
    if (i != p) {
      dfs(i, x);
      sub[x] += sub[i];
    }
}
vector<pair<int, int> > match[100100];
int W;
int dfs1(int x, int p, int br) {
  sz[br]++;
  pre[x] = cnt++;
  if (p + 1) h[x] = 1 + h[p];
  anc[x] = p;
  vector<int> v;
  for (int i : L[x])
    if (i != p) {
      int u = dfs1(i, x, (p == -1) ? i : br);
      if (u + 1) v.push_back(u), W++;
    }
  v.push_back(x);
  for (int i = 0; i + 1 < v.size(); i++) {
    match[br].push_back({v[i], v[i + 1]});
    ;
  }
  if (v.size() % 2 == 1)
    return v[v.size() - 1];
  else
    return -1;
}
int lca(int a, int b) {
  if (h[a] < h[b]) return a;
  if (h[a] > h[b]) return b;
  return anc[a];
}
int main() {
  int n;
  long long k;
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    L[a].push_back(b);
    L[b].push_back(a);
  }
  dfs(0);
  int ts = 0, p = 0;
  while (1) {
    ;
    if (ts > 0 && L[ts].size() == 1) break;
    int mx = -1;
    for (int i : L[ts])
      if (i != p) {
        if (mx == -1 || sub[i] > sub[mx]) mx = i;
      }
    if (2 * sub[mx] >= n) {
      p = ts;
      ts = mx;
    } else
      break;
  }
  dfs1(ts, -1, ts);
  long long cur = 0;
  for (int i = 0; i < n; i++) cur += h[i];
  set<pair<int, int> > S;
  for (int i : L[ts]) {
    S.insert({sz[i], i});
    ;
  }
  for (int i = 0; i < n; i++)
    sort(match[i].begin(), match[i].end(),
         [](pair<int, int> x, pair<int, int> y) {
           return min(h[x.first], h[x.second]) < min(h[y.first], h[y.second]);
         });
  if (k > cur || k < W || k % 2 != cur % 2) {
    printf("NO\n");
    return 0;
  }
  vector<pair<int, int> > ans;
  while (cur > k) {
    ;
    pair<int, int> u = *--S.end();
    S.erase(u);
    int br = u.second;
    pair<int, int> p = match[br][match[br].size() - 1];
    ;
    match[br].pop_back();
    int dec = 2 * h[lca(p.first, p.second)];
    ;
    if (cur - dec >= k) {
      cur -= dec;
      ans.push_back(p);
      foi[p.first] = foi[p.second] = 1;
      sz[br] -= 2;
      S.insert({sz[br], br});
      continue;
    }
    int x = p.first;
    if (h[p.first] < h[p.second]) x = p.second;
    int y = x;
    while (cur - 2 * h[y] < k) y = anc[y];
    ;
    ans.push_back({x, y});
    foi[x] = foi[y] = 1;
    cur = k;
  }
  vector<int> outros;
  for (int i = 0; i < n; i++)
    if (!foi[i]) outros.push_back(i);
  sort(outros.begin(), outros.end(),
       [](int i, int j) { return pre[i] < pre[j]; });
  for (int i = 0; i < outros.size() / 2; i++)
    ans.push_back({outros[i], outros[i + outros.size() / 2]});
  printf("YES\n");
  for (pair<int, int> i : ans) printf("%d %d\n", i.first + 1, i.second + 1);
}
