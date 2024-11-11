#include <bits/stdc++.h>
using namespace std;
int g[100][100];
int n;
int l1, r1, l2, r2;
long long t[52][52];
long long t1[52][52];
bool better(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
long long solve(int w, int l) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) t[i][j] = 0;
  t[0][0] = 1;
  for (int i = 0; i < n; i++) {
    bool cg =
        ((i != l) && better(make_pair(g[i][0], i), make_pair(g[w][0], w))) ||
        (i == w);
    bool cs = (i != w) && (i != l);
    if (cs) {
      cs = false;
      for (int j = 0; j < n - 1 && !cs; j++)
        if (better(make_pair(g[w][0], w), make_pair(g[i][j], i)) &&
            better(make_pair(g[i][j], i), make_pair(g[l][n - 2], l)))
          cs = true;
    }
    bool cl = (i != w &&
               better(make_pair(g[l][n - 2], l), make_pair(g[i][n - 2], i))) ||
              (i == l);
    for (int g = 0; g <= r1; g++)
      for (int s = 0; s <= r2; s++) t1[g][s] = 0;
    for (int g = 0; g <= r1; g++)
      for (int s = 0; s <= r2; s++) {
        if (cg) t1[g + 1][s] += t[g][s];
        if (cs) t1[g][s + 1] += t[g][s];
        if (cl) t1[g][s] += t[g][s];
      }
    for (int g = 0; g <= r1; g++)
      for (int s = 0; s <= r2; s++) t[g][s] = t1[g][s];
  }
  long long ans = 0;
  for (int i = l1; i <= r1; i++)
    for (int j = l1; j <= r1; j++) ans += t[i][j];
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) g[i][j] = (1 << 29) * (i != j);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a, --b;
    g[a][b] = min(g[a][b], c);
    g[b][a] = g[a][b];
  }
  scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for (int i = 0; i < n; i++) {
    swap(g[i][i], g[i][n - 1]);
    sort(g[i], g[i] + n - 1);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) ans += solve(i, j);
  cout << ans << endl;
  return 0;
}
