#include <bits/stdc++.h>
using namespace std;
using namespace std;
int n;
long long cost[4][100005];
int cnt[100005];
int visit[100005] = {0};
vector<int> v[100005];
int arr[100005];
int co = 1;
int com[][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
int ans;
int selected;
void dfs(int start) {
  arr[co++] = start;
  visit[start] = 1;
  for (int j = 0; j < v[start].size(); j++) {
    if (visit[v[start][j]] != 1) dfs(v[start][j]);
  }
}
void go() {
  long long mn = 1e18;
  for (int i = 0; i < 6; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      sum += (cost[com[i][j % 3]][arr[j + 1]]);
    }
    if (sum < mn) {
      mn = sum;
      selected = i;
    }
  }
  ans = mn;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n + 1; i++) cnt[i] = 0;
  for (int i = 1; i < 4; i++)
    for (int j = 1; j < n + 1; j++) {
      cin >> cost[i][j];
    }
  int x, y;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
    cnt[x]++;
    cnt[y]++;
    if (cnt[x] > 2 || cnt[y] > 2) {
      cout << -1 << endl;
      return 0;
    }
  }
  int start;
  for (int i = 1; i < n + 1; i++) {
    if (cnt[i] == 1) {
      start = i;
      break;
    }
  }
  dfs(start);
  go();
  cout << ans << endl;
  int ansArr[n + 1];
  for (int i = 0; i < n; i++) {
    ansArr[arr[i + 1]] = com[selected][i % 3];
  }
  for (int i = 1; i < n + 1; i++) {
    cout << ansArr[i] << " ";
  }
  return 0;
}
