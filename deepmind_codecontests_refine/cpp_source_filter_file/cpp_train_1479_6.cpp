#include <bits/stdc++.h>
long long MAX = 1e12;
using namespace std;
vector<int> temp(3);
int fans[100010];
long long fcst = INT_MAX;
long long c[3][100010];
vector<int> adj[100010];
int n;
void dfs(int s) {
  bool vis[n];
  int ham[n];
  queue<int> q;
  memset(vis, false, sizeof(vis));
  vis[s] = true;
  int k = 0;
  long long cst = c[temp[k]][s];
  ham[s] = temp[k];
  q.push(s);
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (int i = 0; i < adj[p].size(); i++) {
      if (vis[adj[p][i]] == false) {
        q.push(adj[p][i]);
        k++;
        k = k % 3;
        ham[adj[p][i]] = temp[k];
        cst += c[temp[k]][adj[p][i]];
        vis[adj[p][i]] = true;
      }
    }
  }
  if (fcst > cst) {
    fcst = cst;
    for (int i = 0; i < n; i++) {
      fans[i] = ham[i];
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) cin >> c[i][j];
  }
  int x, y;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int cnt1 = 0, strt;
  for (int i = 0; i < n; i++) {
    if (adj[i].size() == 1) {
      strt = i;
      cnt1++;
    } else if (adj[i].size() > 2) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (cnt1 != 2) {
    cout << -1 << endl;
    return 0;
  }
  int mat[6][3];
  mat[0][0] = 0, mat[0][1] = 1, mat[0][2] = 2;
  mat[1][0] = 1, mat[1][1] = 2;
  mat[1][2] = 0;
  mat[2][0] = 2, mat[2][1] = 1;
  mat[2][2] = 0;
  mat[3][0] = 0, mat[3][1] = 2;
  mat[3][2] = 1;
  mat[4][0] = 1, mat[4][1] = 0;
  mat[4][2] = 2;
  mat[5][0] = 2, mat[5][1] = 0;
  mat[5][2] = 1;
  for (int i = 0; i < 6; i++) {
    temp[0] = mat[i][0], temp[1] = mat[i][1], temp[2] = mat[i][2];
    dfs(strt);
  }
  cout << fcst << endl;
  for (int i = 0; i < n; i++) cout << fans[i] + 1 << " ";
}
