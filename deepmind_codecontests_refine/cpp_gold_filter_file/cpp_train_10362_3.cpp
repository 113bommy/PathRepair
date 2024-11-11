#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt;
set<pair<int, int> > S;
set<int> T;
bool check(int a, int b) {
  if (a > b) swap(a, b);
  return S.find(make_pair(a, b)) == S.end();
}
void dfs(int x) {
  vector<int> v;
  for (int i : T)
    if (check(x, i)) v.push_back(i);
  for (int i : v) T.erase(i);
  for (int i : v) dfs(i);
}
int main() {
  scanf("%d%d%d\n", &n, &m, &k);
  while (m--) {
    int a, b;
    scanf("%d%d\n", &a, &b);
    if (a > b) swap(a, b);
    if (a == 1) ++cnt;
    S.insert(make_pair(a, b));
  }
  int bcc = 0;
  for (int i = 2; i < n + 1; ++i) T.insert(i);
  for (int i = 2; i < n + 1; ++i)
    if (check(1, i) && T.count(i)) dfs(i), ++bcc;
  if (T.size() == 0 && n - 1 - cnt >= k && k >= bcc)
    printf("possible\n");
  else
    printf("impossible\n");
  return 0;
}
