#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int Set(int N, int pos) { return N = N | (1 << pos); }
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int hr[] = {-2, -2, -1, +1, +2, +2, -1, +1};
int hc[] = {+1, -1, +2, +2, -1, +1, -2, -2};
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};
const int MAXN = (int)1e5 + 9;
const long long M = 2e18 + 10;
int main() {
  long long i, j, k, l, m, n, p, q, x, y, u, v, r, s, tc, t;
  cin >> n >> k;
  long long ara[n + 9], up[n + 9];
  for (int i = 0; i <= (int)n - 1; i++) cin >> ara[i];
  up[n - 1] = n;
  for (i = n - 2; i >= 0; i--) {
    if (ara[i + 1] == 1)
      up[i] = up[i + 1];
    else
      up[i] = i + 1;
  }
  long long ans = 0;
  for (i = 0; i < n; i++) {
    r = i;
    p = ara[i], s = ara[i];
    if (k == 1) ans++;
    while (up[r] != n && p <= M / ara[up[r]]) {
      p *= ara[up[r]];
      s += ara[up[r]] + up[r] - i - 1;
      r = up[r];
      int need = -1;
      if (p % k == 0) need = p / k;
      if (s <= need && need <= s + up[r] - r - 1) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
