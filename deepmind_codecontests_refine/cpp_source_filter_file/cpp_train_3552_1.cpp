#include <bits/stdc++.h>
using namespace std;
const int N = 260;
int m, n, mx[N][10], g[N][26], sl[N], L[N];
char a[N][N];
int kq;
unsigned long long o[N], A[N], B[N], pw[N], P[N];
unsigned long long get(int l, int r) { return A[r] - A[l - 1] * pw[r - l + 1]; }
unsigned long long Get(int l, int r) { return B[l] - B[r + 1] * pw[r - l + 1]; }
unsigned long long GET(int l, int r) {
  int tg = L[r - l + 1];
  return max(mx[l][tg], mx[r - (1 << tg) + 1][tg]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> m >> n;
  pw[0] = 1;
  P[0] = 1;
  for (int i = 1, _c = 250; i <= _c; ++i) {
    pw[i] = pw[i - 1] * 47;
    L[i] = log2(i);
  }
  for (int i = 1, _c = 25; i <= _c; ++i) P[i] = P[i - 1] * 97;
  for (int i = 1, _c = m; i <= _c; ++i)
    for (int j = 1, _c = n; j <= _c; ++j) cin >> a[i][j];
  for (int l = 1, _c = n; l <= _c; ++l)
    for (int r = l, _c = n; r <= _c; ++r) {
      if (l == r) {
        memset(o, 0, sizeof(o));
        memset(g, 0, sizeof(g));
        memset(sl, 0, sizeof(sl));
      }
      for (int i = 1, _c = m; i <= _c; ++i) {
        int x = a[i][r] - 'a';
        g[i][x]++;
        if (g[i][x] % 2)
          sl[i]++;
        else
          sl[i]--;
        if (sl[i] > 1)
          mx[i][0] = 1;
        else
          mx[i][0] = 0;
        o[i] = o[i] + P[x] * x;
      }
      for (int j = 1, _c = log2(m); j <= _c; ++j)
        for (int i = 1, _c = m; i <= _c; ++i)
          mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
      for (int i = 1, _c = m; i <= _c; ++i) A[i] = A[i - 1] * 47 + o[i];
      for (int i = m, _c = 1; i >= _c; --i) B[i] = B[i + 1] * 47 + o[i];
      for (int i = 1, _c = m; i <= _c; ++i)
        if (!mx[i][0]) {
          int l = i, r = min(m, i + (i - 1)), tg = i;
          while (l <= r) {
            int mid = (l + r) / 2;
            if (get(i, mid) == Get(2 * i - mid, i) && !GET(i, mid)) {
              tg = mid;
              l = mid + 1;
            } else
              r = mid - 1;
          }
          kq += (tg - i + 1);
        }
      for (int i = 2, _c = m; i <= _c; ++i)
        if (!mx[i][0] && !mx[i - 1][0] && o[i] == o[i - 1]) {
          int l = i, r = min(m, i + (i - 1)), tg = i;
          while (l <= r) {
            int mid = (l + r) / 2;
            if (get(i, mid) == Get(2 * i - 1 - mid, i - 1) && !GET(i, mid)) {
              tg = mid;
              l = mid + 1;
            } else
              r = mid - 1;
          }
          kq += (tg - i + 1);
        }
    }
  cout << kq;
}
