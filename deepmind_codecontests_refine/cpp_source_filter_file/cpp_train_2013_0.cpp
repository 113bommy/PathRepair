#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
int n, m, col[N], freq[2], ans[N], rem = 1;
bool vis[N];
vector<int> g[N];
void dfs(int u) {
  for (auto i : g[u])
    if (col[i] == -1) {
      col[i] = !col[u];
      dfs(i);
    }
}
void print() {
  int lol = 0;
  for (int i = 0; i < n; i++) {
    if (!col[i] && !ans[i]) {
      lol++;
      ans[i] = rem;
    }
    if (lol == 3) rem++, lol = 0;
  }
  for (int i = 0; i < n; i++) {
    if (col[i] && !ans[i]) {
      lol++;
      ans[i] = rem;
    }
    if (lol == 3) rem++, lol = 0;
  }
  puts("YES");
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  exit(0);
}
void fix(int a) {
  memset(vis, 0, sizeof vis);
  for (auto i : g[a]) vis[i] = 1;
  ans[a] = rem;
  int need = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    if (need == 2) break;
    if (col[i] == col[a] || vis[i]) continue;
    ans[i] = rem;
    need++;
  }
  rem++;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(col, -1, sizeof col);
  for (int i = 0, a, b; i < m; i++) {
    scanf("%d%d", &a, &b);
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
    if (col[i] == -1) {
      col[i] = 0;
      dfs(i);
    }
  for (int i = 0; i < n; i++) freq[col[i]]++;
  if (freq[0] % 3 == 0 && freq[1] % 3 == 0) print();
  if (freq[0] % 3 == 2) {
    swap(freq[0], freq[1]);
    for (int i = 0; i < n; i++) col[i] ^= 1;
  }
  if (freq[0] % 3 != 0) {
    for (int i = 0; i < n; i++)
      if (!col[i]) {
        int sz = freq[1] - g[i].size();
        if (sz > 1) {
          fix(i);
          print();
        }
      }
    int x = -1, y = -1;
    for (int i = 0; i < n && y != -1; i++)
      if (col[i]) {
        int sz = freq[0] - g[i].size();
        if (sz > 1) {
          if (x == -1)
            x = i;
          else
            y = i;
        }
      }
    if (x != -1 && y != -1) {
      fix(x);
      fix(y);
      print();
    }
  }
  puts("NO");
}
