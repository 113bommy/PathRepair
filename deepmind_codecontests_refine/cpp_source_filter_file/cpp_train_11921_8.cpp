#include <bits/stdc++.h>
using namespace std;
const int N = 760, M = 1e7 + 7;
int n, p[N], mat[N], bmat[N], ch[M][2], fail[M], las[M], tot, ans;
string s[N];
bitset<N> e[N], vis;
vector<int> ns;
void bfs() {
  queue<int> q;
  for (int i = 0, iE = 1; i <= iE; i++)
    if (ch[0][i]) q.push(ch[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (!las[u]) las[u] = las[fail[u]];
    for (int i = 0, iE = 1; i <= iE; i++) {
      if (ch[u][i])
        fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
      else
        ch[u][i] = ch[fail[u]][i];
    }
  }
}
bool dfs(int x) {
  for (int i = 1, iE = n; i <= iE; i++)
    if (e[x][i] && !vis[i]) {
      vis[i] = true;
      if (!mat[i] || dfs(mat[i])) {
        mat[i] = x;
        return 1;
      }
    }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, iE = n; i <= iE; i++) cin >> s[i], p[i] = i;
  for (int i = 1, iE = n; i <= iE; i++) {
    int now = 0;
    for (int j = 0, jE = s[i].size() - 1; j <= jE; j++) {
      if (!ch[now][s[i][j] - 'a']) ch[now][s[i][j] - 'a'] = ++tot;
      now = ch[now][s[i][j] - 'a'];
    }
    las[now] = i;
  }
  bfs();
  for (int i = 1, iE = n; i <= iE; i++) {
    int now = 0;
    for (int j = 0, jE = s[i].size() - 1; j <= jE; j++) {
      now = ch[now][s[i][j] - 'a'];
      if (j == (int)(s[i].size() - 1))
        e[i][las[fail[now]]] = true;
      else
        e[i][las[now]] = true;
    }
    e[i][0] = false;
  }
  sort(p + 1, p + n + 1,
       [&](int x, int y) { return s[x].size() < s[y].size(); });
  for (int i = 1, iE = n; i <= iE; i++)
    for (int j = 1, jE = n; j <= jE; j++)
      if (e[p[i]][j]) e[p[i]] |= e[j];
  for (int i = 1, iE = n; i <= iE; i++) vis.reset(), ans += dfs(i);
  for (int i = 1, iE = n; i <= iE; i++)
    if (mat[i]) bmat[mat[i]] = i;
  for (int i = 1, iE = n; i <= iE; i++)
    if (!bmat[i]) ns.push_back(i);
  while (1) {
    bool ok = false;
    vis.reset();
    for (int x : ns) vis |= e[x];
    for (int &x : ns)
      if (vis[x]) {
        ok = true;
        for (; x; x = mat[x])
          ;
      }
    if (!ok) break;
  }
  cout << n - ans << "\n";
  for (int x : ns) cout << x << " ";
  return 0;
}
