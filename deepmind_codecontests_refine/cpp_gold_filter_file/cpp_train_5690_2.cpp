#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 69;
int visit[N][2], trace[N][2], check[N], num[N], low[N], Time, n, m, s, oo = 1e9;
vector<pair<int, int> > edge;
vector<int> a[N];
void bfs() {
  visit[s][0] = 1;
  queue<pair<int, int> > q;
  q.push(make_pair(s, 0));
  while (!q.empty()) {
    int u = q.front().first, c = q.front().second;
    q.pop();
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      if (visit[v][c ^ 1] == 0) {
        visit[v][c ^ 1] = 1;
        q.push(make_pair(v, c ^ 1));
        trace[v][c ^ 1] = u;
      }
    }
  }
}
void tv(int u) {
  int c = 1;
  stack<int> luu;
  while (u != s || c) {
    luu.push(u);
    u = trace[u][c];
    c ^= 1;
  }
  luu.push(s);
  cout << "Win\n";
  while (!luu.empty()) cout << luu.top() << ' ', luu.pop();
}
stack<int> st;
void dfs(int u) {
  num[u] = low[u] = ++Time;
  st.push(u);
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (num[u] == low[u]) {
    int v;
    do {
      v = st.top();
      st.pop();
      low[u] = num[v] = oo;
      if (v != u && (visit[u][0] || visit[u][1])) {
        cout << "Draw";
        exit(0);
      }
    } while (v != u);
  }
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    for (int j = 1; j <= c; j++) {
      int k;
      cin >> k;
      a[i].push_back(k);
      edge.push_back(make_pair(i, k));
    }
  }
  cin >> s;
  bfs();
  for (int i = 1; i <= n; i++) {
    if (a[i].size() == 0 && visit[i][1]) {
      tv(i);
      return 0;
    }
  }
  for (int i = 1; i <= n; i++)
    if (num[i] == 0) dfs(i);
  cout << "Lose";
}
