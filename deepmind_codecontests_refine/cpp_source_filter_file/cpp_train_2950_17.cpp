#include <bits/stdc++.h>
using namespace std;
int n, k, h;
int w[100005], a[100005], pos[100005], ans[100005], store[100005];
bool cmp(int x, int y) {
  if (w[x] != w[y]) return w[x] < w[y];
  return a[x] < a[y];
}
int main() {
  scanf("%d %d %d", &n, &k, &h);
  for (int i = 0; i < n; i++) scanf("%d", &w[i]);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) pos[i] = i;
  sort(pos, pos + n, cmp);
  double low = 0, high = 1e9;
  for (int iter = 0; iter < 70; iter++) {
    double mid = (low + high) / 2;
    int x = k;
    for (int i = n - 1; i >= 0; i--)
      if (x > 0) {
        int u = pos[i];
        if (a[u] * mid >= x) {
          store[x] = u;
          x--;
        }
      }
    if (x)
      low = mid;
    else {
      for (int i = 1; i <= k; i++) ans[i] = store[i];
      high = mid;
    }
  }
  for (int i = 1; i <= k; i++) printf("%d ", ans[i] + 1);
}
