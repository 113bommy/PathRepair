#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}
template <typename T, typename... U>
inline void read(T& x, U&... y) {
  read(x), read(y...);
}
int n, m;
bool vis[55];
char S[55][55];
int main() {
  read(n, m);
  for (int i = 1; i <= n; ++i) scanf("%s", S[i] + 1);
  bool OK = true;
  for (int i = 1; i <= m; ++i) {
    memset(vis, 0, sizeof(vis));
    for (int j = 1; j <= n; ++j)
      if (S[j][i] == '#') vis[j] = true;
    for (int j = 1; j <= m; ++j) {
      bool t1 = false, t2 = false;
      for (int k = 1; k <= n; ++k) {
        if (S[k][j] == '#') {
          if (vis[k])
            t1 = true;
          else
            t2 = true;
        }
      }
      if (t1 & t2) OK = false;
    }
  }
  puts(OK ? "Yes" : "No");
  return 0;
}
