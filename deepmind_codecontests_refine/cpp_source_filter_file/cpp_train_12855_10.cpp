#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n, a[N], pos, ans[N], st[21][N + N], lg[N];
map<int, int> M;
inline int f(int l, int r) {
  int first = lg[r - l + 1];
  return min(st[first][l], st[first][r - (1 << first) + 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
  for (int i = 1; i <= n; ++i) st[0][i] = a[i];
  for (int i = 1; i <= lg[n]; ++i)
    for (int j = 1; j + (1 << i) - 1 <= n; ++j)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  for (int i = 1; i <= n; ++i) {
    int L, R;
    int l = 1, r = i;
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (f(mid, i) >= a[i])
        r = mid;
      else
        l = mid;
    }
    if (a[l] >= a[i])
      L = l;
    else if (a[r] >= a[i])
      L = r;
    l = i, r = n;
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (f(i, mid) >= a[i])
        l = mid;
      else
        r = mid;
    }
    if (a[r] >= a[i])
      R = r;
    else if (a[l] >= a[i])
      R = l;
    M[a[i]] = max(M[a[i]], R - L + 1);
  }
  map<int, int>::iterator i = M.end();
  --i;
  int l = 1, r = 0;
  for (;; --i) {
    if (i->second > r) {
      for (int j = l; j <= i->second; ++j) ans[j] = i->first;
      l = i->second + 1;
      r = i->second + 1;
    }
    if (i == M.begin()) break;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}
