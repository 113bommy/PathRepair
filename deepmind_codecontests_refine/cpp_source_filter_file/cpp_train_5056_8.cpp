#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
int n;
int a[200005], ch[200005][22], ans[200005];
long long s[200005];
struct AB {
  int a, b, c, n;
} d[200005];
int tot, h[200005];
void charu(int a, int b, int c) {
  d[++tot].a = a, d[tot].b = b, d[tot].c = c, d[tot].n = h[a], h[a] = tot;
}
void dfs(int u) {
  for (int i = 1; i <= 5; i++) ch[u][i] = ch[ch[u][i - 1]][i - 1];
  int now = u;
  for (int i = 5; i >= 0; i--) {
    if (s[u] - s[ch[now][i]] <= a[u]) now = ch[now][i];
  }
  ans[ch[now][0]]--;
  ans[ch[u][0]]++;
  for (int k = h[u]; k; k = d[k].n) {
    int v = d[k].b, c = d[k].c;
    ch[v][0] = u, s[v] = s[u] + c;
    dfs(v);
    ans[u] += ans[v];
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 2; i <= n; i++) {
    int a = read(), b = read();
    charu(a, i, b);
  }
  s[0] = -1e18;
  dfs(1);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
