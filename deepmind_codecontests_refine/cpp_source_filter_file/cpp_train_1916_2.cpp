#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> kraj;
  int n, m;
  cin >> n >> m;
  char mat[1001][1001];
  bool visited[1001][101];
  int e1, e2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 'E') {
        e1 = i;
        e2 = j;
      }
      visited[i][j] = false;
    }
  }
  queue<int> qi;
  queue<int> qj;
  queue<int> qs;
  int brojac = 0;
  int maxi = 9999999;
  qi.push(e1);
  qj.push(e2);
  qs.push(0);
  visited[e1][e2] = true;
  while (!qi.empty()) {
    int topi = qi.front();
    qi.pop();
    int topj = qj.front();
    qj.pop();
    int tops = qs.front();
    qs.pop();
    if (mat[topi][topj] == 'S') {
      maxi = tops;
    }
    if (tops > maxi) break;
    if (mat[topi][topj] != 'T' && mat[topi][topj] != '0' &&
        mat[topi][topj] != 'E' && mat[topi][topj] != 'S') {
      brojac += (mat[topi][topj] - '0');
    }
    if (topi + 1 < n && mat[topi + 1][topj] != 'T' &&
        !visited[topi + 1][topj]) {
      qi.push(topi + 1);
      qj.push(topj);
      qs.push(tops + 1);
      visited[topi + 1][topj] = true;
    }
    if (topj - 1 >= 0 && mat[topi][topj - 1] != 'T' &&
        !visited[topi][topj - 1]) {
      qi.push(topi);
      qj.push(topj - 1);
      qs.push(tops + 1);
      visited[topi][topj - 1] = true;
    }
    if (topj + 1 < m && mat[topi][topj + 1] != 'T' &&
        !visited[topi][topj + 1]) {
      qi.push(topi);
      qj.push(topj + 1);
      qs.push(tops + 1);
      visited[topi][topj + 1] = true;
    }
    if (topi - 1 >= 0 && mat[topi - 1][topj] != 'T' &&
        !visited[topi - 1][topj]) {
      qi.push(topi - 1);
      qj.push(topj);
      qs.push(tops + 1);
      visited[topi - 1][topj] = true;
    }
  }
  cout << brojac << endl;
  return 0;
}
