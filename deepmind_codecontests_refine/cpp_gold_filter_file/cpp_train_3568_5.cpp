#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, fa[1005];
vector<pair<int, pair<int, int> > > S, M, TS, TM;
int Find(int x) {
  if (fa[x] != x) fa[x] = Find(fa[x]);
  return fa[x];
}
void Merge(int a, int b) { fa[Find(b)] = Find(a); }
int main() {
  int u, v;
  char c;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %c", &u, &v, &c);
    if (c == 'S')
      S.push_back(make_pair(i + 1, make_pair(u, v)));
    else
      M.push_back(make_pair(i + 1, make_pair(u, v)));
  }
  if (n % 2 == 0 || n - 1 > m) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < S.size(); i++) {
    int u = S[i].second.first, v = S[i].second.second;
    if (Find(u) == Find(v)) continue;
    Merge(u, v);
    cnt++;
  }
  if (cnt < (n - 1) / 2) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < M.size(); i++) {
    int u = M[i].second.first, v = M[i].second.second;
    if (Find(u) == Find(v)) continue;
    Merge(u, v);
    cnt++;
    TM.push_back(M[i]);
  }
  if (cnt < n - 1) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  cnt = TM.size();
  for (int i = 0; i < cnt; i++) {
    int u = TM[i].second.first, v = TM[i].second.second;
    Merge(u, v);
  }
  for (int i = 0; i < M.size() && cnt < (n - 1) / 2; i++) {
    int u = M[i].second.first, v = M[i].second.second;
    if (Find(u) == Find(v)) continue;
    Merge(u, v);
    cnt++;
    TM.push_back(M[i]);
  }
  if (cnt < (n - 1) / 2) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < S.size() && cnt < n - 1; i++) {
    int u = S[i].second.first, v = S[i].second.second;
    if (Find(u) == Find(v)) continue;
    Merge(u, v);
    cnt++;
    TS.push_back(S[i]);
  }
  if (cnt < n - 1) {
    printf("-1");
    return 0;
  }
  printf("%d\n", n - 1);
  for (int i = 0; i < (n - 1) / 2; i++) printf("%d ", TM[i].first);
  for (int i = 0; i < (n - 1) / 2; i++) printf("%d ", TS[i].first);
  return 0;
}
