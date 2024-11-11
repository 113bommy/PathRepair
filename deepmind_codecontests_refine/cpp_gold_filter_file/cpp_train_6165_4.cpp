#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 20 * 20, E_MAX = 20 * 20 * 4;
int t, n, m, grid[20][20];
char maze[40][40];
vector<int> G[N_MAX];
int N = 0, E = 0, id[N_MAX][N_MAX], inP[E_MAX];
vector<vector<int>> P;
vector<int> bound;
pair<int, int> edge[E_MAX];
bool inF[E_MAX], inS1[E_MAX], inS2[E_MAX], seen[N_MAX];
vector<int> F[N_MAX], D[E_MAX];
int comp[N_MAX], in_class[E_MAX], p[E_MAX], between[N_MAX][N_MAX];
queue<int> q;
void max_ind() {
  for (int e = 0; e < E; e++) inF[e] = false;
  for (int i = 0; i < N; i++) F[i].clear();
  for (int e = 0; e < E; e++) D[e].clear();
  for (int i = 0; i < P.size(); i++) in_class[i] = 0;
  while (true) {
    for (int i = 0; i < N; i++) comp[i] = -1;
    int C = 0;
    for (int i = 0; i < N; i++) {
      if (comp[i] != -1) continue;
      q.push(i);
      comp[i] = C;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : F[u])
          if (comp[v] == -1) {
            comp[v] = C;
            q.push(v);
          }
      }
      C++;
    }
    for (int e = 0; e < E; e++) {
      inS1[e] = (comp[edge[e].first] != comp[edge[e].second]);
      inS2[e] = (in_class[inP[e]] < bound[inP[e]]);
    }
    int inc = 0;
    while (inc < E && !(inS1[inc] && inS2[inc])) inc++;
    if (inc < E) {
      inF[inc] = true;
      int u = edge[inc].first, v = edge[inc].second;
      F[u].push_back(v);
      F[v].push_back(u);
      if (inP[inc] != -1) in_class[inP[inc]]++;
      continue;
    }
    for (int e = 0; e < E; e++) D[e].clear();
    for (int f = 0; f < E; f++) {
      if (inS1[f] || inF[f]) continue;
      int u = edge[f].first, v = edge[f].second;
      for (int i = 0; i < E; i++) p[i] = -1;
      q.push(u);
      p[u] = u;
      while (p[v] == -1) {
        int x = q.front();
        q.pop();
        for (int y : F[x])
          if (p[y] == -1) {
            p[y] = x;
            q.push(y);
          }
      }
      queue<int>().swap(q);
      int w = v;
      while (p[w] != w) {
        D[id[p[w]][w]].push_back(f);
        w = p[w];
      }
    }
    for (int e = 0; e < E; e++) {
      if (inS2[e] || inF[e]) continue;
      for (int f : P[inP[e]])
        if (inF[f]) D[e].push_back(f);
    }
    for (int e = 0; e < E; e++) {
      if (inS1[e]) {
        q.push(e);
        p[e] = e;
      } else
        p[e] = -1;
    }
    int sol = -1;
    while (!q.empty() && sol == -1) {
      int e = q.front();
      q.pop();
      for (int f : D[e]) {
        if (p[f] != -1) continue;
        p[f] = e;
        q.push(f);
        if (inS2[f]) {
          sol = f;
          break;
        }
      }
    }
    queue<int>().swap(q);
    if (sol == -1) return;
    bool add = true;
    int e = sol;
    while (p[e] != e) {
      inF[e] = add;
      in_class[inP[e]] += (add ? 1 : -1);
      add = !add;
      e = p[e];
    }
    inF[e] = true;
    in_class[inP[e]]++;
    for (int i = 0; i < N; i++) F[i].clear();
    for (int e = 0; e < E; e++) {
      if (!inF[e]) continue;
      int u = edge[e].first, v = edge[e].second;
      F[u].push_back(v);
      F[v].push_back(u);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    N = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == 'X')
          grid[i][j] = -1;
        else
          grid[i][j] = N++;
      }
    }
    E = 0;
    for (int i = 0; i < N; i++) {
      G[i].clear();
      for (int j = 0; j < N; j++) id[i][j] = -1;
    }
    P.clear();
    bound.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == -1) continue;
        int u = grid[i][j];
        if (i < n - 1 && grid[i + 1][j] != -1) {
          int v = grid[i + 1][j];
          id[u][v] = id[v][u] = E;
          edge[E++] = {u, v};
          G[u].push_back(v);
          G[v].push_back(u);
        }
        if (j < m - 1 && grid[i][j + 1] != -1) {
          int v = grid[i][j + 1];
          id[u][v] = id[v][u] = E;
          edge[E++] = {u, v};
          G[u].push_back(v);
          G[v].push_back(u);
        }
        if ((i + j) % 2 == 0 && i + j != 0) {
          P.push_back(vector<int>());
          if (0 < i && grid[i - 1][j] != -1)
            P.back().push_back(id[u][grid[i - 1][j]]);
          if (0 < j && grid[i][j - 1] != -1)
            P.back().push_back(id[u][grid[i][j - 1]]);
          if (i < n - 1 && grid[i + 1][j] != -1)
            P.back().push_back(id[u][grid[i + 1][j]]);
          if (j < m - 1 && grid[i][j + 1] != -1)
            P.back().push_back(id[u][grid[i][j + 1]]);
          bound.push_back(2);
        }
      }
    }
    for (int e = 0; e < E; e++) inP[e] = -1;
    for (int i = 0; i < P.size(); i++)
      for (int e : P[i]) inP[e] = i;
    P.push_back(vector<int>());
    bound.push_back(0);
    for (int e = 0; e < E; e++) {
      if (inP[e] == -1) {
        P.back().push_back(e);
        inP[e] = P.size();
        inP[e]--;
      }
    }
    max_ind();
    int s = 0;
    for (int e = 0; e < E; e++)
      if (inF[e]) s++;
    if (s + 2 != 2 * P.size()) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout.flush();
    for (int i = 0; i < N; i++) comp[i] = -1;
    int C = 0;
    for (int i = 0; i < N; i++) {
      if (comp[i] != -1) continue;
      comp[i] = C;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : F[u]) {
          if (comp[v] != -1) continue;
          comp[v] = C;
          q.push(v);
        }
      }
      C++;
    }
    for (int i = 0; i < C; i++)
      for (int j = 0; j < C; j++) between[i][j] = -1;
    for (int e = 0; e < E; e++) {
      int u = edge[e].first, v = edge[e].second;
      if (!inF[e] && comp[u] != comp[v] && between[comp[u]][comp[v]] == -1)
        between[comp[u]][comp[v]] = between[comp[v]][comp[u]] = e;
    }
    for (int i = 0; i < N; i++) seen[i] = false;
    seen[0] = true;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 0; v < C; v++) {
        if (between[u][v] != -1 && !seen[v]) {
          inF[between[u][v]] = true;
          q.push(v);
          seen[v] = true;
        }
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        maze[2 * i][2 * j] = (grid[i][j] == -1 ? 'X' : 'O');
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        int u = grid[i][j], v = grid[i][j + 1];
        maze[2 * i][2 * j + 1] =
            (u != -1 && v != -1 && !inF[id[u][v]] ? ' ' : '*');
      }
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        int u = grid[i][j], v = grid[i + 1][j];
        maze[2 * i + 1][2 * j] =
            (u != -1 && v != -1 && !inF[id[u][v]] ? ' ' : '*');
      }
    }
    for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < m - 1; j++) maze[2 * i + 1][2 * j + 1] = '*';
    for (int i = 0; i < 2 * n - 1; i++) {
      for (int j = 0; j < 2 * m - 1; j++) cout << maze[i][j];
      cout << "\n";
    }
  }
  return 0;
}
