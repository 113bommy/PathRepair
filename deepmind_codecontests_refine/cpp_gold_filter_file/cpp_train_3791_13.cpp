#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10 + 5000;
const int INF = int(1e9);
int n, m;
int bonus[MAXN], a[MAXN], b[MAXN];
struct query {
  int t, l, r, v;
  query(int t = 0, int l = 0, int r = 0, int v = 0) : t(t), l(l), r(r), v(v) {}
} q[MAXN];
int main() {
  n = ({
    int n;
    scanf(" %d ", &n);
    n;
  });
  m = ({
    int n;
    scanf(" %d ", &n);
    n;
  });
  fill(a, a + n, INF);
  for (int i = (0), _b = (m); i < m; ++i) {
    int t = ({
      int n;
      scanf(" %d ", &n);
      n;
    });
    int l = ({
              int n;
              scanf(" %d ", &n);
              n;
            }) -
            1;
    int r = ({
              int n;
              scanf(" %d ", &n);
              n;
            }) -
            1;
    int v = ({
      int n;
      scanf(" %d ", &n);
      n;
    });
    if (t == 1)
      for (int j = (l), _b = (r); j <= r; ++j) bonus[j] += v;
    else {
      for (int j = (l), _b = (r); j <= r; ++j) {
        a[j] = min(a[j], v - bonus[j]);
        b[j] = a[j];
      }
    }
    q[i] = query(t, l, r, v);
  }
  for (int i = (0), _b = (m); i < m; ++i) {
    int l = q[i].l;
    int r = q[i].r;
    int v = q[i].v;
    if (q[i].t == 1)
      for (int j = (l), _b = (r); j <= r; ++j) b[j] += v;
    else {
      int maxb = -INF;
      for (int j = (l), _b = (r); j <= r; ++j) maxb = max(maxb, b[j]);
      if (maxb != v) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = (0), _b = (n); i < n; ++i) printf("%d ", a[i]);
  return 0;
}
