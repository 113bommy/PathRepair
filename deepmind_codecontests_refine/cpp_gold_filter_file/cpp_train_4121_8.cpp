#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> edge[50];
int cnt[50];
pair<long long, long long> ans[50];
bool sym = true;
bool visit[50], dir[50][4];
int step[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void dfs(int pre, long long dis) {
  visit[pre] = 1;
  for (int i = 0; i < (edge[pre].size()); i++)
    if (!visit[edge[pre][i]]) {
      for (int j = 0; j < (4); j++)
        if (!dir[pre][j]) {
          dir[pre][j] = true;
          dir[edge[pre][i]][(j + 2) % 4] = 1;
          ans[edge[pre][i]].first = ans[pre].first + dis * step[j][0];
          ans[edge[pre][i]].second = ans[pre].second + dis * step[j][1];
          dfs(edge[pre][i], dis / 2);
          break;
        }
    }
}
int main() {
  cin >> n;
  for (int i = 0; i < (n - 1); i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
    cnt[a]++;
    cnt[b]++;
    if (cnt[a] > 4 || cnt[b] > 4) {
      cout << "NO" << endl;
      return 0;
    }
  }
  ans[1].first = 0;
  ans[1].second = 0;
  dfs(1, 1ll << 32ll);
  cout << "YES" << endl;
  for (int i = 1; i <= (n); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
