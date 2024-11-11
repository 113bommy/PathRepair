#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 400 + 10;
bool mrk[MAX_N], rail[MAX_N][MAX_N], bus[MAX_N][MAX_N];
int N, M, D[MAX_N];
void BFS1(int x) {
  mrk[x] = true;
  queue<int> Q;
  Q.push(x);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    if (x == N) break;
    for (int nx = 1; nx <= N; nx++) {
      if (!rail[x][nx] || mrk[nx]) continue;
      mrk[nx] = true;
      D[nx] = D[x] + 1;
      Q.push(nx);
    }
  }
}
void BFS2(int x) {
  mrk[x] = true;
  queue<int> Q;
  Q.push(x);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    if (x == N) break;
    for (int nx = 1; nx <= N; nx++) {
      if (!bus[x][nx] || mrk[nx]) continue;
      mrk[nx] = true;
      D[nx] = D[x] + 1;
      Q.push(nx);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    rail[x][y] = true;
    rail[y][x] = true;
  }
  for (int i = 0; i < MAX_N; i++)
    for (int j = 0; j < MAX_N; j++)
      if (!rail[i][j]) bus[i][j] = true;
  rail[N][N] = true;
  bus[N][N] = true;
  if (rail[N][N])
    BFS1(1);
  else
    BFS2(1);
  if (!mrk[N])
    cout << -1 << endl;
  else
    cout << D[N] << endl;
  return 0;
}
