#include <bits/stdc++.h>
using namespace std;
const int N = 8e3 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, in[N], inp[N], inq[N];
char s[N];
bool G[N][N], vis[N];
long long ans;
int get_num(char c) {
  if (isdigit(c)) return c - '0';
  return c - 'A' + 10;
}
int get_bit(char c, int p) { return get_num(c) >> (3 - p) & 1; }
bool cmp(int x, int y) { return G[x][y]; }
long long C2(int n) { return 1ll * n * (n - 1) / 2; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++) {
      G[i][j] = get_bit(s[(j + 3) / 4], (j + 3) % 4);
      if (G[i][j]) ++in[j];
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i);
  memset(vis, 1, sizeof(vis));
  int rem = n;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    --rem;
    vis[u] = 0;
    ans += (614 * n + 1) * rem;
    for (int v = 1; v <= n; v++)
      if (G[u][v]) {
        --in[v];
        if (!in[v]) q.push(v);
      }
  }
  if (!rem) return cout << ans, 0;
  int x = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i] && (!x || in[i] > in[x])) x = i;
  vector<int> P, Q;
  for (int i = 1; i <= n; i++)
    if (vis[i]) {
      if (i == x || G[i][x])
        P.push_back(i);
      else
        Q.push_back(i);
    }
  sort(P.begin(), P.end(), cmp);
  sort(Q.begin(), Q.end(), cmp);
  for (auto a : P)
    for (auto b : Q)
      if (G[b][a])
        ++inq[a];
      else
        ++inp[b];
  ans += C2(int(P.size()));
  for (int i = 0; i < int(P.size()); i++)
    for (int j = i + 1; j < int(P.size()); j++)
      if (inq[P[i]] == inq[P[j]])
        ans += 3;
      else
        ans += 2;
  ans += C2(int(Q.size()));
  for (int i = 0; i < int(Q.size()); i++)
    for (int j = i + 1; j < int(Q.size()); j++)
      if (inp[Q[i]] == inp[Q[j]])
        ans += 3;
      else
        ans += 2;
  ans += 3 * int(P.size()) * int(Q.size());
  cout << ans;
  return 0;
}
