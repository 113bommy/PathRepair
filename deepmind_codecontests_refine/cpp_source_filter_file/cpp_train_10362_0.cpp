#include <bits/stdc++.h>
using namespace std;
map<int, int> mp[300005];
vector<int> v[300005];
int i, j, m, n, p, k, vis[300005], x, y, Q[300005], P[300005];
set<int> st;
set<int>::iterator it;
void work(int x) {
  Q[Q[0] = 1] = x;
  vis[x] = 1;
  st.erase(x);
  int i, l = 1;
  for (; l <= Q[0]; ++l) {
    int p = Q[l];
    P[0] = 0;
    for (it = st.begin(); it != st.end(); ++it) {
      int k = *it;
      if (!mp[p][k]) P[++P[0]] = k, Q[++Q[0]] = k;
    }
    for (i = 1; i <= P[0]; ++i) vis[P[i]] = 1, st.erase(P[i]);
  }
}
int main() {
  vis[1] = 1;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
    mp[x][y] = mp[y][x] = 1;
  }
  if (n - v[x].size() - 1 < k) {
    puts("impossible");
    return 0;
  }
  for (i = 2; i <= n; ++i) st.insert(i);
  vis[1] = 1;
  for (i = 2; i <= n; ++i)
    if (!mp[1][i] && !vis[i]) {
      work(i);
      --k;
    }
  if (k < 0 || st.size())
    puts("impossible");
  else
    puts("possible");
}
