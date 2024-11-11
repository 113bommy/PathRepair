#include <bits/stdc++.h>
using namespace std;
struct demand {
  int L, R, V;
  demand(int _L, int _R, int _V) {
    L = _L;
    R = _R;
    V = _V;
  }
};
long long arr[100100];
long long dp[100100];
bool call(int n, vector<demand> &d, int *ans) {
  memset((arr), (0), sizeof(arr));
  ;
  for (auto x : d) {
    if (x.V == 0) continue;
    arr[x.L]++;
    arr[x.R + 1]--;
  }
  for (auto i = 0; i < (n); i++) {
    if (i) arr[i] += arr[i - 1];
    dp[i] = bool(arr[i] > 0);
    ans[i] = dp[i];
    if (i) dp[i] += dp[i - 1];
  }
  for (auto x : d) {
    long long tot = dp[x.R];
    if (x.L > 0) tot += dp[x.L - 1];
    if (x.V == 0 && tot >= (x.R - x.L + 1)) return false;
    if (x.V == 1) {
      if (tot != x.R - x.L + 1) return false;
    }
  }
  return true;
}
vector<demand> d, temp;
int ttt[100100];
int ans[100100];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int tm = m;
  while (m--) {
    int l, r, q;
    cin >> l >> r >> q;
    l--, r--;
    d.push_back(demand(l, r, q));
  }
  vector<demand> temp;
  for (auto i = 0; i < (tm); i++) temp.push_back(demand(0, 0, 0));
  for (int bit = 0; bit < 30; bit++) {
    int idx = 0;
    for (auto x : d) {
      int v = bool(x.V & (1 << bit));
      temp[idx].L = x.L;
      temp[idx].R = x.R;
      temp[idx].V = v;
      idx++;
    }
    if (!call(n, temp, ttt)) {
      cout << "NO" << endl;
      return 0;
    }
    for (auto i = 0; i < (n); i++) {
      if (ttt[i]) ans[i] += (1 << bit);
    }
  }
  cout << "YES" << endl;
  for (auto i = 0; i < (n); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
