#include <bits/stdc++.h>
using namespace std;
long long a[35], b[35], k[35], p[35];
long long n, u, r, ans;
void op1() {
  for (int i = 0; i < n; i++) a[i] = a[i] ^ b[i];
}
void op2() {
  long long tmp[35];
  for (int i = 0; i < n; i++) tmp[i] = a[p[i]] + r;
  for (int i = 0; i < n; i++) a[i] = tmp[i];
}
void dfs(int t, int f) {
  long long x = 0;
  if ((t & 1) == 0) {
    for (int i = 0; i < n; i++) x += a[i] * k[i];
    ans = max(x, ans);
  }
  if (t == 0) return;
  long long tmp[35];
  for (int i = 0; i < n; i++) tmp[i] = a[i];
  op2();
  dfs(t - 1, 1);
  for (int i = 0; i < n; i++) a[i] = tmp[i];
  if (f) {
    op1();
    dfs(t - 1, 0);
    for (int i = 0; i < n; i++) a[i] = tmp[i];
  }
  return;
}
int main() {
  cin >> n >> u >> r;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
  ans = -100000000000000009;
  dfs(u, 1);
  cout << ans << endl;
}
