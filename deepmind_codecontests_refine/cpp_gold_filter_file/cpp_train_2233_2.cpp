#include <bits/stdc++.h>
using namespace std;
template <class T1>
void debug(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void debug(T1 e1, T2 e2) {
  cout << e1 << "\t" << e2 << endl;
}
template <class T1, class T2, class T3>
void debug(T1 e1, T2 e2, T3 e3) {
  cout << e1 << "\t" << e2 << "\t" << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void debug(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void debug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << "\t" << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void debug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << "\t" << e5 << "\t"
       << e6 << endl;
}
template <class T>
void debug(vector<vector<T> > e, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}
template <class T>
void debug(vector<basic_string<T> > e, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j];
    cout << endl;
  }
  cout << endl;
}
template <class T>
void debug(T e[110][110], int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j] << " ";
    cout << endl;
  }
}
template <class T>
string toString(T n) {
  ostringstream oss;
  oss << n;
  oss.flush();
  return oss.str();
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
bool isVowel(char ch) {
  ch = tolower(ch);
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}
bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
vector<int> adj[110000];
int n, m;
int x[110000];
int ones[110000];
bool col[110000];
int dfs(int node) {
  col[node] = true;
  ones[node] = x[node];
  for (int i = 0; i < ((int)adj[node].size()); i++) {
    int v = adj[node][i];
    if (col[v]) continue;
    ones[node] += dfs(v);
  }
  return ones[node];
}
vector<int> ans;
void updateans(int node) {
  if (x[node])
    x[node] = 0;
  else
    x[node] = 1;
  ans.push_back(node);
}
void dfs2(int node, int par, bool bck) {
  col[node] = true;
  ones[node] -= x[node];
  updateans(node);
  for (int i = 0; i < ((int)adj[node].size()); i++) {
    int v = adj[node][i];
    if (col[v]) continue;
    if (!ones[v]) continue;
    if (ones[node] == ones[v] && !bck && !x[node]) {
      ones[node] -= ones[v];
      dfs2(v, node, false);
      return;
    }
    ones[node] -= ones[v];
    dfs2(v, node, true);
    if (ones[node] != ones[v] || bck || x[node]) updateans(node);
  }
  if (bck && x[node]) {
    updateans(par);
    updateans(node);
  }
}
int main() {
  while (cin >> n >> m) {
    int i;
    for (i = 1; i <= n; i++) adj[i].clear();
    int a, b;
    for (i = 1; i <= m; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for (i = 1; i <= n; i++) cin >> x[i];
    memset(col, false, sizeof(col));
    int cnt = 0;
    for (i = 1; i <= n; i++) {
      if (col[i]) continue;
      if (dfs(i)) cnt++;
      if (cnt > 1) break;
    }
    if (i <= n) {
      cout << -1 << endl;
      continue;
    }
    memset(col, false, sizeof(col));
    ans.clear();
    for (i = 1; i <= n; i++) {
      if (col[i]) continue;
      if (!ones[i]) continue;
      dfs2(i, i, false);
      break;
    }
    cout << ((int)ans.size()) << endl;
    if (((int)ans.size()) == 0) continue;
    printf("%d", ans[0]);
    for (i = 1; i < ((int)ans.size()); i++) printf(" %d", ans[i]);
    cout << endl;
  }
  return 0;
}
