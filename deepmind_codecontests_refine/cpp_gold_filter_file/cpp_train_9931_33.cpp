#include <bits/stdc++.h>
using namespace std;
char a[1700][1700];
int used[1700][1700], comp = 0;
int L[1700][1700], R[1700][1700], U[1700][1700], D[1700][1700];
int N, M;
char P[1700][1700];
vector<int> v;
queue<pair<int, int> > q;
int MNX[1 << 20], MNY[1 << 20], MXX[1 << 20], MXY[1 << 20];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
void scan() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) scanf("%d", a[i] + j);
}
int brr = 0;
void bfs(char a[1700][1700], int i, int j) {
  used[i][j] = ++comp;
  q.push(make_pair(i, j));
  brr = 0;
  MXX[comp] = MNX[comp] = i;
  MXY[comp] = MNY[comp] = j;
  while (!q.empty()) {
    ++brr;
    i = q.front().first;
    j = q.front().second;
    q.pop();
    MXX[comp] = max(MXX[comp], i);
    MNX[comp] = min(MNX[comp], i);
    MXY[comp] = max(MXY[comp], j);
    MNY[comp] = min(MNY[comp], j);
    for (int k = 0; k < 4; ++k) {
      int ni = i + dx[k], nj = j + dy[k];
      if (!used[ni][nj] && a[ni][nj]) {
        used[ni][nj] = comp;
        q.push(make_pair(ni, nj));
      }
    }
  }
}
int calc(int x, int y) {
  int res = 0, add = 0;
  for (int i = x; i <= x + 5; ++i) {
    int l = max(L[i][y], y - 5), r = min(R[i][y], y + 5);
    if (a[i][y] == 0) break;
    res = res + r - l - 1;
  }
  for (int i = x - 1; i >= x - 5; --i) {
    int l = max(L[i][y], y - 5), r = min(R[i][y], y + 5);
    if (a[i][y] == 0) break;
    res = res + r - l - 1;
  }
  return res;
}
int countRays(int idx) {
  int lx = MNX[idx], rx = MXX[idx];
  int ly = MNY[idx], ry = MXY[idx];
  for (int i = lx; i <= rx; ++i) {
    int last = ly - 1;
    for (int j = ly; j <= ry; ++j) {
      if (a[i][j] == 0) last = j;
      L[i][j] = last;
    }
    last = ry + 1;
    for (int j = ry; j >= ly; --j) {
      if (a[i][j] == 0) last = j;
      R[i][j] = last;
    }
  }
  for (int i = lx; i <= rx; ++i)
    for (int j = ly; j <= ry; ++j)
      if (a[i][j] && calc(i, j) <= 40) {
        P[i][j] = 1;
      }
  int lcomp = comp;
  int br = 0;
  for (int i = lx; i <= rx; ++i)
    for (int j = ly; j <= ry; ++j)
      if (P[i][j] && !used[i][j]) {
        bfs(P, i, j);
        if (brr > 10) ++br;
      }
  return br;
}
void solve() {
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      if (a[i][j] && !used[i][j]) bfs(a, i, j);
  cout << comp << endl;
  memset(used, 0, sizeof(used));
  int tomp = comp;
  for (int i = 1; i <= tomp; ++i) v.push_back(countRays(i));
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) printf("%d ", v[i]);
  printf("\n");
}
int main() {
  scan();
  solve();
}
