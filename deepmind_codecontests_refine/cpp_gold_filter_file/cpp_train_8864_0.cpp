#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int arr[MAX], P[MAX][21];
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < MAX; ++i) {
    for (int j = 0; j < 21; ++j) P[i][j] = MAX - 1;
  }
  cin >> n >> m;
  vector<pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    l++, r++;
    vp.emplace_back(l, r);
  }
  sort(vp.begin(), vp.end());
  int idx = 0;
  multiset<int> s;
  for (int i = 1; i < MAX; ++i) {
    while (idx < n && vp[idx].first == i) s.insert(vp[idx++].second);
    while (s.size() > 0 && *s.begin() < i) s.erase(s.begin());
    if (s.size()) P[i][0] = *s.rbegin();
  }
  for (int j = 1; j < 21; ++j) {
    for (int i = 1; i < MAX; ++i) {
      P[i][j] = P[P[i][j - 1]][j - 1];
      if (P[i][j] == i) P[i][j] = MAX - 1;
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    ++l, ++r;
    int ans = 1e9, cur = 0;
    for (int j = 20; j >= 0; --j) {
      if (P[l][j] == MAX - 1) continue;
      if (P[l][j] >= r)
        ans = min(ans, cur + (1 << j));
      else
        l = P[l][j], cur += (1 << j);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
