#include <bits/stdc++.h>
using namespace std;
const int N = 1200005;
int n, q;
vector<int> v[N];
int f[N * 5][8], x, ans[15], Ans[N];
struct Ask {
  int l, r, from;
} A[N];
inline int cmp(Ask x, Ask y) { return x.r < y.r; }
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 2; j * j <= x; j++)
      if (x % j == 0) {
        int flag = 0;
        while (x % j == 0) flag ^= 1, x /= j;
        if (flag) v[i].push_back(j);
      }
    if (x != 1) v[i].push_back(x);
  }
  for (int i = 1; i <= q; i++) scanf("%d%d", &A[i].l, &A[i].r), A[i].from = i;
  sort(A + 1, A + q + 1, cmp);
  for (int i = 1, l = 1; i <= n; i++) {
    for (int j = 0; j < 1 << v[i].size(); j++) {
      int cnt = 0, s = 1;
      for (int k = 0; k < v[i].size(); k++)
        if ((1 << k) & j)
          s *= v[i][k];
        else
          cnt++;
      for (int k = 0; k <= 7; k++) ans[k + cnt] = max(ans[k + cnt], f[s][k]);
      f[s][cnt] = i;
    }
    while (l <= q && i == A[l].r) {
      for (int j = 0; j <= 14; j++)
        if (ans[j] >= A[l].l) {
          Ans[A[l].from] = j;
          break;
        }
      l++;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", Ans[i]);
}
