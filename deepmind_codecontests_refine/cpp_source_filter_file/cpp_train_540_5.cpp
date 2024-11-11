#include <bits/stdc++.h>
using namespace std;
void test() {
  int n, m, k;
  cin >> n >> m >> k;
  k = min(k, m - 1);
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  vector<int> act;
  for (int i = 0; i < m; i++) {
    act.push_back(max(vec[i], vec[i + n - m]));
  }
  set<pair<int, int> > sett;
  int sim = act.size() - k;
  for (int i = 0; i < sim; i++) {
    sett.insert({vec[i], i});
  }
  int ans = (*sett.begin()).first;
  for (int i = sim; i < act.size(); i++) {
    sett.erase({act[i - sim], i - sim});
    sett.insert({act[i], i});
    ans = max(ans, (*sett.begin()).first);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  int z;
  cin >> z;
  while (z--) {
    test();
  }
}
