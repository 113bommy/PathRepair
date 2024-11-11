#include <bits/stdc++.h>
using namespace std;
const int maxN = 300001;
vector<int> rep[5001];
int cnt[5001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= 5000; ++i) {
    int x = i;
    for (int j = 2; j <= 5000; ++j)
      while (x % j == 0) {
        x /= j;
        rep[i].push_back(j);
      }
    vector<int> temp;
    merge(rep[i - 1].begin(), rep[i - 1].end(), rep[i].begin(), rep[i].end(),
          back_inserter(temp));
    rep[i].swap(temp);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!x) x = 1;
    ++cnt[x];
  }
  int ans = 0;
  for (int x = 1; x <= 5000; ++x) ans += cnt[x] * (long long)rep[x].size();
  set<int> left;
  for (int i = 2; i <= 5000; ++i) left.insert(i);
  while (true) {
    vector<int> to(5001);
    int i = 1;
    for (int x : left) {
      if (rep[x].empty()) continue;
      to[rep[x].back()] += cnt[x];
      if (to[rep[x].back()] > to[i]) i = rep[x].back();
    }
    bool brk = true;
    if (2 * to[i] > n) {
      brk = false;
      for (auto it = left.begin(); it != left.end();) {
        int x = *it;
        if (rep[x].size() && rep[x].back() == i) {
          rep[x].pop_back();
          ++it;
        } else {
          cnt[x] = 0;
          it = left.erase(it);
        }
      }
      ans -= to[i];
      ans += n - to[i];
    }
    if (brk) break;
  }
  cout << ans;
}
