#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
int n, m, a[N], b[N];
void solve() {
  long long ans = 0;
  vector<int> fs(a, a + m);
  sort(fs.begin(), fs.end());
  reverse(fs.begin(), fs.end());
  vector<pair<int, int>> bs;
  for (int i = 0; i < m; ++i) {
    bs.emplace_back(b[i], i);
  }
  sort(bs.begin(), bs.end());
  reverse(bs.begin(), bs.end());
  int ia = 0;
  long long tot = 0;
  for (int i = 0; i < m; ++i) {
    int bb, ind;
    tie(bb, ind) = bs[i];
    while (ia < m && ia < n && fs[ia] > bb) {
      tot += fs[ia++];
    }
    long long cand;
    if (ia < n && a[ind] < bb) {
      cand = tot + a[ind] + (long long)bb * (n - ia - 1);
    } else {
      cand = tot + (long long)bb * (n - ia);
    }
    ans = max(ans, cand);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i];
    }
    solve();
  }
  return 0;
}
