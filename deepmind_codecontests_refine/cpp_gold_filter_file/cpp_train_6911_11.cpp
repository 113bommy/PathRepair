#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int hg[40];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    for (int j = 0; j < 30; ++j) {
      if (t & (1 << j)) {
        hg[j]++;
      }
    }
  }
  vector<int> can(m);
  for (int &i : can) cin >> i;
  sort(can.begin(), can.end());
  int res = 0;
  for (int i : can) {
    int nxt = -1;
    for (int t = i; t < 40; ++t) {
      if (hg[t] > 0) {
        nxt = t;
        break;
      }
    }
    if (nxt == -1) continue;
    if (nxt == i) {
      hg[i]--;
      res++;
    } else {
      for (int bi = nxt - 1; bi >= i; --bi) {
        hg[bi + 1]--;
        hg[bi] += 2;
      }
      hg[i]--;
      res++;
    }
  }
  cout << res << "\n";
  return 0;
}
