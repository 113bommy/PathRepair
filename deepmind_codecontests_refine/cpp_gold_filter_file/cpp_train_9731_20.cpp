#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;
vector<pair<int, int> > v[MAX];
int d1[MAX];
int dis1[MAX];
bool mark[MAX];
int disn[MAX];
int dn[MAX];
pair<int, int> par1[MAX];
pair<int, int> parn[MAX];
map<pair<int, int>, bool> check;
vector<pair<int, int> > edge;
void BFS(int x) {
  queue<int> q;
  q.push(x);
  mark[x] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < v[now].size(); i++) {
      int child = v[now][i].first;
      int road = v[now][i].second;
      if (!mark[child]) {
        par1[child] = {now, road};
        dis1[child] = dis1[now] + 1;
        if (road == 1)
          d1[child] = d1[now] + 1;
        else
          d1[child] = d1[now];
        mark[child] = true;
        q.push(child);
      }
    }
  }
}
void BFS_2(int x) {
  queue<int> q;
  q.push(x);
  mark[x] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < v[now].size(); i++) {
      int child = v[now][i].first;
      int road = v[now][i].second;
      if (!mark[child]) {
        parn[child] = {now, road};
        disn[child] = disn[now] + 1;
        if (road == 1)
          dn[child] = dn[now] + 1;
        else
          dn[child] = dn[now];
        mark[child] = true;
        q.push(child);
      }
    }
  }
}
void pp1(int x) {
  if (par1[x].first != -1) {
    if (par1[x].second == 0) {
      cout << x << " " << par1[x].first << " " << 1 << endl;
    }
    check[{x, par1[x].first}] = true;
    check[{par1[x].first, x}] = true;
    pp1(par1[x].first);
  }
}
void pp2(int x) {
  if (parn[x].first != -1) {
    if (parn[x].second == 0) {
      cout << x << " " << parn[x].first << " " << 1 << endl;
    }
    check[{x, parn[x].first}] = true;
    check[{parn[x].first, x}] = true;
    pp2(parn[x].first);
  }
}
int main() {
  int n, m, s, e, w;
  cin >> n >> m;
  int work = 0;
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> w;
    v[s].push_back({e, w});
    v[e].push_back({s, w});
    if (w == 1) {
      work++;
      edge.push_back({s, e});
      edge.push_back({e, s});
    }
  }
  BFS(1);
  memset(mark, false, sizeof(mark));
  BFS_2(n);
  int answer = -1;
  int ind = -1;
  int mini = min(dis1[n], disn[1]);
  for (int i = 2; i <= n - 1; i++) {
    if (dis1[i] + disn[i] == mini) {
      int cur = d1[i] + dn[i];
      if (cur > answer) {
        ind = i;
      }
      answer = max(answer, cur);
    }
  }
  if (d1[n] > answer) {
    ind = n;
  }
  par1[1] = {-1, -1};
  parn[n] = {-1, -1};
  answer = max(answer, d1[n]);
  if (answer < dn[1]) {
    ind = 1;
  }
  answer = max(answer, dn[1]);
  cout << mini - answer + work - answer << endl;
  pp1(ind);
  pp2(ind);
  for (int i = 0; i < edge.size(); i++) {
    int x = edge[i].first;
    int y = edge[i].second;
    if (check[{x, y}] == false) {
      cout << x << " " << y << " " << 0 << endl;
      check[{x, y}] = true;
      check[{y, x}] = true;
    }
  }
}
