#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000009;
bool dan(vector<int> v, map<vector<int>, int> &M) {
  if (M.find(v) == M.end()) return false;
  int cnt = 0;
  for (int i = -1; i <= 1; i++)
    if (M.find({v[0] + i, v[1] - 1}) != M.end()) cnt++;
  return cnt <= 1;
}
bool check(vector<int> v, map<vector<int>, int> &M) {
  if (M.find(v) == M.end()) return false;
  for (int i = -1; i <= 1; i++)
    if (dan({v[0] + i, v[1] + 1}, M)) return false;
  return true;
}
int main() {
  int m;
  scanf("%d", &m);
  vector<vector<int>> v(m, {0, 0});
  map<vector<int>, int> M;
  for (int i = 0; i < m; i++) scanf("%d%d", &v[i][0], &v[i][1]), M[v[i]] = i;
  set<int> S;
  for (int i = 0; i < m; i++)
    if (check(v[i], M)) S.insert(i);
  long long ans = 0;
  for (int i = 0; !S.empty(); i ^= 1) {
    auto it = i & 1 ? S.begin() : --S.end();
    int x = *it;
    S.erase(it);
    M.erase(v[x]);
    for (int i = -1; i <= 1; i++)
      if (dan({v[x][0] + i, v[x][1] + 1}, M))
        for (int j = -1; j <= 1; j++)
          if (M.find({v[x][0] + i + j, v[x][1]}) != M.end())
            S.erase(M[{v[x][0] + i + j, v[x][1]}]);
    for (int i = -1; i <= 1; i++)
      if (check({v[x][0] + i, v[x][1] - 1}, M))
        S.insert(M[{v[x][0] + i, v[x][1] - 1}]);
    ans = (ans * m % P + x) % P;
  }
  printf("%lld\n", ans);
}
