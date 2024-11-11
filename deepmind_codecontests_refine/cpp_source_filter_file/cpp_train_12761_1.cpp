#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int n1, n2, m;
struct Node {
  int d, w;
} a[N], b[N];
long long da[N], db[N];
long long wa[N], wb[N];
bool cmp(Node A, Node B) {
  if (A.w != B.w) return A.w > B.w;
  return A.d > B.d;
}
int main() {
  scanf("%d%d%d", &n1, &n2, &m);
  for (int i = 1; i <= n1; i++) scanf("%d%d", &a[i].w, &a[i].d);
  for (int i = 1; i <= n2; i++) scanf("%d%d", &b[i].w, &b[i].d);
  sort(a + 1, a + 1 + n1, cmp);
  sort(b + 1, b + 1 + n2, cmp);
  for (int i = 1; i <= n1; i++) {
    da[i] = da[i - 1] + a[i].d;
    wa[i] = wa[i - 1] + a[i].w;
  }
  for (int i = 1; i <= n2; i++) {
    db[i] = db[i - 1] + b[i].d;
    wb[i] = wb[i - 1] + b[i].w;
  }
  long long ans = 0;
  for (int i = 1; i <= n1; i++) {
    int l = 1, r = n2;
    while (r - l > 1) {
      int mid = l + r >> 1;
      if (da[i] + db[mid] <= m)
        l = mid;
      else
        r = mid - 1;
    }
    if (da[i] + db[l] <= m) {
      ans = max(wa[i] + wb[r], ans);
    }
    if (da[i] + db[r] <= m) {
      ans = max(wa[i] + wb[l], ans);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
