#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int head[500005], Next[500005], vet[500005], c[500005];
long long t, T;
long long l[500005], r[500005];
void add(int x, int y) {
  cnt++;
  Next[cnt] = head[x];
  head[x] = cnt;
  vet[cnt] = y;
}
bool dfs(int x) {
  for (int i = head[x]; i; i = Next[i]) {
    int v = vet[i];
    if (!c[v])
      c[v] = 3 - c[x], dfs(v);
    else if (c[v] == c[x])
      return false;
  }
  return true;
}
int main() {
  cin >> t >> T;
  cin >> n >> m;
  long long n1 = 1e17, n2 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &l[i], &r[i]);
    n1 = min(n1, r[i]);
    n2 = max(n2, l[i]);
  }
  if (n1 + n2 < t) n2 = t - n1;
  if (n1 + n2 > T) n1 = T - n2;
  if (n1 < 0 && n2 < 0) {
    puts("IMPOSSIBLE");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int f1 = (l[i] <= n1 && n1 <= r[i]), f2 = (l[i] <= n2 && n2 <= r[i]);
    if (!f1 && !f2) {
      puts("IMPOSSIBLE");
      return 0;
    } else if (f1 && !f2)
      c[i] = 1;
    else if (!f1 && f2)
      c[i] = 2;
  }
  int x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  for (int i = 1; i <= n; i++) {
    if (!c[i]) continue;
    if (!dfs(i)) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (c[i]) continue;
    c[i] = 1;
    if (!dfs(i)) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }
  puts("POSSIBLE");
  cout << n1 << " " << n2 << endl;
  for (int i = 1; i <= n; i++) {
    putchar(c[i] + '0');
  }
  return 0;
}
