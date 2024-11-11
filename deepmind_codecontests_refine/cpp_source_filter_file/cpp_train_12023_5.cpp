#include <bits/stdc++.h>
using namespace std;
const int N = 1001000;
const long long P = 1e9 + 7, INF = 2 * 1e9;
int n, a, b, odw[N], cnt;
vector<int> v[N];
pair<int, int> dfs(int x, int h) {
  odw[x] = 1;
  pair<int, int> tmp;
  int sum0 = 0, sum1 = 0, min0 = INF, min1 = INF;
  if (v[x].size() == 1) {
    cnt++;
    return {0, 0};
  }
  for (int i = 0; i < v[x].size(); i++)
    if (!odw[v[x][i]]) {
      tmp = dfs(v[x][i], h + 1);
      sum0 += tmp.first;
      sum1 += tmp.second;
      min0 = min(min0, tmp.first);
      min1 = min(min1, tmp.second);
    }
  sum0 += v[x].size() - 2;
  sum1 += v[x].size() - 2;
  if (h % 2 == 0)
    return {sum0, min1};
  else
    return {min1, sum0};
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  v[1].push_back(0);
  odw[0] = 1;
  pair<int, int> wyn = dfs(1, 0);
  printf("%d %d", cnt - wyn.second, wyn.first + 1);
}
