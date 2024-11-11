#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
template <typename T>
void read(T &x) {
  T flag = 1;
  char ch = getchar();
  for (; '0' > ch || ch > '9'; ch = getchar())
    if (ch == '-') flag = -1;
  for (x = 0; '0' <= ch && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  x *= flag;
}
int T;
int n, m;
vector<int> vec[MAXN], grade[MAXN];
int dep[MAXN], fa[MAXN];
void dfs(int x) {
  grade[dep[x]].push_back(x);
  for (auto y : vec[x]) {
    if (!dep[y]) {
      fa[y] = x;
      dep[y] = dep[x] + 1;
      dfs(y);
    }
  }
}
int main() {
  read(T);
  while (T--) {
    for (int i = 1; i <= n; i++)
      vec[i].clear(), dep[i] = 0, fa[i] = 0, grade[i].clear();
    read(n);
    read(m);
    for (int i = 1; i <= m; i++) {
      int x, y;
      read(x);
      read(y);
      vec[x].push_back(y);
      vec[y].push_back(x);
    }
    dep[1] = 1;
    dfs(1);
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, dep[i]);
    if (mx >= (n + 1) / 2) {
      printf("PATH\n%d\n", mx);
      int now;
      for (int i = 1; i <= n; i++) {
        if (dep[i] == mx) {
          now = i;
          break;
        }
      }
      while (now) {
        printf("%d ", now);
        now = fa[now];
      }
      puts("");
    } else {
      int cnt = 0;
      for (int i = 1; i <= mx; i++) cnt += grade[i].size() / 2;
      printf("PAIRING\n%d\n", cnt);
      for (int i = 1; i <= mx; i++) {
        for (int j = 0; j < grade[i].size(); j += 2) {
          if (j + 1 < grade[i].size()) {
            printf("%d %d\n", grade[i][j], grade[i][j + 1]);
          }
        }
      }
    }
  }
  return 0;
}
