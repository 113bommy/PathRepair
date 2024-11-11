#include <bits/stdc++.h>
const int N = 1e6 + 50;
const int M = 8e4 + 50;
const int Q = 12e3 + 50;
int pri[M], vis[N], fss[Q], cnt, tot, n;
int sum(int u) {
  int res = 0;
  while (u) {
    res = res * 10 + u % 10;
    u /= 10;
  }
  return res;
}
void pre(int u) {
  pri[++tot] = 2;
  for (int i = 3; i <= u; i += 2)
    if (!vis[i]) {
      pri[++tot] = i;
      for (int j = i * 2; j <= u; j += i)
        if (!vis[j]) vis[j] = 1;
    }
  for (int i = 1; i <= tot; i++) {
    int q = sum(pri[i]);
    if (!vis[q] && q & 1 && q != pri[i]) fss[++cnt] = pri[i];
  }
}
int main() {
  pre(N - 50);
  while (scanf("%d", &n) != EOF) printf("%d\n", fss[n]);
}
