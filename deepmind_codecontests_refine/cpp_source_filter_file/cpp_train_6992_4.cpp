#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> cc;
map<int, vector<int>> mp;
map<int, int> vst;
int f[N], m;
void update(int x, int val) {
  for (; x < N; x += x & -x) {
    f[x] += val;
  }
}
int getsum(int x) {
  int sum = 0;
  for (; x; x -= x & -x) {
    sum += f[x];
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1, x, y; i <= n; i++) {
    cin >> x >> y;
    mp[y].emplace_back(x);
    cc.emplace_back(x);
  }
  cc.push_back(0);
  sort(cc.begin(), cc.end());
  cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
  m = cc.size() - 1;
  long long ans = 0;
  for (auto ptr = mp.rbegin(); ptr != mp.rend(); ptr++) {
    sort(ptr->second.begin(), ptr->second.end());
    int preidx = 0;
    for (auto it : ptr->second) {
      if (!vst[it]++) {
        int idx = lower_bound(cc.begin(), cc.end(), it) - cc.begin();
        update(it, 1);
      }
    }
    for (auto it : ptr->second) {
      int idx = lower_bound(cc.begin(), cc.end(), it) - cc.begin();
      ans += 1ll * (getsum(m) - getsum(idx) + 1) *
             (getsum(idx - 1) - getsum(preidx) + 1);
      preidx = idx;
    }
  }
  cout << ans << '\n';
  return 0;
}
