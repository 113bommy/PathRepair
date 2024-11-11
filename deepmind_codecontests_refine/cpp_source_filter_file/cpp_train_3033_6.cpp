#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], basis[20], pos[20], num[20], ans[maxn];
pair<pair<int, int>, int> p[maxn];
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    p[i] = {{r, l}, i};
  }
  sort(p + 1, p + q + 1);
  for (int i = 1, cur = 1; i <= n; i++) {
    int x = a[i], id = i;
    for (int j = 20 - 1; j >= 0; j--) {
      if (x >> j & 1) {
        if (basis[j]) {
          if (pos[j] < id) {
            swap(basis[j], x);
            swap(pos[j], id);
          }
          x ^= basis[j];
        } else {
          basis[j] = x;
          pos[j] = i;
          break;
        }
      }
    }
    while (cur <= q && p[cur].first.first == i) {
      int tmp = 0;
      for (int j = 20 - 1; j >= 0; j--) {
        if (pos[j] == 0 || pos[j] < p[cur].first.second) continue;
        tmp = max(tmp, tmp ^ basis[j]);
      }
      ans[p[cur].second] = tmp;
      ++cur;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
