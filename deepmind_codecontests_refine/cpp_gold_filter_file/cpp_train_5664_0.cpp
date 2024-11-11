#include <bits/stdc++.h>
using namespace std;
int n, m, a[300002], sv[300002], u, x, y;
struct fenw {
  int x[300002], tag[300002];
  void update(int now, int val) {
    if (val == 1 && tag[now] == 0) {
      tag[now] = 1;
      for (int i = now; i <= n; i += (i & (-i))) x[i] += val;
    } else if (val == -1 && tag[now] == 1) {
      tag[now] = 0;
      for (int i = now; i <= n; i += (i & (-i))) x[i] += val;
    }
  }
  int find(int now) {
    int s = 0;
    for (int i = now; i > 0; i -= (i & (-i))) s += x[i];
    return s;
  }
  void pr() {
    for (int i = 1; i <= n; i++) printf("%d ", x[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", tag[i]);
    printf("\n");
  }
};
fenw f;
int main() {
  scanf("%d", &n);
  sv[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sv[a[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (sv[i] < sv[i - 1]) f.update(i - 1, 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &x, &y);
    if (u == 1)
      printf("%d\n", f.find(y - 1) - f.find(x - 1) + 1);
    else {
      swap(sv[a[x]], sv[a[y]]);
      u = sv[a[x] - 1] > sv[a[x]] ? 1 : -1;
      f.update(a[x] - 1, u);
      u = sv[a[x]] > sv[a[x] + 1] ? 1 : -1;
      f.update(a[x], u);
      u = sv[a[y]] > sv[a[y] + 1] ? 1 : -1;
      f.update(a[y], u);
      if (x != y - 1) {
        u = sv[a[y] - 1] > sv[a[y]] ? 1 : -1;
        f.update(a[y] - 1, u);
      }
      swap(a[x], a[y]);
    }
  }
  return 0;
}
