#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int l, r;
  cin >> l >> r;
  map<long long int, vector<long long int>> m;
  m[1].push_back(4);
  m[1].push_back(7);
  vector<long long int> v;
  v.push_back(4);
  v.push_back(7);
  for (int i = 2; i <= 10; ++i) {
    for (auto j : m[i - 1]) {
      m[i].push_back(j * 10 + 4);
      m[i].push_back(j * 10 + 7);
    }
    v.insert(v.end(), m[i].begin(), m[i].end());
  }
  sort(v.begin(), v.end());
  auto start = lower_bound(v.begin(), v.end(), l);
  auto end = lower_bound(v.begin(), v.end(), r);
  long long int ans = 0;
  for (int i = start - v.begin() + 1; i < end - v.begin(); ++i) {
    ans += v[i] * (v[i] - v[i - 1]);
  }
  if (start == end) {
    ans += (r - l + 1) * (v[end - v.begin()]);
  } else {
    ans += v[start - v.begin()] * (v[start - v.begin()] - l + 1);
    ans += v[end - v.begin()] * (r - v[end - v.begin() - 1]);
  }
  cout << ans << endl;
}
int main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
}
