#include <bits/stdc++.h>
using namespace std;
int a[35][35];
int b[35];
int k[35];
int p[35];
int n, u, r;
int temp[35];
long long ans;
void go(int pos, int last) {
  if (pos % 2 == u % 2) {
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      cur += a[u][i] * 1LL * k[i];
    }
    ans = max(ans, cur);
  }
  if (pos == u) return;
  for (int i = 0; i < n; i++) {
    a[pos + 1][i] = a[pos][p[i]] + r;
  }
  go(pos + 1, 1);
  if (last) {
    for (int i = 0; i < n; i++) a[pos + 1][i] = a[pos][i] ^ b[i];
    go(pos + 1, 0);
  }
}
int main() {
  ans = -(1LL << 60);
  scanf("%d %d %d", &n, &u, &r);
  for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) scanf("%d", &k[i]);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]), --p[i];
  go(0, 1);
  cout << ans << endl;
  return 0;
}
