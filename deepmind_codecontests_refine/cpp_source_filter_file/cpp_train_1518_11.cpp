#include <bits/stdc++.h>
using namespace std;
int n, lv, k;
int a[300000], pv[300000], par[300000];
vector<int> edge;
int process() {
  cin >> n >> lv >> k;
  for (int i = 1; i <= lv; i++) cin >> a[i];
  pv[1] = 1;
  for (int i = 2; i <= lv; i++) pv[i] = pv[i - 1] + a[i - 1];
  for (int i = 1; i <= lv; i++) {
    for (int j = 1; j <= a[i]; j++) par[pv[i] + j] = pv[i - 1] + 1;
  }
  int leave = 1;
  for (int i = 1; i <= lv; i++) leave += a[i] - 1;
  if (k > leave) return cout << -1, 0;
  int need = leave - k;
  for (int i = 1; i < lv; i++) {
    int poss = min(a[i] - 1, a[i + 1] - 1);
    if (poss >= need) {
      for (int j = 1; j <= need; j++) {
        par[pv[i + 1] + 1 + j] = pv[i] + 1 + j;
      }
      need = 0;
      break;
    } else {
      for (int j = 1; j <= poss; j++) par[pv[i + 1] + 1 + j] = pv[i] + 1 + j;
      need - poss;
    }
  }
  if (need > 0) return cout << -1, 0;
  cout << n << endl;
  for (int i = 2; i <= n; i++) cout << i << ' ' << par[i] << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  process();
  return 0;
}
