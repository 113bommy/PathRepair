#include <bits/stdc++.h>
using namespace std;
int a[111111];
vector<int> vec[111111];
void dfs(int v, int p, int h) {
  a[h] += 1;
  for (int i = 0; i < vec[v].size(); i++) {
    if (vec[v][i] != p) dfs(vec[v][i], v, h + 1);
  }
}
int main() {
  int n, k, p;
  cin >> n >> k >> p;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  dfs(1, 0, 0);
  int i = 1;
  int cur = 0;
  int den = 0;
  int ans = 0;
  for (int gl = 1; gl < n; gl++) {
    if (a[gl] == 0) break;
    den += cur;
    cur += a[gl];
    while (den > p) {
      if (a[i] == 0) i++;
      den -= gl - i;
      a[i]--;
      cur--;
    }
    ans = max(ans, cur);
  }
  cout << min(ans, k);
  return 0;
}
