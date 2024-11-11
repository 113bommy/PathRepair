#include <bits/stdc++.h>
using namespace std;
int mp[1000005];
int sum[1000005];
vector<long long> hs;
vector<long long> v[1000005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n, m, dx, dy;
  while (cin >> n >> m >> dx >> dy) {
    hs.clear();
    memset(sum, 0, sizeof(sum));
    for (int i = (0); i <= (n - 1); i++) mp[i * dx % n] = i;
    for (int i = (1); i <= (m); i++) {
      int x, y;
      cin >> x >> y;
      v[mp[x]].push_back(y);
      hs.push_back(mp[x]);
    }
    sort(hs.begin(), hs.end());
    int sz = unique(hs.begin(), hs.end()) - hs.begin();
    hs.resize(sz);
    for (int i = 0; i < hs.size(); i++) {
      for (auto u : v[hs[i]]) {
        int id = (((u - hs[i] * dy) % n + n) % n + n) % n;
        sum[id]++;
      }
    }
    int mx = -1, p = -1;
    for (int i = (0); i <= (n - 1); i++) {
      if (sum[i] > mx) {
        mx = sum[i];
        p = i;
      }
    }
    cout << 0 << " " << p << endl;
  }
  return 0;
}
