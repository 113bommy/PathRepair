#include <bits/stdc++.h>
using namespace std;
int d[6][3] = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
               {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};
int main() {
  int k, n, m, sn, sm, ans = 0;
  cin >> k >> n >> m;
  string plate[k][n];
  bool visited[k][n][m];
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) visited[i][j][i] = false;
      cin >> plate[i][j];
    }
  queue<vector<int> > q;
  cin >> sn >> sm;
  vector<int> init;
  for (int i = 0; i < 3; i++) init.push_back(0);
  int arr[3] = {0, sn - 1, sm - 1};
  for (int i = 0; i < 3; i++) init[i] = arr[i];
  q.push(init);
  while (!q.empty()) {
    vector<int> A = q.front();
    visited[A[0]][A[1]][A[2]] = true;
    ans++;
    q.pop();
    for (int i = 0; i < 6; i++) {
      vector<int> B(A);
      for (int j = 0; j < 3; j++) B[j] += d[i][j];
      if (B[0] >= 0 && B[0] < k && B[1] >= 0 && B[1] < n && B[2] >= 0 &&
          B[2] < m && plate[B[0]][B[1]][B[2]] == '.' &&
          !visited[B[0]][B[1]][B[2]]) {
        q.push(B);
        visited[B[0]][B[1]][B[2]] = true;
      }
    }
  }
  cout << ans;
  return 0;
}
