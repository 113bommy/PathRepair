#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000500;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  set<int> s;
  cin >> n;
  long long s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }
  set<int> av;
  for (int i = 1; i <= 1e6; ++i) {
    int x = i;
    int y = 1e6 - x;
    if (x > y) break;
    if (s.find(x) != s.end() || s.find(y) != s.end()) continue;
    av.insert(x);
  }
  vector<int> res;
  while (!s.empty()) {
    auto x = *s.begin();
    s.erase(x);
    if (s.find(1e6 - x + 1) == s.end()) {
      res.push_back(1e6 - x + 1);
      continue;
    }
    s.erase(1e6 - x + 1);
    res.push_back(*av.begin());
    res.push_back(1e6 - *av.begin() + 1);
    av.erase(av.begin());
    s.erase(1e6 - x + 1);
  }
  cout << (int)res.size() << '\n';
  for (auto x : res) cout << x << ' ';
  cout << '\n';
  return 0;
}
