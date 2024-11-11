#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int n, m, i, j, t, v[1005];
vector<int> e[1005];
set<int> s;
int dfs(int x) {
  if (v[x] == 1) {
    printf("A %d\n", x);
    fflush(stdout);
    int y;
    scanf("%d", &y);
    if (s.count(y))
      return x;
    else
      return -1;
  }
  v[x] = 2;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (v[x] != 2) {
      int t = dfs(*it);
      if (t) return t;
    }
  return 0;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) e[i].clear();
    for (((i)) = (1); ((i)) <= ((n - 1)); ((i))++) {
      int x, y;
      scanf("%d%d", &x, &y);
      e[x].push_back(y);
      e[y].push_back(x);
    }
    scanf("%d", &m);
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) v[i] = 0;
    while (m--) {
      int x;
      scanf("%d", &x);
      v[x] = 1;
    }
    s.clear();
    scanf("%d", &m);
    while (m--) {
      int x;
      scanf("%d", &x);
      s.insert(x);
    }
    printf("B %d\n", *s.begin());
    fflush(stdout);
    int x;
    scanf("%d", &x);
    int t = dfs(x);
    printf("C %d\n", t);
    fflush(stdout);
  }
  return 0;
}
