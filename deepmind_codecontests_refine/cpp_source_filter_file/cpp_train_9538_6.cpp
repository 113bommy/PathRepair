#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, maxlog = 21;
int eul[maxlog][maxn], dep[maxn], tim, fa[maxn], st[maxn], n, dfn[maxn];
vector<int> g[maxn], vec[maxn];
long long val[maxn];
void dfs(int x) {
  dep[x] = dep[fa[x]] + 1;
  eul[0][dfn[x] = ++tim] = dep[x];
  vec[dep[x]].push_back(x);
  for (int v : g[x]) {
    dfs(v);
    eul[0][++tim] = dep[x];
  }
}
int query(int l, int r) {
  int len = r - l + 1, x = 0;
  while (1 << x < len) {
    x++;
  }
  x--;
  return min(eul[x][l], eul[x][r - (1 << x) + 1]);
}
void solve(vector<int> tmp, vector<int> v) {
  int top = 0;
  long long sum = 0;
  st[0] = -1;
  assert(v.size() == tmp.size() + 1);
  for (int j = 0; j < tmp.size(); j++) {
    int x = tmp[j];
    while (top && st[top] >= x) {
      sum -= 1LL * (st[top] - st[top - 1]) * tmp[st[top]];
      top--;
    }
    st[++top] = j;
    sum += 1LL * (j - st[top - 1]) * x;
    val[v[j + 1]] += sum;
  }
}
void calc(int x) {
  val[x] += dep[x];
  for (int v : g[x]) {
    val[v] += val[x];
    calc(v);
  }
}
int root;
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &fa[i]);
    g[fa[i]].push_back(i);
    if (!fa[i]) {
      root = i;
    }
  }
  dfs(root);
  for (int i = 1; i < maxlog; i++) {
    for (int j = 1; j <= tim - (1 << i) + 1; j++) {
      eul[i][j] = min(eul[i - 1][j], eul[i - 1][j + (1 << i - 1)]);
    }
  }
  for (int i = 1; vec[i].size(); i++) {
    vector<int> tmp;
    for (int j = 0; j < vec[i].size() - 1; j++) {
      tmp.push_back(query(dfn[vec[i][j]], dfn[vec[i][j + 1]]));
    }
    solve(tmp, vec[i]);
    reverse(tmp.begin(), tmp.end());
    reverse(vec[i].begin(), vec[i].end());
    solve(tmp, vec[i]);
  }
  calc(root);
  for (int i = 1; i <= n; i++) {
    printf("%lld%c", val[i] - dep[i], " \n"[i == n]);
  }
  return 0;
}
