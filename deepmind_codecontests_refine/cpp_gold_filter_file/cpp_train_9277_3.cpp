#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int infi = 1e9 + 7;
const long long infl = 1e18 + 7;
int ar[101];
bitset<101> dp0[10500];
bitset<101> dp[10500];
bitset<101> ndp[10500];
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> ar[i];
  vector<pair<int, int> > tmp;
  sort(ar, ar + n);
  int lst = ar[0];
  int sum = ar[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    sum += ar[i];
    if (lst == ar[i])
      ++cnt;
    else {
      tmp.emplace_back(lst, cnt);
      lst = ar[i];
      cnt = 1;
    }
  }
  tmp.emplace_back(lst, cnt);
  if (tmp.size() <= 2) {
    cout << n;
    return 0;
  }
  for (auto cur : tmp) {
    for (int cnt = 1; cnt <= cur.second; ++cnt) {
      int second = cnt * cur.first;
      for (int w = 0; w < (10500); ++w) {
        ndp[w + second] |= dp0[w] << cnt;
        ndp[w + second] |= dp[w] << cnt;
      }
    }
    for (int cnt = 1; cnt <= cur.second; ++cnt) {
      dp0[cnt * cur.first][cnt] = 1;
    }
    for (int i = 0; i < (10500); ++i) dp[i] |= ndp[i];
  }
  int ans = 0;
  for (auto cur : tmp) {
    for (int cnt = 1; cnt <= cur.second; ++cnt) {
      int second = cnt * cur.first;
      if (dp[second][cnt]) continue;
      ans = max(ans, cnt);
      if (tmp.size() == 2 && cnt == cur.second) ans = n;
    }
  }
  cout << ans;
  return 0;
}
