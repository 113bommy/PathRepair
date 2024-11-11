#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, B = 400;
int ans[B + 1][B + 1], pr[N], n, m, x[N], y[N], xx, yy, ty, idx, sm, add[N];
void update(int i, int xx, int yy, int val, int idd) {
  if (xx + yy >= B) {
    for (int j = i; j <= m; j += (xx + yy)) {
      if (j + xx > m) break;
      pr[min(m + 1, j + xx)] += val;
      pr[min(m + 1, j + xx + yy)] -= val;
    }
  } else {
    sm = xx + yy;
    for (int j = 0; j < sm; j++) {
      if (((j - i) % sm + sm) % sm >= xx) {
        ans[sm][j] += val;
      }
    }
  }
}
int getans(int i) {
  int pas = pr[i];
  for (int j = 1; j <= B; j++) {
    pas += ans[j][i % j];
  }
  return pas;
}
int check(int i, int xx, int yy, int i1) {
  if (xx + yy < B) return 0;
  int vl = (i - i1) / (xx + yy);
  int le = i1 + vl * (xx + yy) + xx;
  int le1 = i1 + (vl - 1) * (xx + yy) + xx;
  if ((le < i && le + yy >= i) || (le1 < i && le1 + yy >= i)) {
    pr[i]--;
    return 1;
  } else
    return 0;
}
int main() {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> ty >> idx;
    pr[i] = pr[i - 1] + pr[i];
    if (ty == 1) {
      add[idx] = i;
      xx = x[idx];
      yy = y[idx];
      update(i, xx, yy, 1, i);
      cout << getans(i) << "\n";
      continue;
    }
    if (ty == 2) {
      xx = x[idx];
      yy = y[idx];
      update(add[idx], xx, yy, -1, i);
      cout << getans(i) - check(i, xx, yy, add[idx]) << "\n";
      continue;
    }
  }
}
