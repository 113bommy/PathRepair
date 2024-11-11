#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
vector<int> G[maxn];
inline int read() {
  int x = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
int a[maxn], ans[maxn];
int fa[maxn];
bool f[maxn];
vector<int> b;
int getf(int p) {
  if (p == fa[p])
    return p;
  else
    return getf(fa[p]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) fa[i] = 1;
  ans[0] = 1;
  ans[n] = 1;
  int pos = n + 1;
  printf("1");
  for (int i = 1; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    f[p] = true;
    while (pos > 1 && f[pos - 1]) pos--;
    printf(" %d", i + 1 - (n - pos + 1));
  }
}
