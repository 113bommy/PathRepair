#include <bits/stdc++.h>
using namespace std;
int n;
struct graph {
  vector<vector<int> > edges;
  vector<int> nodes;
};
queue<int> q;
int flag = 1;
void bfs(int r2, graph g) {
  int k;
  vector<vector<int> >::iterator ii;
  vector<int>::iterator jj;
  vector<int> b;
  int c[50000];
  vector<int> d(50000, 0);
  if (flag) {
    q.push(r2);
    flag = 0;
    c[r2] = 0;
  }
  ii = g.edges.begin();
  do {
    k = q.front();
    b = (*(ii + k));
    d[k] = 1;
    for (jj = b.begin(); jj < b.end(); jj++) {
      if (!d[*jj]) {
        q.push(*jj);
        c[*jj] = k;
      }
    }
    q.pop();
  } while (!q.empty());
  for (int i = 1; i <= n; i++) {
    if (i == r2) continue;
    cout << c[i] << " ";
  }
}
int main() {
  int r1, r2, temp;
  graph g;
  vector<vector<int> >::iterator ii;
  cin >> n >> r1 >> r2;
  for (int i = 0; i <= 50000; i++) g.edges.push_back(vector<int>());
  ii = g.edges.begin();
  for (int i = 1; i <= n; i++) {
    if (i == r1) continue;
    cin >> temp;
    (*(ii + i)).push_back(temp);
    (*(ii + temp)).push_back(i);
  }
  bfs(r2, g);
}
