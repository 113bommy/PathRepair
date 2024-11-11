#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
template <class T>
void read(T &val) {
  T x = 0;
  T bz = 1;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') {
    bz = -1;
    c = getchar();
  }
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  val = x * bz;
}
const int mod = 998244353;
const int maxn = 1e6 + 10;
int n, m, a[maxn], q, t;
char s[maxn];
int mp[505][550];
vector<int> g[505];
int col[maxn], flag;
void dfs(int u) {
  for (auto to : g[u]) {
    if (col[to]) {
      if (col[u] == col[to]) flag = 1;
    } else {
      col[to] = 3 - col[u];
      dfs(to);
    }
  }
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    read(u);
    read(v);
    mp[u][v] = mp[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!mp[i][j]) g[i].push_back(j), g[j].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!col[i] && g[i].size())
      col[i] = 1, dfs(i);
    else if (!col[i])
      col[i] = 3;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (mp[i][j]) {
        if (abs(col[i] + col[j]) == 3) flag = 1;
      }
    }
  }
  if (flag) {
    puts("No");
  } else {
    puts("Yes");
    for (int i = 1; i <= n; i++) {
      if (col[i] == 1)
        printf("a");
      else if (col[i] == 2)
        printf("c");
      else
        printf("b");
    }
    puts("");
  }
  return 0;
}
