#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int ft[maxN];
int L[maxN], R[maxN];
int n, m;
int cnt[maxN];
void upd(int pos, int v) {
  pos += 1;
  while (pos < maxN) {
    ft[pos] = max(ft[pos], v);
    pos += pos & -pos;
  }
}
int qry(int pos) {
  pos += 1;
  int ans = 0;
  while (pos > 0) {
    ans = max(ans, ft[pos]);
    pos -= pos & -pos;
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    cnt[l] += 1;
    cnt[r + 1] -= 1;
  }
  for (int i = 1; i <= m; ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = 1; i <= n; ++i) ft[i] = -1e9;
  for (int i = 1; i <= m; ++i) {
    L[i] = 1 + qry(cnt[i]);
    upd(cnt[i], L[i]);
  }
  for (int i = 1; i <= n; ++i) ft[i] = -1e9;
  for (int i = m; i >= 1; --i) {
    R[i] = 1 + qry(cnt[i]);
    upd(cnt[i], R[i]);
  }
  for (int i = 1; i <= m; ++i) L[i] = max(L[i], L[i - 1]);
  for (int i = m; i >= 1; --i) R[i] = max(R[i], R[i + 1]);
  int ans = 0;
  for (int i = 0; i <= m; ++i) {
    ans = max(ans, L[i] + R[i + 1]);
  }
  printf("%d\n", ans);
  return 0;
}
