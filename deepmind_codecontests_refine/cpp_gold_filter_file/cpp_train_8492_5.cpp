#include <bits/stdc++.h>
using namespace std;
int maxim_l[100010];
int ans[100010];
int v[100010];
bool folosit[100010];
int nr_folosite[100010], c;
int n;
int brute_force(int k);
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i(1); i <= n; i++) cin >> v[i];
  int x(sqrt(20.0 * n));
  for (int i(1); i <= x + 1; i++) ans[i] = brute_force(i);
  maxim_l[0] = n + 1;
  for (int l(1); l <= (n + x) / x; l++) {
    int p(0), q(1 << 17);
    while (q) {
      if (brute_force(p + q) > l) p += q;
      q >>= 1;
    }
    p++;
    for (int i(maxim_l[l - 1] - 1); i >= p; i--) ans[i] = l;
    maxim_l[l] = p;
  }
  for (int i(1); i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
int brute_force(int k) {
  int ans(1);
  for (int i(1); i <= n; i++) {
    if (!folosit[v[i]]) {
      nr_folosite[c++] = v[i];
      folosit[v[i]] = 1;
      if (c > k) {
        ans++;
        for (int j(0); j < c; j++) folosit[nr_folosite[j]] = 0;
        c = 1;
        nr_folosite[0] = v[i];
        folosit[v[i]] = 1;
      }
    }
  }
  for (int j(0); j < c; j++) folosit[nr_folosite[j]] = 0;
  c = 0;
  return ans;
}
