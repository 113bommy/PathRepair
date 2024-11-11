#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
int v[MAX], vis[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int> > SCC;
int DFS(int curr) {
  dfsn[curr] = ++cnt;
  S.push(curr);
  int result = dfsn[curr];
  for (int next : adj[curr]) {
    if (dfsn[next] == 0)
      result = min(result, DFS(next));
    else if (!finished[next])
      result = min(result, dfsn[next]);
  }
  if (result == dfsn[curr]) {
    vector<int> currSCC;
    while (1) {
      int t = S.top();
      S.pop();
      currSCC.push_back(t);
      finished[t] = true;
      sn[t] = SN;
      if (t == curr) break;
    }
    sort(currSCC.begin(), currSCC.end());
    SCC.push_back(currSCC);
    SN++;
  }
  return result;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &V, &E);
    cnt = 0;
    SN = 0;
    for (int e = 0; e <= V; e++) {
      dfsn[e] = 0;
      sn[e] = 0;
      adj[e].clear();
      v[e] = 0;
      vis[e] = 0;
      finished[e] = false;
    }
    while (!S.empty()) S.pop();
    SCC.clear();
    for (int i = 0; i < E; i++) {
      int A, B;
      scanf("%d %d", &A, &B);
      if (A == B) continue;
      adj[A - 1].push_back(B - 1);
    }
    for (int i = 0; i < V; i++)
      if (dfsn[i] == 0) DFS(i);
    for (int e = 0; e < V; e++) {
      for (int p = 0; p < adj[e].size(); p++) {
        int next = adj[e][p];
        if (sn[e] != sn[next]) {
          v[sn[e]]++;
        }
      }
    }
    int wh = -1;
    for (int e = 0; e < SN; e++)
      if (v[e] == 0) wh = e;
    if (wh == -1)
      printf("No\n");
    else {
      vector<int> f, s;
      for (int e = 0; e < SCC[wh].size(); e++) {
        int now = SCC[wh][e];
        f.push_back(now + 1);
        vis[now] = 1;
      }
      for (int e = 0; e < V; e++)
        if (vis[e] == 0) s.push_back(e + 1);
      if (f.size() == 0 || s.size() == 0)
        printf("No\n");
      else {
        printf("Yes\n");
        printf("%d %d\n", f.size(), s.size());
        for (int p = 0; p < f.size(); p++) printf("%d ", f[p]);
        printf("\n");
        for (int p = 0; p < s.size(); p++) printf("%d ", s[p]);
        printf("\n");
      }
    }
  }
}
