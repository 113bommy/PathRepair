#include <bits/stdc++.h>
using namespace std;
const int maxp = 40;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, f[maxn], to[maxn][maxp];
long long k, s[maxn][maxp];
int w[maxn], minv[maxn][maxp];
long long si;
int mi;
void init() {
  for (int i = 0; i < n; i++) {
    to[i][0] = f[i];
    minv[i][0] = s[i][0] = w[i];
  }
  for (long long j = 1; (1ll << j) <= k; j++) {
    for (int i = 0; i < n; i++) {
      to[i][j] = to[to[i][j - 1]][j - 1];
      minv[i][j] = min(minv[i][j - 1], minv[to[i][j - 1]][j - 1]);
      s[i][j] = s[i][j - 1] + s[to[i][j - 1]][j - 1];
    }
  }
}
inline int lowbit(int x) { return x & -x; }
void query(int u, long long k) {
  mi = inf;
  si = 0;
  int cnt = 0;
  while (k) {
    while (!(k & 1)) {
      k >>= 1;
      cnt++;
    }
    mi = min(mi, minv[u][cnt]);
    si += s[u][cnt];
    u = to[u][cnt];
    k ^= 1;
  }
}
int main() {
  scanf("%d%I64d", &n, &k);
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < n; i++) cin >> w[i];
  init();
  for (int i = 0; i < n; i++) {
    query(i, k);
    printf("%I64d %d\n", si, mi);
  }
  return 0;
}
