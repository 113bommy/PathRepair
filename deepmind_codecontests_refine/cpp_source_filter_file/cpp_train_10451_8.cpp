#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
struct pii {
  int first, second, id;
  pii(int first = 0, int second = 0, int id = 0)
      : first(first), second(second), id(id) {}
};
inline int cmp(pii x, pii y) {
  return (x.second != y.second) ? x.second < y.second : x.first < y.first;
}
inline bool inter(pii x, pii y) {
  return !(x.second < y.first || x.first > y.second);
}
pii a[N];
int n;
int b[N];
int rk[N];
int dan[N], vis[N];
int ct[N];
inline bool check(int mid, int id = 0) {
  for (int i = 1; i <= n; ++i) dan[i] = n;
  memset(vis, 0, sizeof vis);
  dan[0] = n + 1;
  for (int i = 1; i <= n; ++i) {
    int x = 0;
    memset(ct, 0, sizeof ct);
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) continue;
      ++ct[dan[j]];
    }
    for (int j = i + 1; j <= n; ++j) ct[j] += ct[j - 1];
    int mxv = 0;
    for (int j = i; j <= n; ++j) {
      if (ct[j] > j - i + 1)
        return false;
      else if (ct[j] == j - i + 1) {
        mxv = j;
        break;
      }
    }
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) continue;
      if (dan[j] <= mxv) {
        x = j;
        break;
      }
    }
    vis[x] = 1;
    if (id == 1) b[i] = x;
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) continue;
      if (inter(a[j], a[x])) dan[j] = min(dan[j], i + mid);
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int L = 0, R = n;
  while (L < R) {
    int mid = (L + R) / 2;
    if (check(mid))
      R = mid;
    else
      L = mid + 1;
  }
  check(R, 1);
  for (int i = 1; i <= n; ++i) printf("%d ", a[b[i]].id);
  return 0;
}
