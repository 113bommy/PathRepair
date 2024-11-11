#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], t[N], f[N], n, m, l, r;
long long s;
void update(int r, int val) {
  for (int i = r; i <= n + 1; i = i | (i + 1)) t[i] += val;
}
int sum(int r) {
  int res = 0;
  for (int i = r; i >= 0; i = (i & (i + 1)) - 1) res += t[i];
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    update(l, 1);
    update(r + 1, -1);
  }
  for (int i = 1; i <= n; i++) f[i - 1] = sum(i);
  sort(f, f + n);
  for (int i = 0; i < n; i++) s += 1ll * a[i] * f[i];
  cout << s;
  return 0;
}
