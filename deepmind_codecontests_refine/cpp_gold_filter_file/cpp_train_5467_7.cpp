#include <bits/stdc++.h>
using namespace ::std;
const long long M = 1000000007, INF = (long long)1 << 60;
int n, h, w;
const int N = 500001;
string a;
long long ans;
long long R[N + 5];
long long L[N + 5];
long long U[N + 5];
long long D[N + 5];
long long lr[N + 5];
long long ud[N + 5];
void init() {
  scanf("%d %d %d", &n, &h, &w);
  cin >> a;
  for (int i = 1; i <= N; i++) R[i] = L[i] = U[i] = D[i] = INF;
  int x = 0, y = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 'R') y++;
    if (a[i] == 'L') y--;
    if (a[i] == 'D') x++;
    if (a[i] == 'U') x--;
    if (x < 0)
      U[-x] = min(U[-x], i + 1);
    else
      D[x] = min(D[x], i + 1);
    if (y < 0)
      L[-y] = min(L[-y], i + 1);
    else
      R[y] = min(R[y], i + 1);
  }
  if (x < 0) {
    for (int i = -x + 1; i <= N; i++)
      if (U[i] == INF) U[i] = U[i + x] + n;
  } else if (x > 0) {
    for (int i = x + 1; i <= N; i++)
      if (D[i] == INF) D[i] = D[i - x] + n;
  }
  if (y < 0) {
    for (int i = -y + 1; i <= N; i++)
      if (L[i] == INF) L[i] = L[i + y] + n;
  } else if (y > 0) {
    for (int i = y + 1; i <= N; i++)
      if (R[i] == INF) R[i] = R[i - y] + n;
  }
}
int main() {
  init();
  long long mh = h + 1, mw = w + 1;
  bool p1 = false, p2 = false;
  for (int i = 0; i < h; i++) {
    ud[i + 1] = min(U[i + 1], D[h - i]);
    if (D[h - i] < U[i + 1] && mh == h + 1) mh = i + 1;
    if (ud[i + 1] == INF) p1 = true;
  }
  for (int i = 0; i < w; i++) {
    lr[i + 1] = min(L[i + 1], R[w - i]);
    if (R[w - i] < L[i + 1] && mw == w + 1) mw = i + 1;
    if (lr[i + 1] == INF) p2 = true;
  }
  long long mw2 = w - mw + 2, mh2 = h - mh + 2;
  if (p1 && p2) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= h; i++) {
    if (ud[i] == INF) continue;
    long long idx = upper_bound(L + 1, L + mw, ud[i]) - L;
    ans = (ans + (mw - idx) * (ud[i] % M)) % M;
    idx = upper_bound(R + 1, R + mw2, ud[i]) - R;
    ans = (ans + (mw2 - idx) * (ud[i] % M)) % M;
  }
  for (int i = 1; i <= w; i++) {
    if (lr[i] == INF) continue;
    long long idx = upper_bound(U + 1, U + mh, lr[i]) - U;
    ans = (ans + (mh - idx) * (lr[i] % M)) % M;
    idx = upper_bound(D + 1, D + mh2, lr[i]) - D;
    ans = (ans + (mh2 - idx) * (lr[i] % M)) % M;
  }
  printf("%I64d", ans);
  return 0;
}
