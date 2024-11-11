#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, ans[N];
vector<int> pos[N];
bool check(int k) {
  unordered_set<int> inc;
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(pos[i].begin(), pos[i].end(), k, greater<int>());
    while (it < pos[i].end() && inc.count(*it)) {
      it++;
    }
    if (it == pos[i].end()) {
      return false;
    }
    inc.insert(*it);
  }
  int i = 0;
  for (int x : inc) {
    ans[i] = x;
    i++;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    while (x) {
      pos[i].emplace_back(x);
      x >>= 1;
    }
  }
  int l = 1;
  int r = 1e9;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
