#include <bits/stdc++.h>
using namespace std;
const int maxn = 110000;
inline int read() {
  int rtn = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) rtn = (rtn << 1) + (rtn << 3) + ch - '0';
  return rtn * f;
}
int n, fa[maxn], color[maxn], ans;
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) fa[i] = read();
  for (int i = 1; i <= n; i++) color[i] = read();
  for (int i = 1; i <= n; i++)
    if (color[i] != color[fa[i]]) ans++;
  printf("%d", ans);
  return 0;
}
