#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
int a[N], l[N], r[N], d[N], cha[N];
int m, n, k, t;
bool check(int x) {
  if (!x) return true;
  for (int i = 0; i <= n + 1; i++) cha[i] = 0;
  int g = a[x];
  for (int i = 1; i <= k; i++) {
    if (d[i] > g) {
      cha[l[i]]++, cha[r[i] + 1]--;
    }
  }
  int res = 0;
  for (int i = 1; i <= n + 1; i++) {
    cha[i] += cha[i - 1];
    if (cha[i] > 0) res++;
  }
  return res * 2 + n + 1 <= t;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> m >> n >> k >> t;
  for (int i = 1; i <= m; i++) cin >> a[i];
  sort(a + 1, a + 1 + m, greater<int>());
  for (int i = 1; i <= k; i++) cin >> l[i] >> r[i] >> d[i];
  int L = 0, R = m, M, ans = 0;
  while (L <= R) {
    M = (L + R) >> 1;
    if (check(M)) {
      ans = M;
      L = M + 1;
    } else
      R = M - 1;
  }
  cout << ans << endl;
  return 0;
}
