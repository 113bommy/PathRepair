#include <bits/stdc++.h>
using namespace std;
int cnt[2][105];
long long pos[1005];
int n, k, m;
inline void add(int &a, int b) {
  a += b;
  if (a >= m) a -= m;
}
int main() {
  scanf("%d %d %d", &n, &k, &m);
  pos[0] = 1;
  pos[1] = 9 % m;
  for (int i = 2; i < n; i++) pos[i] = pos[i - 1] * 10 % m;
  int *now = cnt[0], *pre = cnt[1];
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    !i || i % k ? add(now[i % k], 1) : add(ans, 1 * pos[n - 1]);
  }
  int t = 1;
  for (int u = 2; u <= n; u++) {
    for (int i = 0; i < k; i++) pre[i] = now[i];
    t = t * 10 % k;
    for (int v = 0; v < k; v++) {
      for (int i = 1; i < 10; i++) {
        (v + i * t) % k ? add(now[(v + i * t) % k], pre[v])
                        : add(ans, pos[n - u] * pre[v] % m);
      }
    }
  }
  printf("%d\n", ans);
}
