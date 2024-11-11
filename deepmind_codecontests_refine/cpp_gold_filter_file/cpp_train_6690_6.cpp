#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool d = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') d = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return d ? x : -x;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void writep(long long x) {
  write(x);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 5e5 + 5;
int dep[N], fa[N], mx, rt;
vector<long long> v[N], rv[N];
bool used[N];
void dfs(int u) {
  if (dep[u] >= mx) mx = dep[u], rt = u;
  rv[dep[u]].push_back(u);
  used[u] = 1;
  for (auto k : v[u]) {
    if (used[k]) continue;
    dep[k] = dep[u] + 1;
    fa[k] = u;
    dfs(k);
  }
}
int main() {
  int T = read();
  while (T--) {
    int n = read(), m = read();
    mx = -1;
    for (int i = (int)(0); i <= (int)(n); i++) {
      v[i].clear();
      rv[i].clear();
      used[i] = fa[i] = dep[i] = 0;
    }
    for (int i = (int)(1); i <= (int)(m); i++) {
      int x = read(), y = read();
      v[x].push_back(y);
      v[y].push_back(x);
    }
    dfs(1);
    vector<pair<int, int> > ans;
    for (int i = (int)(0); i <= (int)(n); i++) {
      for (int j = 0; j < (int)rv[i].size() - 1; j += 2) {
        ans.push_back(make_pair(rv[i][j], rv[i][j + 1]));
      }
    }
    if (ans.size() * 2 >= (n + 1) / 2) {
      puts("PAIRING");
      writeln(ans.size());
      for (auto x : ans) writep(x.first), writeln(x.second);
    } else {
      int u = rt;
      vector<long long> pcc;
      while (u) {
        pcc.push_back(u);
        u = fa[u];
      }
      puts("PATH");
      writeln((int)pcc.size());
      for (auto x : pcc) writep(x);
      puts("");
    }
  }
}
