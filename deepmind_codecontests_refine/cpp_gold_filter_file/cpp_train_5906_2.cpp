#include <bits/stdc++.h>
using namespace std;
long long int a[100001][101];
vector<long long int> nodes[100001];
bool visited[100001] = {0};
long long int arr[100001];
long long int n, m, k, s;
void dfs(long long int s) {
  visited[s] = 1;
  a[s][arr[s]] = 0;
  for (long long int i = 0; i < nodes[s].size(); i++) {
    long long int x = arr[nodes[s][i]];
    if (a[s][x] == -1)
      a[s][x] = 1;
    else {
      long long int r = 1;
      a[s][x] = min(r, a[s][x]);
    }
  }
  for (long long int i = 0; i < nodes[s].size(); i++) {
    for (long long int j = 1; j <= k; j++) {
      if (a[nodes[s][i]][j] == -1)
        ;
      else {
        if (a[s][j] == -1)
          a[s][j] = a[nodes[s][i]][j] + 1;
        else
          a[s][j] = min(a[s][j], a[nodes[s][i]][j] + 1);
      }
    }
  }
  for (long long int i = 0; i < nodes[s].size(); i++) {
    for (long long int j = 1; j <= k; j++) {
      if (a[s][j] == -1)
        ;
      else {
        if (a[nodes[s][i]][j] == -1)
          a[nodes[s][i]][j] = a[s][j] + 1;
        else
          a[nodes[s][i]][j] = min(a[s][j] + 1, a[nodes[s][i]][j]);
      }
    }
  }
  for (long long int i = 0; i < nodes[s].size(); i++) {
    if (visited[nodes[s][i]] == 0) dfs(nodes[s][i]);
  }
  for (long long int i = 0; i < nodes[s].size(); i++) {
    for (long long int j = 1; j <= k; j++) {
      if (a[nodes[s][i]][j] == -1)
        ;
      else {
        if (a[s][j] == -1)
          a[s][j] = a[nodes[s][i]][j] + 1;
        else
          a[s][j] = min(a[s][j], a[nodes[s][i]][j] + 1);
      }
    }
  }
  for (long long int i = 0; i < nodes[s].size(); i++) {
    for (long long int j = 1; j <= k; j++) {
      if (a[s][j] == -1)
        ;
      else {
        if (a[nodes[s][i]][j] == -1)
          a[nodes[s][i]][j] = a[s][j] + 1;
        else
          a[nodes[s][i]][j] = min(a[s][j] + 1, a[nodes[s][i]][j]);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k >> s;
  for (long long int i = 1; i <= n; i++) cin >> arr[i];
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= k; j++) a[i][j] = -1;
  }
  for (long long int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    nodes[x].push_back(y);
    nodes[y].push_back(x);
  }
  for (long long int p = 1; p <= 3; p++) {
    dfs(1);
    for (long long int i = 1; i <= n; i++) visited[i] = 0;
  }
  long long int temp[k];
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= k; j++) temp[j - 1] = a[i][j];
    sort(temp, temp + k);
    long long int res = 0;
    for (long long int j = 0; j < s; j++) res += temp[j];
    cout << res << " ";
  }
  return 0;
}
