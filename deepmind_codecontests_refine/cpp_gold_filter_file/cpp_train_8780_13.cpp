#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long H[N] = {1}, x, s;
const int P = 1e6 + 3;
const int mod = 1e9 + 7;
int n, m, A[N], B[N], pos[N];
struct node {
  long long H, S;
} St[N << 2];
void update(int o, int l, int r, int x, int p, int q) {
  if (l == r && l == x) {
    St[o].H += p, St[o].S += q;
    return;
  }
  if (x <= (l + r >> 1))
    update(o << 1, l, (l + r >> 1), x, p, q);
  else if (x > (l + r >> 1))
    update(o << 1 | 1, (l + r >> 1) + 1, r, x, p, q);
  St[o].S = St[o << 1].S + St[o << 1 | 1].S;
  St[o].H =
      ((H[St[o << 1 | 1].S] * St[o << 1].H) % mod + St[o << 1 | 1].H) % mod;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    H[i] = (P * H[i - 1]) % mod;
    s = (s * P + A[i]) % mod, x = (x + H[i - 1]) % mod;
  }
  for (int i = 1; i <= m; ++i) scanf("%d", &B[i]), pos[B[i]] = i;
  int ret = 0;
  for (int i = 1; i <= m; ++i) {
    update(1, 1, m, pos[i], i, 1);
    if (i > n) update(1, 1, m, pos[i - n], -(i - n), -1);
    if (((St[1].H - (i - n) * x) % mod + mod) % mod == s && i >= n) ++ret;
  }
  cout << ret << endl;
  return 0;
}
