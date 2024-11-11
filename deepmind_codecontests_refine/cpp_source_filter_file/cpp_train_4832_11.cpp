#include <bits/stdc++.h>
using namespace std;
int ft[2000005];
int n, k;
void upd(int id) {
  while (id <= 2000000) {
    ft[id] += 1;
    id += id & (-id);
  }
}
int qry(int id) {
  int ans = 0;
  while (id) {
    ans += ft[id];
    id -= id & (-id);
  }
  return ans;
}
int main() {
  int v[300005];
  scanf("%d %d", &n, &k);
  int mi = 1000005;
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
    mi = min(mi, v[i]);
    upd(v[i]);
  }
  int l = min(k + 1, mi), r = mi;
  int ans = l;
  for (int i = l + 1; i <= r; i++) {
    int f = 1;
    for (int j = i; j <= 77; j += i) {
      if (qry(j + i - 1) - qry(j + k)) {
        f = 0;
        break;
      }
    }
    if (f) ans = i;
  }
  printf("%d\n", ans);
  return 0;
}
