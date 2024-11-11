#include <bits/stdc++.h>
using namespace std;
int n, m;
int final[5010], v[5010];
struct Op {
  int tip, st, dr, val;
};
Op op[5010];
int main() {
  int i, j, maxim;
  cin >> n >> m;
  for (i = 1; i <= n; ++i) final[i] = 500000000;
  for (i = 1; i <= m; ++i) {
    cin >> op[i].tip >> op[i].st >> op[i].dr >> op[i].val;
    if (op[i].tip == 1) {
      for (j = op[i].st; j <= op[i].dr; ++j) final[j] += op[i].val;
    } else {
      for (j = op[i].st; j <= op[i].dr; ++j)
        final[j] = min(final[j], op[i].val);
    }
  }
  for (i = 1; i <= n; ++i) v[i] = final[i];
  for (i = 1; i <= m; ++i) {
    if (op[i].tip == 1) {
      for (j = op[i].st; j <= op[i].dr; ++j) v[j] -= op[i].val;
    }
  }
  for (i = 1; i <= n; ++i) final[i] = v[i];
  for (i = 1; i <= m; ++i) {
    if (op[i].tip == 1) {
      for (j = op[i].st; j <= op[i].dr; ++j) final[j] += op[i].val;
    } else {
      maxim = final[op[i].st];
      for (j = op[i].st; j <= op[i].dr; ++j) maxim = max(maxim, final[j]);
      if (maxim != op[i].val) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (i = 1; i <= n; ++i) cout << v[i] << ' ';
  cout << "\n";
  return 0;
}
