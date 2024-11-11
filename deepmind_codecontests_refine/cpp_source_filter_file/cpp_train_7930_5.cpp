#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, q, b[N], num[N], h = 0;
int vis[N], st[N], ed[N];
struct node {
  int z, id;
} a[N];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void init() {
  q = read();
  while (q-- > 0) {
    int ans = 0, t = 1;
    n = read();
    h = 0;
    for (int i = (1); i <= (n); i++) vis[i] = 0;
    for (int i = (1); i <= (n); i++)
      a[i].z = read(), b[i] = a[i].z, a[i].id = i;
    sort(b + 1, b + n + 1);
    int p = b[1];
    num[++h] = p;
    for (int i = (2); i <= (n); i++)
      if (b[i] != p) {
        p = b[i];
        num[++h] = p;
      }
    for (int i = (1); i <= (n); i++) {
      if (!vis[a[i].z]) vis[a[i].z] = 1, st[a[i].z] = i;
      ed[a[i].z] = i;
    }
    for (int i = (2); i <= (h); i++) {
      if (st[num[i]] >= ed[num[i - 1]])
        t++;
      else
        t = 1;
      ans = max(ans, t);
    }
    printf("%d\n", h - ans);
  }
}
int main() {
  init();
  return 0;
}
