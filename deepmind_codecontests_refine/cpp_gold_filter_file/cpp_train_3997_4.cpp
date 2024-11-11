#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int r = 1;
  x = x % p;
  while (y) {
    if (y & 1) r = r * x % p;
    y = y >> 1;
    x = x * x % p;
  }
  return r;
}
const int N = 1e5 + 99;
const int maxn = 1e5 + 99;
long long int bit1[maxn], bit2[maxn];
void update(long long int* bit, int i, long long int val) {
  while (i < maxn) bit[i] += val, i += i & -i;
}
void update(int l, int r, long long int val) {
  update(bit1, l, val);
  update(bit1, r + 1, -val);
  update(bit2, l, val * (l - 1));
  update(bit2, r + 1, -val * r);
}
long long int query(int i) {
  long long int ans = 0, ans2 = 0, X = i;
  while (i > 0) ans += bit1[i], ans2 += bit2[i], i -= i & -i;
  return ans * X - ans2;
}
long long int query(int l, int r) { return query(r) - query(l - 1); }
long long int a[N], q[N][3], pf[N];
int main() {
  int NN, m, k;
  cin >> NN >> m >> k;
  for (int i = 0; i < NN; i++) cin >> a[i + 1];
  for (int i = 1; i <= m; i++) cin >> q[i][0] >> q[i][1] >> q[i][2];
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    pf[x]++, pf[y + 1]--;
  }
  for (int i = 1; i <= m; i++) pf[i] += pf[i - 1];
  for (int i = 1; i <= m; i++) {
    update(q[i][0], q[i][1], q[i][2] * pf[i]);
  }
  for (int i = 1; i <= NN; i++) {
    cout << query(i) - query(i - 1) + a[i] << " ";
  }
  return 0;
}
