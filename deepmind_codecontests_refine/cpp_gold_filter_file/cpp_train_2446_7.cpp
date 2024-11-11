#include <bits/stdc++.h>
long long g[20][256][2520];
bool ok[256][2520];
inline int trans(int x) {
  if (x < 2) return 0;
  return (1 << (x - 2));
}
inline void prework() {
  for (int s = 0; s < 256; s++) {
    for (int v = 0; v < 2520; v++) {
      ok[s][v] = 1;
      for (int t = 2; t <= 9; t++) {
        if ((s >> (t - 2)) & 1) {
          if (v % t) {
            ok[s][v] = 0;
            break;
          }
        }
      }
    }
  }
  return;
}
long long DFS(int s, int v, int rest) {
  if (!rest) return ok[s][v];
  if (g[rest][s][v] != -1) return g[rest][s][v];
  long long ans = 0;
  for (int i = 0; i <= 9; i++) {
    ans += DFS(s | trans(i), (v * 10 + i) % 2520, rest - 1);
  }
  return g[rest][s][v] = ans;
}
inline long long work(long long x) {
  long long ans = 0;
  int temp[20], top = 0;
  while (x) {
    temp[top] = x % 10;
    x /= 10;
    top++;
  }
  int S = 0, V = 0;
  for (int i = top - 1; i >= 0; i--) {
    for (int j = 0; j < temp[i]; j++) {
      ans += DFS(S | trans(j), (V * 10 + j) % 2520, i);
    }
    S |= trans(temp[i]);
    V = (V * 10 + temp[i]) % 2520;
  }
  return ans + ok[S][V];
}
inline void solve() {
  long long l, r;
  scanf("%lld%lld", &l, &r);
  --l;
  printf("%lld\n", work(r) - work(l));
  return;
}
int main() {
  memset(g, -1, sizeof(g));
  prework();
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
