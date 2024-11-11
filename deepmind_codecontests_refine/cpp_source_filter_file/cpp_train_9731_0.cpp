#include <bits/stdc++.h>
using namespace std;
int edges[200000][3];
int visit[200000];
int mindis[200000];
int pare[200000];
int minblack[200000];
int mark[200000];
list<int> *adj;
list<int> que;
map<pair<int, int>, int> mym;
int color(int a, int b) {
  map<pair<int, int>, int>::iterator it;
  pair<int, int> use = make_pair(a, b);
  if (mym.find(use) != mym.end()) {
    it = mym.find(use);
    int col = it->second - 1;
    col = edges[col][2];
    return col;
  } else {
    use = make_pair(b, a);
    it = mym.find(use);
    int col = it->second - 1;
    col = edges[col][2];
    return col;
  }
}
void idx(int a, int b) {
  map<pair<int, int>, int>::iterator it;
  pair<int, int> use = make_pair(a, b);
  if (mym.find(use) != mym.end()) {
    it = mym.find(use);
    int col = it->second - 1;
    mark[col] = 1;
  } else {
    use = make_pair(b, a);
    it = mym.find(use);
    int col = it->second - 1;
    mark[col] = 1;
  }
}
void bfs(int vertex) {
  visit[vertex] = 1;
  que.push_back(vertex);
  list<int>::iterator i;
  mindis[vertex] = 0;
  while (!que.empty()) {
    int l = que.front();
    que.pop_front();
    for (i = adj[l].begin(); i != adj[l].end(); ++i) {
      if (mindis[*i] > mindis[l] + 1) mindis[*i] = mindis[l] + 1;
      if (!visit[*i]) {
        visit[*i] = 1;
        que.push_back(*i);
      }
    }
  }
}
void minbla(int vertex) {
  visit[vertex] = 1;
  que.push_back(vertex);
  minblack[vertex] = 0;
  list<int>::iterator i;
  mindis[vertex] = 0;
  while (!que.empty()) {
    int l = que.front();
    que.pop_front();
    for (i = adj[l].begin(); i != adj[l].end(); ++i) {
      if (mindis[*i] == mindis[l] + 1) {
        if (!color(*i, l)) {
          if (minblack[l] + 1 < minblack[*i]) minblack[*i] = minblack[l] + 1;
        }
        if (color(*i, l)) {
          if (minblack[l] < minblack[*i]) minblack[*i] = minblack[l];
        }
      }
      if (!visit[*i]) {
        visit[*i] = 1;
        que.push_back(*i);
      }
    }
  }
}
void parents(int vertex) {
  visit[vertex] = 1;
  que.push_back(vertex);
  list<int>::iterator i;
  while (!que.empty()) {
    int l = que.front();
    que.pop_front();
    if (l == 1) break;
    int done = 0;
    for (i = adj[l].begin(); i != adj[l].end(); ++i) {
      if (!done)
        if (mindis[*i] + 1 == mindis[l])
          if (!color(*i, l)) {
            if (minblack[*i] + 1 == minblack[l]) {
              idx(*i, l);
              que.push_back(*i);
              done = 1;
            }
          } else {
            if (minblack[*i] == minblack[l]) {
              idx(*i, l);
              que.push_back(*i);
              done = 1;
            }
          }
    }
  }
}
int main() {
  int n, m, p, q;
  cin >> n >> m;
  adj = new list<int>[n + 123];
  for (long long i = 0; i < n + 10; i++) visit[i] = 0;
  for (long long i = 0; i < n + 10; i++) mindis[i] = 2000000;
  for (long long i = 0; i < n + 10; i++) mark[i] = 0;
  for (long long i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    p = edges[i][0];
    q = edges[i][1];
    adj[p].push_back(q);
    adj[q].push_back(p);
    pair<int, int> use = make_pair(p, q);
    mym.insert(pair<pair<int, int>, int>(use, i + 1));
  }
  bfs(1);
  for (long long i = 0; i < n + 10; i++) visit[i] = 0, minblack[i] = 2000000;
  minbla(1);
  parents(n);
  int count = 0;
  for (long long i = 0; i < n + 1; i++) {
    if (mark[i]) {
      if (edges[i][2] == 0) count++;
    } else {
      if (edges[i][2] == 1) count++;
    }
  }
  cout << count << "\n";
  for (long long i = 0; i < n + 1; i++) {
    if (mark[i]) {
      if (edges[i][2] == 0)
        cout << edges[i][0] << " " << edges[i][1] << " "
             << "1"
             << "\n";
    } else {
      if (edges[i][2] == 1)
        cout << edges[i][0] << " " << edges[i][1] << " "
             << "0"
             << "\n";
    }
  }
}
