#include <bits/stdc++.h>
using namespace std;
long dv[2000000], used[2000000], n, m, tp, lvl[200000], l[200000], r[200000],
    val[200000];
long L[200000], R[200000];
long ttl, qlvl, qv, ans;
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i <= 20; i++) {
    dv[1 << i] = 1;
  }
  for (int i = 1; i <= 1000000; i++) dv[i] += dv[i - 1];
  cin >> n >> m;
  for (int i = 0; i <= 1000000; i++) used[i] = -1;
  for (; m; --m) {
    cin >> tp;
    if (tp == 1) {
      cin >> lvl[ttl] >> l[ttl] >> r[ttl] >> val[ttl];
      ++ttl;
      continue;
    }
    cin >> qlvl;
    cin >> qv;
    ans = 0;
    L[qlvl] = qv - 1;
    R[qlvl] = qv;
    for (int i = qlvl + 1; i <= n; i++) {
      L[i] = L[i - 1] + dv[L[i - 1]];
      R[i] = R[i - 1] + dv[R[i - 1]];
    }
    ans = 0;
    for (int i = 0; i < ttl; i++) {
      if (lvl[i] >= qlvl && max(L[lvl[i]] + 1, l[i]) <= min(R[lvl[i]], r[i]) &&
          used[val[i]] != m) {
        used[val[i]] = m;
        ++ans;
      }
    }
    cout << ans << endl;
  }
  cin.get();
  cin.get();
  return 0;
}
