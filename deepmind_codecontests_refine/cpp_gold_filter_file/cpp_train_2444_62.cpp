#include <bits/stdc++.h>
using namespace std;
int rows, cols;
char board[60][60];
bool visited[60][60];
int dirrow[] = {
    -1,
    0,
    0,
    1,
};
int dircol[] = {0, -1, 1, 0};
pair<int, int> parent[60][60];
bool bfs(pair<int, int> source) {
  parent[source.first][source.second] = pair<int, int>(-1, -1);
  queue<pair<int, int> > q;
  q.push(source);
  visited[source.first][source.second] = true;
  while (q.empty() == false) {
    pair<int, int> u = q.front();
    int ur = u.first, uc = u.second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int vr = ur + dirrow[i], vc = uc + dircol[i];
      if (0 <= vr && vr < rows && 0 <= vc && vc < cols &&
          board[ur][uc] == board[vr][vc]) {
        pair<int, int> v = pair<int, int>(vr, vc);
        if (visited[vr][vc] == true &&
            (parent[ur][uc].first != vr || parent[ur][uc].second != vc))
          return true;
        if (visited[vr][vc]) continue;
        visited[vr][vc] = true;
        parent[vr][vc] = u;
        q.push(v);
      }
    }
  }
  return false;
}
bool allbfs() {
  bool found = false;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      if (visited[i][j] == false) found = bfs(pair<int, int>(i, j));
      if (found) return found;
    }
  return found;
}
void input() {
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      cin >> board[i][j];
      parent[i][j] = pair<int, int>(-1, -1);
    }
  return;
}
void output() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) cout << board[i][j];
    cout << endl;
  }
  return;
}
int main() {
  while (cin >> rows >> cols) {
    input();
    bool res = allbfs();
    string outp = (res == true) ? "Yes" : "No";
    cout << outp << endl;
  }
  return 0;
}
