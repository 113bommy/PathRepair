#include <bits/stdc++.h>
int T;
int n;
int d[100005];
std::vector<std::pair<int, int> > q;
char s[100005];
std::vector<int> a;
inline void qry() {
  a.clear();
  if (!q.size()) return;
  printf("Q %d ", q.size());
  for (auto i : q) printf("%d %d ", i.first, i.second);
  puts("");
  fflush(stdout);
  scanf("%s", s);
  for (int i = 0; i < q.size(); i++) a.push_back(s[i] - '0');
  q.clear();
}
int dd[100005];
std::vector<int> v;
inline void sol() {
  for (int i = 0; i + 1 < v.size(); i += 2)
    q.push_back(std::make_pair(v[i], v[i + 1]));
  qry();
  for (int i = 0, j = 0; i + 1 < v.size(); i += 2, j++) dd[v[i]] = a[j];
  for (int i = 1; i + 1 < v.size(); i += 2)
    q.push_back(std::make_pair(v[i], v[i + 1]));
  qry();
  for (int i = 1, j = 0; i + 1 < v.size(); i += 2, j++) dd[v[i]] = a[j];
  v.clear();
}
int col[100005];
std::vector<int> ans[3];
inline void cov(int tp, int x) {
  col[x] = tp;
  for (int i = x; i <= d[x]; i++) ans[tp].push_back(x);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i + 1 <= n; i += 2) q.push_back(std::make_pair(i, i + 1));
    qry();
    for (int i = 1, j = 0; i + 1 <= n; i += 2, j++) d[i] = a[j];
    for (int i = 2; i + 1 <= n; i += 2) q.push_back(std::make_pair(i, i + 1));
    qry();
    for (int i = 2, j = 0; i + 1 <= n; i += 2, j++) d[i] = a[j];
    d[n + 1] = d[n] = n;
    for (int i = n - 1; i; i--) d[i] = d[i] ? d[i + 1] : i;
    for (int i = 1; i <= n; i = d[d[i] + 1] + 1) v.push_back(i);
    sol();
    for (int i = d[1] + 1; i <= n; i = d[d[i] + 1] + 1) v.push_back(i);
    sol();
    ans[0].clear(), ans[1].clear(), ans[2].clear();
    for (int i = 1; i <= n; i = d[i] + 1) v.push_back(i);
    cov(0, v[0]);
    if (v.size() > 1) cov(1, v[1]);
    for (int i = 0; i + 2 < v.size(); i++)
      if (dd[v[i]])
        cov(col[v[i]], v[i + 2]);
      else
        cov(0 ^ 1 ^ 2 ^ col[v[i]] ^ col[v[i + 1]], v[i + 2]);
    v.clear();
    printf("A %d %d %d\n", ans[0].size(), ans[1].size(), ans[2].size());
    for (auto i : ans[0]) printf("%d ", i);
    puts("");
    for (auto i : ans[1]) printf("%d ", i);
    puts("");
    for (auto i : ans[2]) printf("%d ", i);
    puts("");
    fflush(stdout);
  }
}
