#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<int> ans1, ans2;
const int N = 1e5 + 9;
map<int, bool> vis;
int main() {
  int a, b;
  cin >> a >> b;
  v.push_back(0);
  for (int i = 1; i < N; ++i) {
    v.push_back(i);
    v[i] += v[i - 1];
  }
  int val = *lower_bound(v.begin(), v.end(), a);
  if (val == a) {
    int c = 1;
    for (auto i : v) {
      if (i > val) break;
      if (i) ans1.push_back(c++);
    }
  } else {
    int diff = val - a;
    int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
    if (diff == 2) {
      for (int i = 1; i <= idx; ++i) {
        if (i == 2) continue;
        ans1.push_back(i);
      }
    } else {
      idx = lower_bound(v.begin(), v.end(), a) - v.begin();
      for (int i = 2; i <= idx; ++i) {
        if (i == diff - 1) continue;
        ans1.push_back(i);
      }
    }
  }
  cout << ans1.size() << endl;
  for (auto i : ans1) {
    cout << i << " ";
    vis[i] = 1;
  }
  for (int i = 1; i < N; ++i) {
    if (vis[i]) continue;
    b -= i;
    if (b < 0) break;
    ans2.push_back(i);
  }
  cout << endl;
  cout << ans2.size() << endl;
  for (int i : ans2) cout << i << " ";
  return 0;
}
