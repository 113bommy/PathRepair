#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 2 * N;
int h[N], e[M], ne[M], idx;
int n;
bool st[N];
int res[N];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
int dfs(int u) {
  st[u] = true;
  int sum = 1;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      int s = dfs(j);
      res[u] = max(res[u], s);
      sum += s;
    }
  }
  res[u] = max(res[u], n - sum);
  return sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(h, -1, sizeof h);
    memset(e, 0, sizeof e);
    memset(ne, 0, sizeof ne);
    idx = 0;
    memset(st, 0, sizeof st);
    memset(res, 0, sizeof res);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      add(a, b), add(b, a);
    }
    dfs(1);
    int minnum = M;
    for (int i = 1; i <= n; i++)
      if (res[i] < minnum) minnum = res[i];
    int bal[2] = {0};
    for (int i = 1, k = 0; i <= n; i++)
      if (res[i] == minnum) bal[k++] = i;
    if (bal[1] == 0)
      cout << 1 << " " << e[h[1]] << endl << 1 << " " << e[h[1]] << endl;
    else {
      for (int i = h[bal[0]]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j != bal[0] && j != bal[1]) {
          cout << bal[0] << " " << j << endl;
          cout << bal[1] << " " << j << endl;
          return 0;
        }
      }
    }
  }
}
