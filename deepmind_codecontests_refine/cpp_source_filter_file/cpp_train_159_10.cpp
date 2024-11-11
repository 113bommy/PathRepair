#include <bits/stdc++.h>
using namespace std;
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (0) {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
  }
}
const int px[5] = {0, 0, 1, -1}, py[5] = {-1, 1, 0, 0}, N = 2e5 + 100,
          INF = 1e9, MOD = 1e9 + 7;
const long double eps = 1e-6, PI = 3.14159265358979323846;
int n, k, s, maxt, l, r, mid, ans, now;
int a[N], c[N], v[N];
char flag;
inline void read(int &n) {
  n = 0;
  char h = getchar();
  while (h < '0' || h > '9') h = getchar();
  while (h >= '0' && h <= '9') {
    n = (n * 10) + h - '0';
    h = getchar();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  read(n);
  read(k);
  read(s);
  read(maxt);
  for (int i = 0; i < n; ++i) {
    read(c[i]);
    read(v[i]);
  }
  for (int i = 0; i < k; ++i) read(a[i]);
  a[++k] = s;
  sort(a, a + k);
  l = 0;
  r = INF;
  while (r - l > 1) {
    mid = (r + l) >> 1;
    flag = 0;
    now = 0;
    for (int i = 1; i <= k; ++i) {
      if (a[i] - a[i - 1] > mid) {
        flag = 1;
        break;
      }
      int q = a[i] - a[i - 1];
      now += q * 2 - min(q, mid - q);
    }
    if (!flag && now <= maxt)
      r = mid;
    else
      l = mid;
  }
  ans = INF;
  for (int i = 0; i < n; ++i)
    if (c[i] < ans && v[i] >= r) ans = c[i];
  if (ans == INF) ans = -1;
  cout << ans;
}
