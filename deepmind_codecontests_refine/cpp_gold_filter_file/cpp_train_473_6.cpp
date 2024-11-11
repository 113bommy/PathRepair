#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
template <class T>
inline void read(T &num) {
  T x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  num = f * x;
}
int n;
int f[N];
int g[N], h[N];
int cnt;
bool vis[N];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (f[f[i]] != f[i]) {
      printf("-1");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[f[i]]) {
      h[++cnt] = f[i];
      vis[f[i]] = 1;
      g[f[i]] = cnt;
    }
    g[i] = g[f[i]];
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++) {
    printf("%d ", g[i]);
  }
  printf("\n");
  for (int i = 1; i <= cnt; i++) {
    printf("%d ", h[i]);
  }
}
