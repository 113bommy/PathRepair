#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x3f3f3f3f;
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
const int N = 1e6 + 111;
int a[N], b[N];
int c[N];
int main() {
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", a + i);
  for (i = 0; i < m; i++) scanf("%d", b + i);
  int ans = 0;
  sort(b, b + m);
  for (i = 0; i < n; i++) {
    int tmp = a[i];
    for (j = 0; j < 31; j++) {
      if ((1 << j) & tmp) c[j]++;
    }
  }
  j = 0;
  int top = -1;
  for (i = 0; i < m; i++) {
    bool f = 1;
    int tp = b[i], r = b[i];
    while (c[r] == 0) {
      r++;
      if (r == 31) {
        f = 0;
        break;
      }
    }
    if (!f) break;
    for (j = tp; j < r - 1; j++) c[j]++;
    c[r]--;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
