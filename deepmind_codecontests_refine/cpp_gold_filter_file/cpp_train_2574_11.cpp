#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[200009];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<int> a(n);
  vector<int> cnt(m, 0);
  int c = n / m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i] % m] += 1;
    g[a[i] % m].push_back(i);
  }
  set<int> less;
  for (int i = 0; i < m; i++) {
    if (cnt[i] >= c)
      continue;
    else
      less.insert(i);
  }
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    if (cnt[i] <= c) continue;
    int rem = cnt[i] - c;
    cnt[i] = c;
    for (auto idx : g[i]) {
      rem--;
      auto it = less.lower_bound((i + 1) % m);
      if (it == less.end()) it = less.begin();
      int diff = (*it - i + m) % m;
      a[idx] += diff;
      ans += diff;
      cnt[*it]++;
      if (cnt[*it] == c) less.erase(it);
      if (rem == 0) break;
    }
  }
  cout << ans << endl;
  for (auto x : a) cout << x << " ";
  cout << endl;
  return 0;
}
