#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int N = 1e6 + 5;
const int M = 2e5 + 5;
using namespace std;
int v[N];
void solve() {
  int n, i, I;
  cin >> n >> I;
  for (i = 0; i < n; i++) cin >> v[i];
  int lim = (8 * I) / n;
  if (lim >= 30) {
    cout << "0\n";
    return;
  }
  int go = (1 << lim);
  sort(v, v + n);
  int ans = 0;
  vector<int> got;
  for (i = 0; i < n; i++) {
    int cnt = 1;
    while (i < n - 1 && v[i + 1] == v[i]) {
      cnt++;
      i++;
    }
    got.push_back(cnt);
  }
  int m = got.size();
  if (m <= go) {
    cout << "0\n";
    return;
  }
  int cur = 0;
  for (i = 0; i < go; i++) cur += got[i];
  ans = max(ans, cur);
  for (; i < m; i++) {
    cur += got[i];
    cur -= got[i - go];
    ans = max(ans, cur);
  }
  cout << n - ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
  return 0;
}
