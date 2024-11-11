#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
mt19937 mt(736);
void solve(istream &cin = std::cin, ostream &cout = std::cout) {
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (auto &it : arr) cin >> it;
  map<int, set<int>> wh;
  for (int i = 0; i < arr.size(); i++) wh[arr[i]].insert(i);
  while (!wh.empty()) {
    auto it = wh.begin();
    if (it->second.size() < 2)
      wh.erase(it);
    else {
      int l = *it->second.begin();
      it->second.erase(l);
      int r = *it->second.begin();
      it->second.erase(r);
      arr[l] = 0;
      arr[r] <<= 1;
      wh[arr[r]].insert(r);
    }
  }
  vector<long long> ans;
  for (auto it : arr)
    if (it > 0) ans.push_back(it);
  cout << ans.size() << endl;
  for (auto it : ans) cout << it << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
