#include <bits/stdc++.h>
int x4[4] = {0, 0, -1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;
int n, m;
int a, b, c;
int cur[200005];
int in[200005];
vector<int> adjList[200005];
vector<pair<int, int> > edgeList;
queue<int> q;
int nextnode, curnode;
map<pair<int, int>, int> edgeDir;
map<pair<int, int>, int> cap;
int main() {
  memset(cur, 0, sizeof(cur));
  memset(in, 0, sizeof(in));
  for (int i = 0; i < 200005; i++) adjList[i].clear();
  edgeList.clear();
  edgeDir.clear();
  cap.clear();
  while (!q.empty()) q.pop();
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &c);
    cur[a] += c;
    cur[b] += c;
    edgeList.push_back(make_pair(a, b));
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    cap[make_pair(a, b)] = cap[make_pair(b, a)] = c;
  }
  q.push(1);
  while (!q.empty()) {
    curnode = q.front();
    q.pop();
    for (int i = 0; i < adjList[curnode].size(); i++) {
      nextnode = adjList[curnode][i];
      if (edgeDir[make_pair(curnode, nextnode)] == 0) {
        edgeDir[make_pair(curnode, nextnode)] = 1;
        edgeDir[make_pair(nextnode, curnode)] = 2;
        in[nextnode] += cap[make_pair(1, nextnode)];
        if (in[nextnode] * 2 == cur[nextnode] && nextnode != n)
          q.push(nextnode);
      }
    }
  }
  for (int i = 0; i < edgeList.size(); i++) {
    if (edgeList[i].first == n)
      printf("1\n");
    else if (edgeList[i].second == n)
      printf("0\n");
    else
      printf("%d\n",
             edgeDir[make_pair(edgeList[i].first, edgeList[i].second)] - 1);
  }
  return 0;
}
