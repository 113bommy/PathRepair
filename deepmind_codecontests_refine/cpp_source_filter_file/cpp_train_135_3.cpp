#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double Pi = acos(-1.0);
const double EPS = 1e-8;
int n, m, a[N << 1], R[N];
int h[2], t[2], que[N << 1];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (n); ++i) scanf("%d", a + i);
  memset(R, -1, sizeof(R));
  for (int i = (0); i < (m); ++i) {
    int x;
    scanf("%d", &x);
    R[x] = i;
  }
  for (int i = (0); i < (n); ++i) a[i] = a[n + i] = R[a[i]];
  a[n << 1] = -1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) continue;
    ans = max(ans, 1);
    int j, w = 0;
    h[0] = t[0] = 0, h[1] = t[1] = n;
    que[t[0]++] = a[i];
    for (j = i + 1; ~a[j] && j < (n << 1); ++j) {
      if (a[j] < que[t[w] - 1]) {
        if (w == 1) {
          swap(h[0], h[1]), swap(t[0], t[1]);
          h[1] = t[1] = (h[0] >= n ? 0 : n);
        }
        w = 1;
      }
      if (w == 1)
        while (h[0] < t[0] && que[h[0]] <= a[j]) ++h[0];
      que[t[w]++] = a[j];
      ans = max(ans, (t[0] - h[0]) + (t[1] - h[1]));
    }
    i = j;
  }
  printf("%d", ans);
  return 0;
}
