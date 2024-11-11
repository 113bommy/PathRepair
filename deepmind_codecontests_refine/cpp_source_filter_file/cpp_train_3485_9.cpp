#include <bits/stdc++.h>
int n, k, m, t[100005], d[100005], b[100005], p[100005], max[100005];
long long a[100005];
std::vector<int> inc[100005], mul, ans;
int idx[100005], idm;
std::priority_queue<std::pair<double, int> > pq;
double val(int x) {
  if (t[x] == 1) return b[x] - a[d[x]];
  if (t[x] == 2) return b[x];
  if (t[x] == 3) return b[x];
}
int cmp(int a, int b) { return val(a) > val(b); }
int cmp2(int a, int b) { return t[a] < t[b]; }
int main() {
  scanf("%d%d%d", &k, &n, &m);
  for (int i = 1; i <= k; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &t[i], &d[i], &b[i]);
    if (t[i] == 1) {
      if (b[i] > max[d[i]]) p[d[i]] = i;
      max[d[i]] = std::max(max[d[i]], b[i]);
    }
    if (t[i] == 2) inc[d[i]].push_back(i);
    if (t[i] == 3) mul.push_back(i);
  }
  for (int i = 1; i <= k; ++i) {
    if (max[i] > a[i]) inc[i].push_back(p[i]);
    std::sort(inc[i].begin(), inc[i].end(), cmp);
    idx[i] = 1;
    if (inc[i].size())
      pq.push(std::make_pair((double)val(inc[i][0]) / a[i] + 1, inc[i][0]));
  }
  std::sort(mul.begin(), mul.end(), cmp);
  idm = 0;
  while (m--) {
    if (pq.empty() && idm == mul.size()) break;
    double v = 0, v2 = 0;
    std::pair<double, int> P;
    if (!pq.empty()) {
      P = pq.top();
      v = P.first;
    }
    if (idm != mul.size()) v2 = b[mul[idm]];
    if (v2 < v) {
      pq.pop();
      int x = P.second;
      ans.push_back(x);
      a[d[x]] += v;
      if (idx[d[x]] < inc[d[x]].size()) {
        pq.push(std::make_pair((double)val(inc[d[x]][idx[d[x]]]) / a[d[x]],
                               inc[d[x]][idx[d[x]]]));
        ++idx[d[x]];
      }
    } else
      ans.push_back(mul[idm++]);
  }
  std::sort(ans.begin(), ans.end(), cmp2);
  printf("%d\n", ans.size());
  for (int v : ans) printf("%d ", v);
  return 0;
}
