#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
int n, m, ans[N];
bitset<4> temp;
vector<int> g[N];
vector<bitset<4>> v;
void fix(int u) {
  temp = 0;
  for (auto i : g[u]) temp[i] = 1;
  if (g[u].size() & 1) temp[u] = temp[n] = 1;
}
void add() {
  int at = 0;
  for (int i = 0; i < v.size(); i++) {
    while (at + 1 < n && !v[i][at] && !temp[at]) at++;
    if (!v[i][at] && temp[at]) {
      v.insert(v.begin() + i, temp);
      return;
    }
    if (v[i][at] && temp[at]) temp ^= v[i];
  }
  if (temp.any()) v.push_back(temp);
}
void find() {
  for (int i = v.size() - 1; i + 1; i--) {
    int mn = 1e9;
    for (int j = n - 1; j + 1; j--) {
      if (!v[i][j]) continue;
      mn = j;
      v[i][n] = bool(v[i][n] ^ ans[j]);
    }
    ans[mn] = v[i][n];
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf(" %d%d", &n, &m);
    v.clear();
    for (int i = 0; i < n; i++) ans[i] = 0, g[i].clear();
    for (int i = 0, a, b; i < m; i++) {
      scanf("%d%d", &a, &b);
      g[--a].push_back(--b);
      g[b].push_back(a);
    }
    bool bad = 0;
    for (int i = 0; i < n; i++) {
      temp = 0;
      if (g[i].size() & 1) bad = 1;
      fix(i);
      add();
    }
    if (!bad) {
      puts("1");
      for (int i = 0; i < n; i++) printf("1 ");
      puts("");
      continue;
    }
    find();
    puts("2");
    for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
    puts("");
  }
}
