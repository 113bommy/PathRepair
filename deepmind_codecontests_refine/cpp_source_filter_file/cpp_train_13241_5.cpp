#include <bits/stdc++.h>
using namespace std;
map<vector<pair<int, int> >, int> cnt;
int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    vector<pair<int, int> > pcnt;
    vector<pair<int, int> > temp;
    for (int p = 2; p * p <= x; ++p) {
      if (x % p == 0) {
        int cc = 0;
        while (x % p == 0) {
          ++cc;
          x /= p;
        }
        if (cc % k != 0) {
          pcnt.push_back(make_pair(p, cc % k));
        }
      }
    }
    if (x > 1) pcnt.push_back(make_pair(x, 1));
    for (int j = 0; j < pcnt.size(); ++j) {
      temp.push_back(make_pair(pcnt[j].first, k - pcnt[j].second));
    }
    ans += cnt[temp];
    ++cnt[pcnt];
  }
  cout << ans << '\n';
  return 0;
}
