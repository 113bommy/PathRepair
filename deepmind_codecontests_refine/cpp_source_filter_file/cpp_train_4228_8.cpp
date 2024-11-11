#include <bits/stdc++.h>
using namespace std;
inline int readInt() {
  int n = 0, ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
  return n;
}
const int MAX_N = 1000 + 3;
int n, a[MAX_N], b[MAX_N];
int vis[MAX_N];
int main() {
  n = readInt();
  int p1 = -1, p2 = -1;
  for (int i = 0; i < n; ++i) a[i] = readInt();
  for (int i = 0; i < n; ++i) b[i] = readInt();
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i]) {
      if (p1 == -1)
        p1 = i;
      else
        p2 = i;
    } else
      vis[a[i]] = true;
  if (p2 == -1) {
    int t = 0;
    for (int i = 1; i <= n; ++i)
      if (!vis[i]) t = i;
    a[p1] = t;
  } else {
    if (!vis[b[p1]] && !vis[a[p1]])
      a[p1] = b[p1];
    else
      a[p2] = b[p2];
  }
  for (int i = 0; i < n; ++i) cout << a[i] << (i + 1 == n ? '\n' : ' ');
  return 0;
}
