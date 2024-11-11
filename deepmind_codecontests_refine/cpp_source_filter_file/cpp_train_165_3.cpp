#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n, a[N], lstp[33], mxpos[N], mnpos[N], st[N][22], lg2[N];
long long ans;
int Qpos(int l, int r) {
  int k = lg2[r - l + 1];
  int x1 = st[l][k], x2 = st[r - (1 << k) + 1][k];
  if (a[x1] > a[x2])
    return x1;
  else
    return x2;
}
void solve(int l, int r) {
  if (l > r) return;
  if (l == r) {
    ans++;
    return;
  }
  int t = Qpos(l, r);
  solve(l, t - 1);
  solve(t + 1, r);
  int L = mxpos[t] + 1, R = mnpos[t] - 1;
  L = max(L, l), R = min(R, r);
  ans += 1ll * (t - L + 1) * (R - t + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mnpos[i] = n + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 30; j++) {
      if (a[i] & (1 << j)) {
        lstp[j] = i;
      } else
        mxpos[i] = max(mxpos[i], lstp[j]);
    }
  }
  for (int j = 0; j <= 30; j++) lstp[j] = n + 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= 30; j++) {
      if (a[i] & (1 << j)) {
        lstp[j] = i;
      } else
        mnpos[i] = min(mnpos[i], lstp[j]);
    }
  }
  for (int i = 1; i <= n; i++) st[i][0] = i;
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      int x1 = st[i][j - 1];
      int x2 = st[i + (1 << (j - 1))][j - 1];
      if (a[x1] > a[x2])
        st[i][j] = x1;
      else
        st[i][j] = x2;
    }
  solve(1, n);
  printf("%lld\n", n * (n + 1) / 2 - ans);
  return 0;
}
