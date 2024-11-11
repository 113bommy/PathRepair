#include <bits/stdc++.h>
using namespace std;
int N, M;
char A[1010][1010];
string STR = "DIMA";
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int DP[1010][1010];
int vis[1010][1010];
bool check(int x, int y) {
  if (x < 0 or y < 0) {
    return false;
  }
  if (x >= N or y >= M) {
    return false;
  }
  return true;
}
int cycle;
int F(int cx, int cy) {
  if (vis[cx][cy] == 2) {
    return DP[cx][cy];
  }
  if (vis[cx][cy] == 1) {
    cycle = 1;
    return (DP[cx][cy] = 0);
  }
  vis[cx][cy] = 1;
  int &ans = DP[cx][cy];
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int nx = cx + dx[i];
    int ny = cy + dy[i];
    if (check(nx, ny)) {
      if (A[cx][cy] == 'D' and A[nx][ny] == 'I') {
        res = max(res, F(nx, ny));
      } else if (A[cx][cy] == 'I' and A[nx][ny] == 'M') {
        res = max(res, F(nx, ny));
      } else if (A[cx][cy] == 'M' and A[nx][ny] == 'A') {
        res = max(res, F(nx, ny) + 1);
      } else if (A[cx][cy] == 'A' and A[nx][ny] == 'D') {
        res = max(res, F(nx, ny));
      }
    }
  }
  ans += res;
  vis[cx][cy] = 2;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int Ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 'D') {
        Ans = max(Ans, F(i, j));
        if (cycle) {
          cout << "Poor Dima!\n";
          return 0;
        }
      }
    }
  }
  if (Ans == 0) {
    cout << "Poor Dima!";
  } else {
    cout << Ans << endl;
  }
  return 0;
}
