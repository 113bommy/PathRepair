#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int maxn = (500000 + 5);
const int mod = (1e9 + 7);
int k[maxn], sum[maxn];
int find(int x) { return k[x] == x ? x : k[x] = find(k[x]); }
int main() {
  int n, m, ki;
  int a, b;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    k[i] = i;
    sum[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &ki);
    if (ki != 0) {
      scanf("%d", &a);
      for (int j = 1; j < ki; j++) {
        scanf("%d", &b);
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) {
          k[b] = a;
          sum[a] += sum[b];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = find(i);
    printf("%d ", sum[x]);
  }
  return 0;
}
