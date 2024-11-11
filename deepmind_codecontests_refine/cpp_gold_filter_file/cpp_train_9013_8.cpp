#include <bits/stdc++.h>
double pi = acos(-1.0);
using namespace std;
int n, m, s, x, u, t;
int col[300050];
vector<int> v[300050], g[300050];
vector<int>::iterator it;
int cnt;
set<int> st;
set<int>::iterator it2;
void dfs(int now, int pre) {
  if (pre == -1) {
    for (it = v[now].begin(); it != v[now].end(); it++) {
      col[*it] = ++cnt;
    }
    for (int i = 0; i < g[now].size(); i++) {
      int p = g[now][i];
      if (p == pre) continue;
      dfs(p, now);
    }
    return;
  }
  st.clear();
  for (it = v[now].begin(); it != v[now].end(); it++) {
    if (col[*it]) {
      st.insert(col[*it]);
    }
  }
  int top = 1, temp = 0;
  it2 = st.begin();
  for (it = v[now].begin(); it != v[now].end(); it++) {
    if (!col[*it]) {
      while (temp < st.size()) {
        if (top == *it2)
          top++, it2++, temp++;
        else
          break;
      }
      cnt = max(cnt, top);
      col[*it] = top++;
    }
  }
  for (int i = 0; i < g[now].size(); i++) {
    int p = g[now][i];
    if (p == pre) continue;
    dfs(p, now);
  }
}
int main() {
  cnt = 0;
  for (int i = 1; i <= m; i++) col[i] = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s);
    for (int j = 0; j < s; j++) {
      scanf("%d", &x);
      v[i].push_back(x);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &t);
    g[u].push_back(t);
    g[t].push_back(u);
  }
  dfs(1, -1);
  int flag = 0;
  for (int i = 1; i <= m; i++) {
    if (col[i] == 0)
      col[i] = 1;
    else
      flag = 1;
  }
  if (flag)
    cout << cnt << endl;
  else
    cout << 1 << endl;
  for (int i = 1; i <= m; i++) {
    printf("%d%c", col[i], " \n"[i == m]);
  }
  return 0;
}
