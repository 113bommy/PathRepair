#include <bits/stdc++.h>
using namespace std;
int ha[400010], h = 0, vis[400010];
int id(int x) { return lower_bound(ha + 1, ha + 1 + h, x) - ha; }
struct Q {
  int l, r;
} A[200010];
int cmp(Q a, Q b) {
  if (a.l == b.l)
    return a.r < b.r;
  else
    return a.l < b.l;
}
long long cnt[400010], sum[400010], mo = 1e9 + 7;
int main() {
  int i, n, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &A[i].l, &A[i].r);
    ha[++h] = A[i].l;
    ha[++h] = A[i].r;
  }
  sort(ha + 1, ha + 1 + h);
  h = unique(ha + 1, ha + 1 + h) - ha - 1;
  long long ma = 0;
  for (i = 1; i <= n; i++) {
    A[i].l = id(A[i].l);
    A[i].r = id(A[i].r);
    ma = max(ma, (long long)A[i].r);
  }
  sort(A + 1, A + 1 + n, cmp);
  long long k;
  cnt[0] = 1;
  A[0].l = A[0].r = 0;
  for (i = 1; i <= n; i++) {
    for (j = A[i - 1].l + 1; j < A[i].l; j++) {
      cnt[j] = cnt[j - 1];
      sum[j] = sum[j - 1] + ha[j] - ha[j - 1];
    }
    k = sum[A[i].r];
    if (k == sum[A[i].l]) {
      cnt[A[i].l] += cnt[A[i].r];
      cnt[A[i].l] %= mo;
    } else if (k < sum[A[i].l] || sum[A[i].l] == 0) {
      sum[A[i].l] = k;
      cnt[A[i].l] = cnt[A[i].r];
    }
  }
  long long ans = 0, mi = 1e18;
  for (i = 1; i <= n; i++) {
    if (A[i].l > ma && mi > sum[A[i].l]) mi = sum[A[i].l];
  }
  for (i = 1; i <= n; i++) {
    if (A[i].l > ma && mi == sum[A[i].l] && vis[A[i].l] == 0) {
      ans = (ans + cnt[A[i].l]) % mo;
      vis[A[i].l] = 1;
    }
  }
  cout << ans << endl;
}
