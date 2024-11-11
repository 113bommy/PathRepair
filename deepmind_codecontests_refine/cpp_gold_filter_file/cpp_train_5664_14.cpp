#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(T *a, int n) {
  for (int i = 0; i < n; i++) cout << a[i] << "  ";
  puts("");
}
const int MAXN = 300007;
int BT[MAXN];
int a[MAXN];
int po[MAXN];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int i;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      po[a[i]] = i;
    }
    po[n + 1] = n + 1;
    po[0] = 0;
    int q;
    scanf("%d", &q);
    while (q--) {
      int tp, x, y;
      scanf("%d%d%d", &tp, &x, &y);
      if (tp == 1) {
        int ans = 1;
        for (i = x + 1; i <= y; i++)
          if (po[i] < po[i - 1]) ans++;
        printf("%d\n", ans);
      } else {
        swap(a[x], a[y]);
        po[a[x]] = x;
        po[a[y]] = y;
      }
    }
  }
  return 0;
}
