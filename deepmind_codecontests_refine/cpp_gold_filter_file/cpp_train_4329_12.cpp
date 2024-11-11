#include <bits/stdc++.h>
using namespace std;
map<int, int> fr[1000010], min_cnt[1000010];
map<int, vector<int>> cnt[1000010];
vector<pair<int, int>> ans[1000010];
map<vector<pair<int, int>>, int> grp;
const long long mod = 1e9 + 7;
long long fact[1000010];
void pre() {
  fact[0] = 1;
  for (long long i = 1; i < 1000010; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
int main() {
  int n, m, x, y;
  pre();
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      for (int j = 0; j < x; ++j) {
        scanf("%d", &y);
        ++fr[i][y];
      }
      for (map<int, int>::iterator it = fr[i].begin(); it != fr[i].end();
           ++it) {
        ans[it->first].push_back(make_pair(i, it->second));
      }
    }
    for (int i = 1; i <= m; ++i) {
      ++grp[ans[i]];
    }
    long long tmp = 1;
    for (map<vector<pair<int, int>>, int>::iterator it = grp.begin();
         it != grp.end(); ++it) {
      tmp *= fact[it->second];
      tmp %= mod;
    }
    cout << tmp << endl;
  }
  return 0;
}
