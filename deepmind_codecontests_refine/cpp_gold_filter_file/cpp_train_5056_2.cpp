#include <bits/stdc++.h>
using namespace std;
const int maxNodes = 1000000;
int noNeed[maxNodes];
long long accu[maxNodes];
int ans[maxNodes];
int ans_temp[maxNodes];
vector<pair<int, int>> nodes[maxNodes];
void dfs(int node, int h = 1) {
  accu[h] += accu[h - 1];
  for (pair<int, int> p : nodes[node]) {
    accu[h] += p.second;
    dfs(p.first, h + 1);
    accu[h] -= p.second;
  }
  int low = 1, high = h;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (accu[h] - accu[mid - 1] <= noNeed[node])
      high = mid;
    else
      low = mid + 1;
  }
  if (low != h) {
    ans_temp[low - 1]--;
    ans_temp[h - 1]++;
  }
  accu[h] = 0;
  ans_temp[h - 1] += ans_temp[h];
  ans[node] = ans_temp[h];
  ans_temp[h] = 0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &noNeed[i]);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    nodes[x].push_back({i + 2, y});
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
