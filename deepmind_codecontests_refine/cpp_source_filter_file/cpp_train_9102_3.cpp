#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int prime[maxn];
int on_group[maxn];
vector<pair<int, int> > groups;
int main() {
  int n;
  cin >> n;
  for (int e = 2; e <= n; e++) {
    if (!prime[e])
      for (int f = 2 * e; f <= n; f++) prime[f] = 1;
  }
  for (int e = n; e >= 2; e--) {
    if (!prime[e]) {
      vector<long long> cur;
      for (int f = e; f <= n; f += e)
        if (!on_group[f]) cur.push_back(f);
      if (cur.size() % 2 == 1 && cur.size() > 2) cur.erase(cur.begin() + 1);
      for (int e = 0; e < cur.size(); e += 2) {
        if (e + 1 == cur.size()) continue;
        groups.push_back(make_pair(cur[e], cur[e + 1]));
        on_group[cur[e]] = on_group[cur[e + 1]] = 1;
      }
    }
  }
  cout << groups.size() << endl;
  for (auto &it : groups) cout << it.first << " " << it.second << endl;
  return 0;
}
