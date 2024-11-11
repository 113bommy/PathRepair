#include <bits/stdc++.h>
using namespace std;
int n, k;
char s1[100005], s2[100005];
vector<int> g[2 * 100005];
int d[3 * 100005];
int main() {
  scanf("%d %d\n", &n, &k);
  gets(s1);
  gets(s2);
  for (int i = 0; i < int(n); i++) {
    if (s1[i] == 'X') continue;
    if (i > 0 && s1[i - 1] == '-') {
      g[i].push_back(i - 1);
    }
    if ((i < n - 1 && s1[i + 1] == '-') || i == n - 1) {
      g[i].push_back(i + 1);
    }
    int j = min(i + k, n);
    if (j < n && s2[j] == 'X') continue;
    g[i].push_back(j + n + 1);
  }
  for (int i = 0; i < int(n); i++) {
    if (s2[i] == 'X') continue;
    if (i > 0 && s2[i - 1] == '-') {
      g[i + n + 1].push_back(i + n);
    }
    if ((i < n - 1 && s2[i + 1] == '-') || i == n - 1) {
      g[i + n + 1].push_back(i + n + 2);
    }
    int j = min(i + k, n);
    if (j < n && s1[j] == 'X') continue;
    g[i + n + 1].push_back(j);
  }
  queue<int> q;
  q.push(0);
  for (int i = 0; i < int(100005 * 3); i++) d[i] = 1000000009;
  d[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < int(g[u].size()); i++) {
      int v = g[u][i];
      if (d[v] > d[u] + 1 && d[u] + 1 <= (v % (n + 1))) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  if (min(d[n], d[n + n + 1]) < 1000000009)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
