#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, long long> cst;
vector<long long> smpl_dec(long long u) {
  vector<long long> ans;
  while (u > 0) {
    ans.push_back(u);
    u >>= 1;
  }
  return ans;
}
vector<long long> dec(long long u, long long v) {
  vector<long long> du = smpl_dec(u), dv = smpl_dec(v);
  int lcp = 0;
  for (; lcp < (int)du.size(); ++lcp) {
    vector<long long>::iterator it = find(dv.begin(), dv.end(), du[lcp]);
    if (it != dv.end()) break;
  }
  vector<long long> ans;
  for (int i = 0; i <= lcp; ++i) {
    ans.push_back(du[i]);
  }
  int pos = find(dv.begin(), dv.end(), du[lcp]) - dv.begin();
  --pos;
  for (int i = pos; i >= 0; --i) {
    ans.push_back(dv[i]);
  }
  return ans;
}
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    long long u, v, w;
    int tp;
    cin >> tp >> u >> v;
    vector<long long> path = dec(u, v);
    if (tp == 1) {
      cin >> w;
      for (int j = 0; j + 1 < (int)path.size(); ++j) {
        cst[make_pair(path[j], path[j + 1])] += w;
        cst[make_pair(path[j + 1], path[j])] += w;
      }
    } else {
      long long ans = 0;
      for (int j = 0; j + 1 < (int)path.size(); ++j) {
        ans += cst[make_pair(path[j], path[j + 1])];
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
