#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const int maxn = 300005;
int n, a[maxn], d[maxn], cnt;
vector<int> e[maxn];
void dfs(int x) {
  if (!e[x].size()) {
    d[x] = 1;
    ++cnt;
    return;
  }
  d[x] = a[x] ? n : 0;
  for (unsigned int i = 0; i < e[x].size(); i++) {
    int y = e[x][i];
    dfs(y);
    if (a[x])
      d[x] = min(d[x], d[y]);
    else
      d[x] += d[y];
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2, f; i <= n; i++) {
    scanf("%d", &f);
    e[f].push_back(i);
  }
  dfs(1);
  cout << cnt + 1 - d[1] << endl;
  return 0;
}
